/*
 * Copyright (c) 2021 Yumi Electronics Co., Ltd.
 *		http://yumios.ml
 *
 * fake_kallsyms.c: workaround for Android kallsyms read in userspace.
 *
 * Author: Bien <bien2004official@gmail.com>
 *
 */

#include <linux/proc_fs.h>
#include <linux/module.h>

static ssize_t fake_kallsyms_read(struct file *file, char __user *ubuf,size_t count, loff_t *ppos)
{
        return 0;
}

static ssize_t fake_kallsyms_write(struct file *file, char __user *ubuf,size_t count, loff_t *ppos)
{
        return -1;
}


static const struct file_operations fake_kallsyms_operations = {
        .read = fake_kallsyms_read,
	.write = fake_kallsyms_write,
};

static int __init fake_kallsyms_init(void)
{
        proc_create("kallsyms", 0444, NULL, &fake_kallsyms_operations);
        return 0;
}
device_initcall(fake_kallsyms_init);
