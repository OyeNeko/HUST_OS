#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <linux/sem.h>

int i=0,sum=0;
int semid;
pthread_t p1,p2,p3;
union semun arg;
void P(int semid, int index);
void V(int semid, int index);

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

/*线程一*/      
void *subp_1(){  
    while(i<=100)
	{ 
		P(semid,0);   
		printf("This is a subp_1 i=%d\n",i); 
		sum+=i;
		if(i%2)V(semid,1); //奇数
		else V(semid,2);//偶数
		i++;
	}
	V(semid,1);
	V(semid,2);
	return;  
}  

/*线程二*/  
void *subp_2(){    
    while(1)
	{
		P(semid,1);
		if(i==101)return;
		printf("This is a subp_2 ood_sum=%d\n",sum); 	
		V(semid,0);
    }
	return;
}  

void *subp_3(){
    while(1)
	{	
		P(semid,2);
		printf("This is a subp_3 even_sum=%d\n",sum); 
		if(i==101)return;
		V(semid,0);
    }
	return;
}
int main()
{
    semid=semget(IPC_PRIVATE,3,IPC_CREAT|0666);
    if(semid==-1){
        printf("create error\n");
        return 0;
    }
    
	arg.val=1;//计算
    if (semctl(semid,0,SETVAL,arg) < 0 ){
        printf("ctl sem error");
        semctl(semid,0,IPC_RMID,arg);
        return -1 ;
    }
	arg.val=0;//打印奇数
    if (semctl(semid,1,SETVAL,arg) < 0 ){
        printf("ctl sem error");
        semctl(semid,1,IPC_RMID,arg);
        return -1 ;
    }
    
	arg.val=0;//打印偶数
    if (semctl(semid,2,SETVAL,arg) < 0 ){
        printf("ctl sem error");
        semctl(semid,2,IPC_RMID,arg);
        return -1 ;
    }
	
	
    if(pthread_create(&p1,NULL,&subp_1,NULL)!=0){  
        printf("Create pthread error!\n");  
        return -1;  
    }  
    
     
    if(pthread_create(&p2,NULL,&subp_2,NULL)!=0)  {  
        printf("Create pthread error!\n");  
        return -1;  
    } 
	
    if(pthread_create(&p3,NULL,&subp_3,NULL)!=0)  {  
        printf("Create pthread error!\n");  
        return -1;  
    } 

//WAIT....
    pthread_join(p1,NULL);  
    pthread_join(p2,NULL);  
//Del sign
    semctl(semid,0,IPC_RMID,arg);
    semctl(semid,1,IPC_RMID,arg);
    return 0;  
}