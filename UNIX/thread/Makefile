obj-m := test.o
KERNELBUILD :=/lib/modules/$(shell uname -r)/build
default:
	make -C $(KERNELBUILD) M=$(shell pwd) 

clean:
	rm -rf *.o *.ko *.mod.c .*.cmd *.markers *.order *.symvers .tmp_versions
