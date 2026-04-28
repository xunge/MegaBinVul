#include <assert.h>
#include <stdlib.h>

#define SA_OK 0

extern int add_linux_shareopt(char **, const char *, const char *);
extern int foreach_shareopt(const char *, int (*)(const char *, char **), char **);
extern int foreach_nfs_shareopt(const char *, int (*)(const char *, char **), char **);
extern int get_linux_shareopts_cb(const char *, char **);