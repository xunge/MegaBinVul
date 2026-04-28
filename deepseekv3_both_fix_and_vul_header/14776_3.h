#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>

extern int mount_entry_on_generic(struct mntent *mntent, const char *mnt_dir, ...);