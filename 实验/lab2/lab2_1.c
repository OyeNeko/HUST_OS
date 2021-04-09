#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <linux/sem.h>
#define SUBP_NUM 5
#define TICKET_NUM 1000

void P(int semid,int index);
void V(int semid,int index);
int semid;
void *subp();

int T_n=0;//售票数
int count[SUBP_NUM];
int i=0;
int j=0;
union semun arg;

int main()
{
	i=0;
	while(i<SUBP_NUM)
	{
		count[i]=0;
		i++;
	}
	
	semid=semget(IPC_PRIVATE,2,IPC_CREAT|0666);
	if(semid==-1)return 0;
	
	arg.val=1;//售票信号灯为0号
	if(semctl(semid,0,SETVAL,arg)<0)
	{
		printf("Semid create error!\n");
		semctl(semid,0,IPC_RMID,arg);
		return -1;
	}
	
	arg.val=0;//初始化售票信号灯为1号
	if(semctl(semid,1,SETVAL,arg)<0)
	{
		printf("Semid create error!\n");
		semctl(semid,1,IPC_RMID,arg);
		return -1;
	}
	//线程组
	pthread_t SUBP_N[SUBP_NUM];
	j=0;
	while(j<SUBP_NUM)
	{
		if(pthread_create(&SUBP_N[j],NULL,subp,NULL)!=0)
		{
			printf("Pthread create error!\n");
			return 0;
		}
		P(semid,1);
		j++;
	}
	
	i=0;
	while(i<SUBP_NUM)
	{
		pthread_join(SUBP_N[i],NULL);
		i++;
	}
	semctl(semid,0,IPC_RMID,arg);
	semctl(semid,1,IPC_RMID,arg);
	return 0;
}
void *subp()
{
	int num =j;
	V(semid,1);
	while(1)
	{
		P(semid,0);
		if(T_n<TICKET_NUM)
		{
			count[num]++;
			T_n++;
			printf("subp %d sold the %d ticket.\n",num,T_n);
		}
		V(semid,0);
	}
	printf("subp %d sold %d in total.\n",num,count[num]);
}
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

