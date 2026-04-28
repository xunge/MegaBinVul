#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mntent.h>

#define MAXPATHLEN 4096
#define ERROR(msg) fprintf(stderr, "%s\n", msg)

extern int mount_entry_on_generic(struct mntent *mntent, ...);