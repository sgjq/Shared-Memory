#ifndef _RW_SHARE_MEM_H_
#define _RW_SHARE_MEM_H_
#define SHARE_MEMORY_KEY 123456

//12M
#define SHAREDMEMORYSIZE 12582912

//10M
#define MEMORYSHIFT 10485760

enum share_mem_type
{
	E_SM_READ=1,
	E_SM_WRITE,
};
//return 0 : success   <0 error
extern int init_share_mem(int key, int size_, int mem_shift, int sem_key);
extern int initsharemembyId(int memoryId, int size_, int mem_shift, int sem_Id);
extern int getsharememoryId();
extern int write_share_mem(char *buf,unsigned int bufsize);
extern int read_share_mem(char *buf);
extern int isNewMessage();
extern int detach_share_mem();
extern int delete_share_mem();
extern int getdatasize();

extern int write_res_tomemory(char *buf,unsigned int bufsize);
extern int getresultdatasize();
extern int read_res_frommemory(char *buf);
extern int isNewResult();
#endif //end of _RW_SHARE_MEM_H_ 

