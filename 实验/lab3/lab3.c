#include "lab3.h"

int main()
{
	int semid_write,semid_read;
	int shmid_node;
	node* Head;

	//创建链表内存
	key_t key_node=1;
	shmid_node=shmget(key_node,LIST_LEN*sizeof(node),IPC_CREAT|0666);
	if(shmid_node==-1){
		printf("create error\n");
		return 0;
		}
	Head=(node *)shmat(shmid_node,NULL,SHM_R|SHM_W);
	
	//创建写信号灯
	key_t key_write=2;
	semid_write=semget(key_write,1,IPC_CREAT|0666);
    if(semid_write==-1){
        printf("create error\n");
        return 0;
    }
	arg.val=0;//写信号灯，初值为0
    if (semctl(semid_write,0,SETVAL,arg) < 0 ){
        printf("ctl sem error");
        semctl(semid_write,0,IPC_RMID,arg);
        return -1 ;
    }
	//创建读信号灯
	key_t key_read=3;
	semid_read=semget(key_read,1,IPC_CREAT|0666);
	if(semid_read==-1){
        printf("create error\n");
        return 0;
    }
	arg.val=LIST_LEN;//读信号灯，初值为链表大小
    if (semctl(semid_read,0,SETVAL,arg) < 0 ){
        printf("ctl sem error\n");
        semctl(semid_read,0,IPC_RMID,arg);
        return -1 ;
    }
    
	//创建两个进程readbuf、writebuf;

	pid_t  p_write,p_read;
	if ((p_read=fork()) == 0) {
		puts("read_process\n");			     	    
		execv("./lab3_read.out",NULL);	
	} 
    if ((p_write=fork()) == 0) {
		puts("write_process\n");			     	    
		execv("./lab3_write.out",NULL);	
	} 



	//等待两个进程运行结束；
	waitpid(p_read,NULL,0);
	waitpid(p_write,NULL,0);
	
	//删除信号灯；
    semctl(semid_read,0,IPC_RMID,arg);
    semctl(semid_write,0,IPC_RMID,arg);
    shmctl(shmid_node,0,IPC_RMID);
	//
    return 0;  
}