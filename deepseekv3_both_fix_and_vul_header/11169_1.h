#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define KEY_MAX_DESC_SIZE 4096
#define IS_ERR(x) ((unsigned long)(x) >= (unsigned long)-4095)
#define PTR_ERR(x) ((long)(x))
#define __user

char *strndup_user(const char *s, size_t n);
long join_session_keyring(const char *name);