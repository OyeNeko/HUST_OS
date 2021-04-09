#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>
#include<string.h>

int pipefd[2];
int pid1=0;
int pid2=0;
void signpass(int sign);
void clean(int sign);
void writepipe(int writehandle);
void readpipe(int proc,int readhandle);

int main()
{
    printf("Process on...\n");
    assert (pipe(pipefd)>=0);
    signal(SIGINT,signpass);
	
    assert ((pid1=fork())>=0);
    if(pid1==0)
    {
        signal(SIGINT,SIG_IGN);
        signal(SIGUSR1,clean);
        readpipe(1,pipefd[0]);
    }
    else
    {
        assert((pid2=fork())>=0);
        if (pid2==0)
        {
            signal(SIGINT,SIG_IGN);
            signal(SIGUSR2,clean);
           
			readpipe(2,pipefd[0]);
        }
		else
		{
			
			writepipe(pipefd[1]);
		}
    }
    return 0;
}

void signpass(int sign)
{
    kill(pid1,SIGUSR1);
    kill(pid2,SIGUSR2);
	waitpid(pid1,NULL,0);
    printf("Child Process 1 is Killed by Parent!\n");
    waitpid(pid2,NULL,0);
    printf("Child Process 2 is Killed by Parent!\n");
	close(pipefd[0]);
	close(pipefd[1]);
	printf("Parent Process is Killed!\n");
	exit(0);
}
void clean(int sign)
{
    close(pipefd[0]);
    close(pipefd[1]);
    if(pid1==0)exit(0);
    if(pid2==0)exit(0);
}

void writepipe(int writehandle)
{
	int count =0;
    char buf[30];
    while(1)
    {
        sprintf(buf,"I send you %d times.\n",count);
        printf("write: %s\n",buf);
        buf[strlen(buf)] = '\0';
        write(writehandle,buf,strlen(buf));
	count++;
        sleep(1);
		if(count>10)signpass(0);
    }
	close(writehandle);
    exit(0);
}
void readpipe(int proc,int readhandle)
{
    char buf[50];
	memset(buf,0,sizeof(buf));
    int n=0;
    while(1)
    {
        n=read(readhandle,buf,sizeof(buf));
        buf[n]='\0';
        printf("%d read: %s\n",proc,buf);
        sleep(1);
    }
	close(readhandle);
exit(0);
}

