#include "lab3.h"



int main()
{
	//绑定内存


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
	
	//挂载写信号灯
	key_t key_write=2;
	semid_write=semget(key_write,1,IPC_CREAT|0666);
    if(semid_write==-1){
        printf("create error\n");
        return 0;
    }
	//挂载读信号灯
	key_t key_read=3;
	semid_read=semget(key_read,1,IPC_CREAT|0666);
	if(semid_read==-1){
        printf("create error\n");
        return 0;
    }
	
	//写文件
	FILE *fp =fopen("b.txt","wb");
	if(fp==NULL)
	{
		printf("Open file failed.\n");
		return -1;
	}
	int i=0;
	node tmp;
	while(1)
	{
		
		P(semid_write,0);
		printf("write\n");
		tmp=Head[i];
		
		fwrite(tmp.data,tmp.len,1,fp);
		if(tmp.last)
		{
			printf("write finished!\n");
			fclose(fp);
			break;
		}
		i++;
		i=i%LIST_LEN;
		
		V(semid_read,0);
	}
	
	return 0;
}