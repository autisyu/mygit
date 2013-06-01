#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kthread.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Kozo");

static int noop(void *dummy)
{
	int i = 0;
	daemonize("mythread");
	while(i++ < 5)
	{
		printk("my thread:current->mm = %p\n",current->mm);
		printk("my thread:current->active_mm = %p\n",current->active_mm);
		set_current_state(TASK_INTERRUPTIBLE);
		schedule_timeout(10*HZ);
	}
	return 0;
}

static int noop2(void *dummy)
{
	int i = 0;
	while(i++ < 5)
	{
		printk("my thread:current->mm = %p\n",current->mm);
		printk("my thread:current->active_mm = %p\n",current->active_mm);
		set_current_state(TASK_INTERRUPTIBLE);
		schedule_timeout(10*HZ);
	}
	return 0;
}
static __init int demo_init(void)
{

	printk(KERN_INFO"demo init\n");
	printk("demo init:current->mm = %p\n",current->mm);
	printk("demo init:current->active_mm = %p\n",current->active_mm);
	//kernel_thread(noop, NULL, CLONE_KERNEL|SIGCHLD);
	kthread_run(noop,NULL,"mythread");
	return 0;
}

static __exit void demo_exit(void)
{
	printk(KERN_INFO"demo exit\n");
}

EXPORT_SYMBOL(noop2);
module_init(demo_init);
module_exit(demo_exit);
