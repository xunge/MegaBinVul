#include <sys/types.h>
#include <ctype.h>
#include <errno.h>

extern int uml_exitcode;

#define __user

typedef long ssize_t;
typedef long loff_t;

struct file;

long simple_strtol(const char *cp, char **endp, unsigned int base);
unsigned long copy_from_user(void *to, const void __user *from, unsigned long n);