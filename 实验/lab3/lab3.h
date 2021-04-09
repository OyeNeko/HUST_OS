#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#define ADDR "./lab3"

#define BUF_LEN 16
#define LIST_LEN 8

typedef struct node
{
	int len;
	char data[BUF_LEN];
	int last;
}node;


 union semun {
   	int val; /* 当 cmd 为 SETVAL 时使用 */
	struct semid_ds *buf; /* 当 cmd 为 IPC_STAT 或 IPC_SET 时使用 */
	unsigned short *array; /* 当 cmd 为 GETALL 或 SETALL 时使用 */
	struct seminfo *__buf; /* 当 cmd 为 IPC_INFO 时使用 */
};

union semun arg;

void P(int semid,int index)
{
	struct sembuf sem;	
    sem.sem_num = index;
    sem.sem_op = -1;	
    sem.sem_flg = 0; //操作标记：0或IPC_NOWAIT等
    semop(semid,&sem,1);	//1:表示执行命令的个数	
    return;
}

void V(int semid,int index)
{	
	struct sembuf sem;	
    sem.sem_num = index;
    sem.sem_op =  1;
    sem.sem_flg = 0;	
	semop(semid,&sem,1);	
    return;
}