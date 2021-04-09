#include "linux/kernel.h"
#include "linux/module.h"
#include "linux/fs.h"
#include "linux/init.h"
#include "linux/types.h"
#include "linux/errno.h"
#include "linux/uaccess.h"
#include "linux/kdev_t.h"

int my_open(struct inode *inode, struct file *file);
int my_release(struct inode *inode, struct file *file);
ssize_t my_read(struct file *file, char __user *user, size_t t, loff_t *f);
ssize_t my_write(struct file *file, const char __user *user, size_t t, loff_t *f);

int dev_id; //设备号
char *dev_name = "Mydriver";

char message[32] = "My driver start!\n";

struct file_operations fops = {
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write};

MODULE_LICENSE("GPL"); //模块许可证

int init_module_func(void) //注册模块
{
  int ans;
  printk("start initial module\n");

  ans = register_chrdev(0, dev_name, &fops);
  if (ans < 0)
  {
    printk("Register unsuccessfully.\n");
    return -1;
  }
  else
  {
    printk("Register successfully.\n");
    printk("id: %d\n", ans);

    dev_id = ans;
    return 0;
  }
  return 0;
}

void cleanup_module_func(void) //退出模块
{
  unregister_chrdev(dev_id, dev_name);
  printk("Unregister successfully.\n");
}

int my_open(struct inode *inode, struct file *file)
{
  try_module_get(THIS_MODULE);

  return 0;
}

int my_release(struct inode *inode, struct file *file)
{
  module_put(THIS_MODULE);

  return 0;
}

ssize_t my_read(struct file *file, char __user *user, size_t t, loff_t *f)
{
  int ret = copy_to_user(user, message, sizeof(message)); //成功返回0，失败返回没有拷贝的字节数
  if (ret)
    return -1;
  return sizeof(message);
}

ssize_t my_write(struct file *file, const char __user *user, size_t t, loff_t *f)
{
  int ret = copy_from_user(message, user, sizeof(message)); //成功返回0，失败返回没有拷贝的字节数
  if (ret)
    return -1;
  return sizeof(message);
}
module_init(init_module_func);
module_exit(cleanup_module_func);
