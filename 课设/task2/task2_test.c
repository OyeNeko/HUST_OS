#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/syscall.h>
int main(int argc,char *argv[]){
	long a=syscall(335,argv[1],argv[2]);
        printf("System call OS_copy return %ld\n",a);
        return 0;
}
