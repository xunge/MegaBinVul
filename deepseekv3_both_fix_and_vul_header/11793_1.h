#include <sys/types.h>
#include <stddef.h>

typedef struct {
  uid_t uid;
  char *name;
} PolkitUnixUser;