SYSCALL_DEFINE2(OS_copy,const char __user*,source,const char __user*,target){
	long ret = 0;
	char buffer[1000];
	// 转化为内核存储空间
	char * source_kd = strndup_user(source, PAGE_SIZE);
	char * target_kd = strndup_user(target, PAGE_SIZE);
	// 异常处理
	if (IS_ERR(source_kd)) {
		printk("source path error1");
		ret = PTR_ERR(source);
		goto error;
	}
	if (IS_ERR(target_kd)) {
		printk("target path error1");
		ret = PTR_ERR(target);
		goto error;
	}
	printk("source path : %s, taget path : %s", source_kd, target_kd);
	mm_segment_t old_fs = get_fs();
	set_fs(KERNEL_DS);
	// 建立文件句柄
	struct file* source_fd = filp_open(source_kd, O_RDONLY, S_IRUSR);
	struct file* target_fd = filp_open(target_kd, O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
	// 异常处理
	if (IS_ERR(source_fd)) {
        ret = PTR_ERR(source);
        printk("source file path error2\n");
        return -1;
    	}
    	if (IS_ERR(target_fd)) {
        ret = PTR_ERR(target);
        printk("target file path error2\n");
        return -1;
    	}
	// 读取文件
	int read_num = 0;
	int count = 0;
	while ((read_num = vfs_read(source_fd,buffer, sizeof(buffer), &source_fd->f_pos)) > 0) {
        vfs_write(target_fd, buffer, read_num, &target_fd->f_pos);
		count += 1;
	}
	set_fs(old_fs);

	return ret;
}
