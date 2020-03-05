#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <fcntl.h>
#include <unistd.h>

#include "sensor_image.pb.h"
#include "res_message.pb.h"
#include "mem_config.pb.h"

extern "C"{
#include "rw_sharedmemory.h"
#include "Mes_semaphore.h"
}

using namespace std;

int write_memory_test();
void read_res_test();
void test_ReadAndWrite();
int test_new_write_read();
/***
 *@brief 这是C++程序发送将要由Python处理的图片等数据，由.proto文件定义数据结构
 *@para[in] object,.proto生成的对象
 *@return 0:成功。-1:失败
**/
template<typename T>
int WriteMessageToMemory(T &object)
{
    string out;
    object.SerializeToString(&out);
    unsigned int str_size = out.length();
    char* p = (char*)(out.data());
    //cout<<"out size:"<<str_size<<endl;
    int wflag = write_share_mem(p, str_size);
    return wflag;
}

/***
 *@brief 这是C++程序读取由Python程序返回的结果，由.proto文件定义数据结构
 *@para[out] object,.proto生成的对象,读取的结果存在object内
 *@return 0:成功。-1:失败
**/
template<typename T>
int ReadResultFromMemory(T &object)
{
    int res_size = getresultdatasize();
    cout<<"res_size:"<<res_size<<endl;

    string str('0', res_size);
    char* res = (char*)(str.data());

    if(read_res_frommemory(res) != 0)
        return -1;

    object.ParseFromString(str);
    return 0;
}

//config是.proto文件定义的共享内存配置参数
MyMessage::MemoryConfig config;

//memkey:共享内存的键值
//memsize:申请共享内存大小，单位byte
//memshift:共享内存中后部分用于存储Python返回的结果，memshift是相对于共享内存头部偏移的地址，memshift<memsize
//semkey:信号量的键值
int memkey, memsize, memshift, semkey;

int main()
{
    cout<<"Hello World!"<<endl;

    string config_path = "../Config/mem_config.proto";
    int file_descriptor = open(config_path.c_str(),O_RDONLY);

    config.ParseFromFileDescriptor(file_descriptor);

    memkey = config.memorykey();
    memsize = config.memorysize();
    memshift = config.resshift();
    semkey = config.semaporekey();
    //read_res_test();
    //test_ReadAndWrite();
    test_new_write_read();
    return 0;
}

/*@brief C++向共享内存写数据，Python读数据的Demo,只读写一次
**/
int write_memory_test()
{
    cv::Mat color=cv::imread("../1.png");//BGR
    cv::imshow("image", color);
    //定义待发送的消息
    MyMessage::Image img;
    img.set_frame_id("camera_frame");
    img.set_format(MyMessage::Image::BGR8);
    img.set_height(color.rows);
    img.set_width(color.cols);
    img.set_measurement_time(11.2);
    img.set_step(color.step[0]);
    int size = color.step[0]*color.rows;
    img.set_data(color.data, size);

    //初始化共享内存
    if(init_share_mem(memkey, memsize, memshift, semkey) != 0)
    {
        cout<<"init share mem error"<<endl;
        return -1;
    }

    //将消息写入共享内存
    int wflag = WriteMessageToMemory(img);
    if(wflag == 0)
        cout<<"Write success!"<<endl;

    //等待python读取
    while(1)
    {
        int key = cv::waitKey(1);
        if(key == 'a')//A
            break;
    }

    //将进程和共享内存分离开
    int flag = detach_share_mem();
    if(flag == 0)
        cout<<"detach_share_mem success!"<<endl;

    //删除共享内存
    int flag2 = delete_share_mem();
    if(flag2 == 0)
        cout<<"delete_share_mem success!"<<endl;
    //cv::waitKey();
}


/*@brief Python向共享内存写数据，C++读数据的Demo,只读写一次
**/
void read_res_test()
{
    //定义将要读取的数据格式对象
    MyMessage::DetectRes detectres;

    //获取共享内存
    if(init_share_mem(memkey, memsize, memshift, semkey) != 0)
    {
        cout<<"init share mem error"<<endl;
    }

    //从共享内存读取python返回的结果
    if(ReadResultFromMemory(detectres) == -1)
        cout<<"read error!"<<endl;

    cout<<"detectres frameid:"<<detectres.frame_id()<<endl;
    cout<<"detectres measurement_time:"<<detectres.measurement_time()<<endl;
    cout<<"detectres left_topx:"<<detectres.left_topx()<<endl;
    cout<<"detectres left_topy:"<<detectres.left_topy()<<endl;
    cout<<"detectres right_bottomx:"<<detectres.right_bottomx()<<endl;
    cout<<"detectres right_bottomy:"<<detectres.right_bottomy()<<endl;
    cout<<"detectres score:"<<detectres.score()<<endl;
}

/*@brief C++向共享内存写数据，python读数据，Python再将处理数据写入共享内存，
 * C++从共享内存读取返回结果的Demo,循环读写
**/
void test_ReadAndWrite()
{
    double curtime = -0.1;
    cv::Mat color=cv::imread("../1.png");//BGR
    cv::imshow("image", color);
    MyMessage::Image img;
    img.set_frame_id("camera_frame");
    img.set_format(MyMessage::Image::BGR8);
    img.set_height(color.rows);
    img.set_width(color.cols);
    img.set_measurement_time(curtime);
    img.set_step(color.step[0]);
    int size = color.step[0]*color.rows;
    img.set_data(color.data, size);

    if(init_share_mem(memkey, memsize, memshift, semkey) != 0)
    {
        cout<<"init share mem error"<<endl;
    }

    MyMessage::DetectRes detectres;
    while(1)
    {
        curtime += 0.1;
        img.set_measurement_time(curtime);

        //向共享内存写入消息
        if(WriteMessageToMemory(img) == -1)
        {
            cout<<"write error!"<<endl;
            break;
        }

        //写完后，等待Python处理完成，返回新的处理结果
        while(1)
        {
            //判断有新的处理结果
            if(isNewResult())
                break;
            int key = cv::waitKey(1);
            if(key == 'a')//A
                goto code1;
        }

        //从共享内存读取新的处理结果
        if(ReadResultFromMemory(detectres) == -1)
        {
            cout<<"read error!"<<endl;
        }
        cout<<"measurement time:"<<detectres.measurement_time()<<endl;
        //cout<<"detect score:"<<detectres.score()<<endl;

        //随机等待时间，模拟程序后续处理
        std::this_thread::sleep_for(std::chrono:: milliseconds (rand()%100+1));
        int key = cv::waitKey(1);
        if(key == 'a')//A
            break;
    }
code1:

    //将进程和共享内存分离开
    if(detach_share_mem() == 0)
        cout<<"detach_share_mem success!"<<endl;

    //删除共享内存
    if(delete_share_mem() == 0)
        cout<<"delete_share_mem success!"<<endl;
}

/*@brief C++向共享内存写数据，python读数据，Python再将处理数据写入共享内存，
 * C++从共享内存读取返回结果的Demo,循环读写。
 * 与上一个程序不同之处是：共享内存的键值和信号量键值由系统自动生成，不是配置文件指定的。
**/
int test_new_write_read()
{
    double curtime = -0.1;
    cv::Mat color=cv::imread("../1.png");//BGR
    cv::imshow("image", color);
    MyMessage::Image img;
    img.set_frame_id("camera_frame");
    img.set_format(MyMessage::Image::BGR8);
    img.set_height(color.rows);
    img.set_width(color.cols);
    img.set_measurement_time(curtime);
    img.set_step(color.step[0]);
    int size = color.step[0]*color.rows;
    img.set_data(color.data, size);
    if(init_share_mem(0, memsize, memshift, 0) != 0)
    {
        cout<<"init share mem error"<<endl;
        return -1;
    }
    int memid = getsharememoryId();
    int semid = getsemaphoreId();
    cout<<"memid:"<<memid<<endl;
    cout<<"semid:"<<semid<<endl;

    config.set_memoryid(memid);
    config.set_semaporeid(semid);

    string dir = "../Config/ab.bin";
    fstream fout(dir, ios::out|ios::trunc|ios::binary);
    config.SerializeToOstream(&fout);
    fout.close();
    MyMessage::DetectRes detectres;
    while(1)
    {
        curtime += 0.1;
        img.set_measurement_time(curtime);

        //向共享内存写入消息
        if(WriteMessageToMemory(img) == -1)
        {
            cout<<"write error!"<<endl;
            break;
        }

        //写完后，等待Python处理完成，返回新的处理结果
        while(1)
        {
            //判断有新的处理结果
            if(isNewResult())
                break;
            int key = cv::waitKey(1);
            if(key == 'a')//A
                goto code1;
        }

        //从共享内存读取新的处理结果
        if(ReadResultFromMemory(detectres) == -1)
        {
            cout<<"read error!"<<endl;
        }
        cout<<"measurement time:"<<detectres.measurement_time()<<endl;
        //cout<<"detect score:"<<detectres.score()<<endl;

        //随机等待时间，模拟程序后续处理
        std::this_thread::sleep_for(std::chrono:: milliseconds (rand()%100+1));
        int key = cv::waitKey(1);
        if(key == 'a')//A
            break;
    }
code1:
    //将进程和共享内存分离开
    if(detach_share_mem() == 0)
        cout<<"detach_share_mem success!"<<endl;

    //删除共享内存
    if(delete_share_mem() == 0)
        cout<<"delete_share_mem success!"<<endl;
}
