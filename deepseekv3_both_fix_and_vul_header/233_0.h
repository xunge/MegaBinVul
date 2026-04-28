#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>

#define BUFSIZE 1024
#define DEVSIZE 256
#define MAX_DEVS 64

typedef struct {
    char *keyHandle;
    unsigned char *publicKey;
    size_t key_len;
} device_t;