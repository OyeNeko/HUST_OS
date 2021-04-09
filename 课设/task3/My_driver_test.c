#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
  int dev;
  char buf[32];
  dev = open("/dev/Mydriver", O_RDWR);
  if (dev == -1)
  {
    printf("Open file failed!\n");
    exit(0);
  }
  printf("Input your message:");
  scanf("%s", buf);
  write(dev, buf, sizeof(buf));

  //
  read(dev, buf, sizeof(buf));
  printf("Message:%s\n", buf);
  close(dev);
  return 0;
}
