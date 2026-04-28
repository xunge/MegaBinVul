#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define NS_CMPRSFLGS 0xc0
#define EMSGSIZE 90

typedef unsigned char u_char;

#define __set_errno(e) (errno = (e))
#define libc_hidden_def(name)