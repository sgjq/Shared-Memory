#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/sem.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>

#include "Mes_semaphore.h"

//#include <linux/sem.h>中的结构体，和sys/sem.h冲突
union semun {
    int val;			/* value for SETVAL */
    struct semid_ds *buf;	/* buffer for IPC_STAT & IPC_SET */
    unsigned short *array;	/* array for GETALL & SETALL */
    struct seminfo *__buf;	/* buffer for IPC_INFO */
    void *__pad;
};

//信号量的id
static int sem_id = 0;

//信号量键值
static int semaphore_key = 0;

/***
 * @brief 初始化信号量
 * @para[in] sem_key，信号量键值
 * @return 0:成功。-1:失败
**/
int init_semaphore(int sem_key)
{
    semaphore_key = sem_key;
    sem_id = semget(semaphore_key, 1, 0666|IPC_CREAT);
    if(sem_id == -1)
    {
        printf("init semaphore error!\n");
        return -1;
    }
    return 0;
}

int init_semaphore_byId(int semId)
{
    sem_id = semId;
    if(sem_id == -1)
    {
        printf("init semaphore error!\n");
        return -1;
    }
    return 0;
}

/***
 * @brief 设置信号量初始值为1
 * @return 0:成功。-1:失败
**/
int set_semvalue()
{
    union semun sem_union;
    sem_union.val = 1;
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
        return -1;
    return 0;
}

/***
 * @brief 初始化信号量，并设置初始值
 * @para[in] sem_key，信号量键值
 * @return 0:成功。-1:失败
**/
int init_and_setsemaphore(int sem_key)
{
    semaphore_key = sem_key;
    if(semaphore_key != 0)
        sem_id = semget(semaphore_key, 1, 0666|IPC_CREAT);
    else
        sem_id = semget(IPC_PRIVATE, 1, 0666|IPC_CREAT);
    if(sem_id == -1)
    {
        printf("init semaphore error!\n");
        return -1;
    }
    if(set_semvalue() == -1)
        return -1;
    return 0;
}

int getsemaphoreId()
{
    return sem_id;
}

/***
 * @brief 信号量-1操作
 * @return 0:成功。-1:失败
**/
int semaphore_p()
{
    struct sembuf sem_p;
    sem_p.sem_num = 0;
    sem_p.sem_op = -1;
    sem_p.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_p, 1) == -1)
        return -1;
    return 0;
}

/***
 * @brief 信号量+1操作
 * @return 0:成功。-1:失败
**/
int semaphore_v()
{
    struct sembuf sem_p;
    sem_p.sem_num = 0;
    sem_p.sem_op = 1;
    sem_p.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_p, 1) == -1)
        return -1;
    return 0;
}

/***
 * @brief 删除信号量
 * @return 0:成功。-1:失败
**/
int delete_semaphore()
{
    union semun sem_union;
    if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
        return -1;
    return 0;
}


