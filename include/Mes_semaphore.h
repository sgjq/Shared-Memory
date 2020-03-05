#ifndef MES_SEMAPHORE_H
#define MES_SEMAPHORE_H

#define SEMAPORE_KEY 1234

extern int init_semaphore(int sem_key);
extern int init_semaphore_byId(int semId);
extern int getsemaphoreId();
extern int set_semvalue();
extern int init_and_setsemaphore(int sem_key);
extern int semaphore_p();
extern int semaphore_v();
extern int delete_semaphore();

#endif
