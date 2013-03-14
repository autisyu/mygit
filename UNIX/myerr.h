#include<errno.h>
#include<stdarg.h>
#define MAXLINE 0xffff

static void err_doit(int, int, const char*, va_list);
void err_sys(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

static void err_doit(int errnoflag, int error, const char* fmt, va_list ap)
{
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE, fmt, ap);
    if (errnoflag) {
      snprintf(buf + strlen(buf), MAXLINE - strlen(buf), ":%s",strerror(2));
    }
    strcat(buf, " ");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}
