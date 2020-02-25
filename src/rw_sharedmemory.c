#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <errno.h>
#include "rw_sharedmemory.h"
#include "Mes_semaphore.h"

//flag==1,new message,set flag=0 after read message
struct mem_share
{
    int flag;
	int size;
	char buf[0];
};

struct res_mem_share
{
    int flag;
    int size;
    char buf[0];
};

static int _share_mem_id=-1;
static struct mem_share *_p_mem_share=NULL;
static struct res_mem_share *_p_resmem_share=NULL;

static int	_mem_size = 0;
static int _mem_shift = 0;
static int _res_mem_size = 0;
static int sharememorykey = 0;

int init_share_mem(int key, int size_, int mem_shift, int sem_key)
{
	int page_size;

	page_size=getpagesize();

    sharememorykey = key;
    _mem_shift = mem_shift;
    _mem_size=((page_size + size_)/page_size + 1) * page_size;

    //printf("_mem_size:%d\n",_mem_size);

	//share_mem_id=shmget(SHARE_MEMORY_KEY,memsize, 0640);
    _share_mem_id=shmget(sharememorykey, _mem_size, 0666|IPC_CREAT);//_mem_size=12M+size
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


int write_share_mem(char *buf,unsigned int bufsize)
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


int getdatasize()
{
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    int tmp = _p_mem_share->size;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");

    return tmp;

}

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

//-1 error(default), 0:not  1:new messaage
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


int detach_share_mem()
{
    if(shmdt(_p_mem_share) == -1)
	{
		perror("detach share memory error");
		return -1;
	}
	return 0;
}


int delete_share_mem()
{
    int shmid=shmget(sharememorykey, 0, IPC_CREAT);
    if(shmid == -1)
	{
		perror("get shm id error");
		return -1;
	}

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


	if(shmctl(shmid, IPC_RMID, 0)<0)
	{
		perror("rm share memory error:");
		return -1;
	}
	return 0;
}

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

int getresultdatasize()
{
    if(semaphore_p() == -1)
        printf("semaphore_p error!\n");

    int tmp = _p_resmem_share->size;

    if(semaphore_v() == -1)
        printf("semaphore_v error!\n");
    return tmp;
}

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

