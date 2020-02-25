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
}

using namespace std;

int write_memory_test();
void read_res_test();
void test_ReadAndWrite();

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

MyMessage::MemoryConfig config;
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
    test_ReadAndWrite();
    return 0;
}


int write_memory_test()
{
    cv::Mat color=cv::imread("../1.png");//BGR
    cv::imshow("image", color);
    MyMessage::Image img;
    img.set_frame_id("camera_frame");
    img.set_format(MyMessage::Image::BGR8);
    img.set_height(color.rows);
    img.set_width(color.cols);
    img.set_measurement_time(11.2);
    img.set_step(color.step[0]);
    int size = color.step[0]*color.rows;
    img.set_data(color.data, size);

    if(init_share_mem(memkey, memsize, memshift, semkey) != 0)
    {
        cout<<"init share mem error"<<endl;
        return -1;
    }

    int wflag = WriteMessageToMemory(img);
    if(wflag == 0)
        cout<<"Write success!"<<endl;
    while(1)
    {
        int key = cv::waitKey(1);
        if(key == 'a')//A
            break;
    }
    int flag = detach_share_mem();
    if(flag == 0)
        cout<<"detach_share_mem success!"<<endl;
    int flag2 = delete_share_mem();
    if(flag2 == 0)
        cout<<"delete_share_mem success!"<<endl;
    //cv::waitKey();
}



void read_res_test()
{
    MyMessage::DetectRes detectres;
    if(init_share_mem(memkey, memsize, memshift, semkey) != 0)
    {
        cout<<"init share mem error"<<endl;
    }

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
        if(WriteMessageToMemory(img) == -1)
        {
            cout<<"write error!"<<endl;
            break;
        }
        while(1)
        {
            if(isNewResult())
                break;
            int key = cv::waitKey(1);
            if(key == 'a')//A
                goto code1;
        }
        if(ReadResultFromMemory(detectres) == -1)
        {
            cout<<"read error!"<<endl;
        }
        cout<<"measurement time:"<<detectres.measurement_time()<<endl;
        //cout<<"detect score:"<<detectres.score()<<endl;
        std::this_thread::sleep_for(std::chrono:: milliseconds (rand()%100+1));
        int key = cv::waitKey(1);
        if(key == 'a')//A
            break;
    }
code1:
    if(detach_share_mem() == 0)
        cout<<"detach_share_mem success!"<<endl;

    if(delete_share_mem() == 0)
        cout<<"delete_share_mem success!"<<endl;
}
