#include "main.h"

int main()
{
  //绑定共享区

  int semid_write, semid_read;
  int shmid_node;
  struct node *Head;

  //创建链表内存
  key_t key_node = 1;
  shmid_node = shmget(key_node, LIST_LEN * sizeof(node), IPC_CREAT | 0666);
  if (shmid_node == -1)
  {
    printf("create error\n");
    return 0;
  }
  Head = (node *)shmat(shmid_node, NULL, SHM_R | SHM_W);

  //挂载写信号灯
  key_t key_write = 2;
  semid_write = semget(key_write, 1, IPC_CREAT | 0666);
  if (semid_write == -1)
  {
    printf("create error\n");
    return 0;
  }
  //挂载读信号灯
  key_t key_read = 3;
  semid_read = semget(key_read, 1, IPC_CREAT | 0666);
  if (semid_read == -1)
  {
    printf("create error\n");
    return 0;
  }

  //打开文件
  int fp = open("source.txt", O_RDONLY);
  if (fp == -1)
  {
    printf("Open file failed!\n");
    return -1;
  }
  int i = 0;
  while (1)
  {

    P(semid_read, 0);
    printf("read\n");
    node tmp;
    tmp.len = read(fp, tmp.data, sizeof(char) * BUF_LEN);
    tmp.last = 0;

    if (tmp.len < BUF_LEN)
    {
      tmp.last = 1;
      Head[i] = tmp;
      V(semid_write, 0);
      close(fp);
      break;
    }

    Head[i] = tmp;
    i++;
    i %= LIST_LEN;
    V(semid_write, 0);
  }
  printf("read finished.\n");

  return 0;
}