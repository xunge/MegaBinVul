#include <string.h>
#include <unistd.h>
#include <errno.h>

#define FALSE 0
#define TRUE 1

extern int g_strcmp0(const char *str1, const char *str2);
extern int connman_inet_check_hostname(const char *hostname, int len);
extern void connman_error(const char *format, ...);
extern void connman_info(const char *format, ...);