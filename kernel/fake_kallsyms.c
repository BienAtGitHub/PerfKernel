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
#include <linux/seq_file.h>

static int fake_kallsyms_open(struct inode *inode, struct file *file)
{
        return 0;
}


static const struct file_operations fake_kallsyms_operations = {
        .open = fake_kallsyms_open,
        .read = seq_read,
        .llseek = seq_lseek,
        .release = seq_release_private,
};

static int __init fake_kallsyms_init(void)
{
        proc_create("kallsyms", 0444, NULL, &fake_kallsyms_operations);
        return 0;
}
device_initcall(fake_kallsyms_init);
