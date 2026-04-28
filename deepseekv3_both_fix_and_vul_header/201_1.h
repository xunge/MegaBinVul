#include <sys/types.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <string.h>

#define REQUIRED_CAPS 0
#define _LINUX_CAPABILITY_VERSION 0x20080522
#define PR_SET_KEEPCAPS 8

typedef unsigned int uid_t;

struct __user_cap_header_struct {
    unsigned int version;
    int pid;
};

struct __user_cap_data_struct {
    unsigned int effective;
    unsigned int permitted;
    unsigned int inheritable;
};

extern int capset(struct __user_cap_header_struct *hdrp, const struct __user_cap_data_struct *datap);