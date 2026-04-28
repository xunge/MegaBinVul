#include <string.h>
#include <unistd.h>
#include <errno.h>

#define FALSE 0
#define EINVAL 22

struct connman_info;
struct connman_error;

extern int connman_inet_check_hostname(const char *domainname, int len);
extern void connman_error(const char *format, ...);
extern void connman_info(const char *format, ...);