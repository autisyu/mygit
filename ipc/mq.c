#include<mqueue.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
    mqd_t mqd;
    int flags = O_RDWR|O_CREAT|O_EXCL;
    mqd       = mq_open("/tmp/temp.123", flags, 0777, 0);
    struct mq_attr attr;
    mq_getattr(mqd, &attr);
    printf("max #msgs = %ld, max #bytes/msg = %ld, #current on queue = %ld", attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
    mq_close(mqd);
    return 0;
}
