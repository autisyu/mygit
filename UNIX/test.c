#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENCE("Dual BSD/GPL");
int add_integer(int, int);
int sub_integer(int, int);

int result(void)
{
    int a, b
    a = sub_integer(1, 3);
    b = add_integer(1, 3);
    printk("%d\n", a);
    printk("%d\n", b);
    return 0;
}
