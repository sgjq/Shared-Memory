#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <errno.h>
#include "rw_sharedmemory.h"
#include "Mes_semaphore.h"


/***
 * @brief 该结构体存储C++向共享内存写入的消息。
 * @para flag:标志位，当C++写完消息后，置1。当Python读取消息后，置0.
 * @para size:C++写入的消息长度，单位byte
 * @para buf:消息的首地址
**/
struct mem_share
{
    int flag;
	int size;
	char buf[0];
};

/***
 * @brief 该结构体存储Python向共享内存写入的结果消息。
 * @para flag:标志位，当Python写完结果信息后，置1。当C++读取结果信息后，置0.
 * @para size:Python写入的消息长度，单位byte
 * @para buf:消息的首地址
**/
struct res_mem_share
{
    int flag;
    int size;
    char buf[0];
};

//申请共享内存获取的id
static int _share_mem_id=-1;

//C++所用的共享内存区域首地址
static struct mem_share *_p_mem_share=NULL;

//Python所用的共享内存区域首地址
static struct res_mem_share *_p_resmem_share=NULL;

//获取的共享内存长度，byte
static int	_mem_size = 0;

//设置的Pyhton共享内存区域相对偏移地址,byte
static int _mem_shift = 0;

//Pyhton共享内存区域长度,byte
static int _res_mem_size = 0;
static int sharememorykey = 0;

/***
 * @brief 初始化共享内存，C++和Python都需要执行这个程序获取共享内存
 * @para[in] key，共享内存键值
 * @para[in] size_，申请共享内存长度，byte
 * @para[in] mem_shift，Pyhton共享内存区域相对偏移地址,byte
 * @para[in] sem_key，信号量键值
 * @return 0:成功。-1:失败
**/
int init_share_mem(int key, int size_, int mem_shift, int sem_key)
{
	int page_size;

	page_size=getpagesize();

    sharememorykey = key;
    _mem_shift = mem_shift;
    _mem_size=((page_size + size_)/page_size + 1) * page_size;

    //printf("_mem_size:%d\n",_mem_size);

	//share_mem_id=shmget(SHARE_MEMORY_KEY,memsize, 0640);
    if(sharememorykey != 0)
        _share_mem_id=shmget(sharememorykey, _mem_size, 0666|IPC_CREAT);//_mem_size=12M+size
    else
        _share_mem_id=shmget(IPC_PRIVATE, _mem_size, 0666|IPC_CREAT);//_mem_size=12M+size

    if(_share_mem_id == -1)
	{
        printf("my error");
		perror("init shmget error:");

		return -1;
	}

	//get mem info
	struct shmid_ds shmds;
    if(shmctl(_share_mem_id, IPC_STAT, &shmds) != 0)
	{
		perror("get mem info error");
	}
	_mem_size=shmds.shm_segsz;
	printf( "Size of memory segment is %d\n",shmds.shm_segsz );
	printf( "Numbre of attaches %d\n",( int )shmds.shm_nattch );

    //第一次申请出共享内存，初始化信号量
    int first_creat_memory = 0;
    if(( int )shmds.shm_nattch == 0)
    {
        first_creat_memory = 1;
        if(init_and_setsemaphore(sem_key) == 0)
        {
            printf("success init and set semaphore!\n");
        }
        else
        {
            printf("error init and set semaphore!\n");
        }
    }
    else
    {
        if(init_semaphore(sem_key) == 0)
        {
            printf("success init semaphore!\n");
        }
        else
        {
            printf("error init and semaphore!\n");
        }
    }

	//get share memory point
	_p_mem_share = (struct mem_share *)shmat(_share_mem_id, NULL, 0);

    //printf("Memory attached at:%d\n ",(long int)_p_mem_share);

	if(_p_mem_share == (void *)-1)
	{
		perror("attach share memory error\n");
		printf("point:%p\n",_p_mem_share);
		return -1;
	}

    _p_resmem_share = (struct res_mem_share*)(_p_mem_share + ((int)_mem_shift/sizeof(struct mem_share)));
    _res_mem_size = _mem_size - _mem_shift;

    //may not need
    if(first_creat_memory && 0)
    {
        _p_mem_share->flag = 0;
        _p_mem_share->size = 0;
        _p_resmem_share->flag = 0;
        _p_resmem_share->size = 0;
    }


	return 0;
}

int initsharemembyId(int memoryId, int size_, int mem_shift, int sem_Id)
{
    int page_size;
    page_size=getpagesize();

    _mem_shift = mem_shift;
    _mem_size=((page_size + size_)/page_size + 1) * page_size;

    _share_mem_id = memoryId;

    if(_share_mem_id == -1)
    {
        printf("my error");
        perror("init shmget error:");

        return -1;
    }

    //get mem info
    struct shmid_ds shmds;
    if(shmctl(_share_mem_id, IPC_STAT, &shmds) != 0)
    {
        perror("get mem info error");
    }
    _mem_size=shmds.shm_segsz;
    printf( "Size of memory segment is %d\n",shmds.shm_segsz );
    printf( "Numbre of attaches %d\n",( int )shmds.shm_nattch );


    if(init_semaphore_byId(sem_Id) == 0)
    {
        printf("success init semaphore!\n");
    }
    else
    {
        printf("error init and semaphore!\n");
    }

    //get share memory point
    _p_mem_share = (struct mem_share *)shmat(_share_mem_id, NULL, 0);

    //printf("Memory attached at:%d\n ",(long int)_p_mem_share);

    if(_p_mem_share == (void *)-1)
    {
        perror("attach share memory error\n");
        printf("point:%p\n",_p_mem_share);
        return -1;
    }

    _p_resmem_share = (struct res_mem_share*)(_p_mem_share + ((int)_mem_shift/sizeof(struct mem_share)));
    _res_mem_size = _mem_size - _mem_shift;

    return 0;
}

int getsharememoryId()
{
    return _share_mem_id;
}

/***
 * @brief C++向共享内存写入数据
 * @para[in] buf，待写入数据首地址
 * @para[in] bufsize，写入数据长度
 * @return 0:成功。-1:失败
**/
int write_share_mem(char *buf, unsigned int bufsize)
{
	if(_mem_size-sizeof(struct mem_share)<bufsize)
	{
		printf("the buf size is too large\n");
		return -1;
	}
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

	_p_mem_share->size = bufsize;
	memcpy(_p_mem_share->buf ,buf, bufsize);
    _p_mem_share->flag = 1;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");

    //printf("write buf size %d success\n",bufsize);
	return 0;
}

/***
 * @brief Python从共享内存中获取C++写入的数据长度
 * @return 0:成功。-1:失败
**/
int getdatasize()
{
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    int tmp = _p_mem_share->size;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");

    return tmp;

}

/***
 * @brief Python从共享内存中获取C++写入的数据
 * @para[in] buf，读出数据到内存的首地址
 * @return 0:成功。-1:失败
**/
int read_share_mem(char *buf)
{
    int tmpsize = 0;
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

	memcpy(buf, _p_mem_share->buf, _p_mem_share->size);
    tmpsize = _p_mem_share->size;
    _p_mem_share->flag = 0;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");
    //printf("read buf size:%d\n", tmpsize);
	return 0;
}

/***
 * @brief Python判断C++是否向共享内存写入新的消息
 * @return 0:没有新的消息。1:有新的消息
**/
int isNewMessage()
{
    int tmp_flag = -1;
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    tmp_flag = _p_mem_share->flag;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");
    return tmp_flag;
}

/***
 * @brief 将进程和共享内存分离开
 * @return 0:成功。-1:出错
**/
int detach_share_mem()
{
    if(shmdt(_p_mem_share) == -1)
	{
		perror("detach share memory error");
		return -1;
	}
	return 0;
}

/***
 * @brief 删除共享内存和信号量
 * @return 0:成功。-1:出错
**/
int delete_share_mem()
{
//    int shmid=shmget(sharememorykey, 0, IPC_CREAT);
//    if(shmid == -1)
//	{
//		perror("get shm id error");
//		return -1;
//	}

    struct shmid_ds shmds;
    if(shmctl(_share_mem_id, IPC_STAT, &shmds) != 0)
    {
        perror("get mem info error");
    }
    if(( int )shmds.shm_nattch == 0)
    {
        if(delete_semaphore() == 0)
            printf("delete semaphore success!\n");
        else
            printf("delete semaphore error!\n");
    }

    if(shmctl(_share_mem_id, IPC_RMID, 0)<0)
	{
		perror("rm share memory error:");
		return -1;
	}
	return 0;
}

/***
 * @brief Python向共享内存写入数据
 * @para[in] buf，待写入数据首地址
 * @para[in] bufsize，写入数据长度
 * @return 0:成功。-1:失败
**/
int write_res_tomemory(char *buf,unsigned int bufsize)
{
    if(_res_mem_size-sizeof(struct res_mem_share)<bufsize)
    {
        printf("the buf size is too large\n");
        return -1;
    }

    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    _p_resmem_share->size = bufsize;
    memcpy(_p_resmem_share->buf ,buf, bufsize);

    //for check result
    _p_resmem_share->flag = 1;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");

    //printf("write result buf size %d success\n",bufsize);
    return 0;
}

/***
 * @brief C++从共享内存中获取python写入的数据长度
 * @return 0:成功。-1:失败
**/
int getresultdatasize()
{
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    int tmp = _p_resmem_share->size;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");
    return tmp;
}

/***
 * @brief C++判断Python是否向共享内存写入新的消息
 * @return 0:没有新的消息。1:有新的消息
**/
int isNewResult()
{
    int tmp_flag = -1;
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    tmp_flag = _p_resmem_share->flag;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");
    return tmp_flag;
}

/***
 * @brief C++从共享内存中获取python写入的数据
 * @para[in] buf，读出数据到内存的首地址
 * @return 0:成功。-1:失败
**/
int read_res_frommemory(char *buf)
{
    int tmpsize = 0;
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    memcpy(buf, _p_resmem_share->buf, _p_resmem_share->size);

    tmpsize = _p_resmem_share->size;
    _p_resmem_share->flag = 0;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");

    //printf("read result buf size:%d\n", tmpsize);
    return 0;
}

