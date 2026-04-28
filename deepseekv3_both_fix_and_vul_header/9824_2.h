#include <sys/socket.h>
#include <sys/uio.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>

#define VERIFY_READ 0
#define __user
#define __force
#define EFAULT 14
#define EMSGSIZE 90

int move_addr_to_kernel(void *namep, int namelen, struct sockaddr *address);
int copy_from_user(void *to, const void *from, unsigned long n);