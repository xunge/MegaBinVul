#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mntent.h>
#include <stdbool.h>

struct mntent;
extern int mount_entry_create_dir_file(struct mntent *mntent, const char *path);
extern void cull_mntent_opt(struct mntent *mntent);
extern int parse_mntopts(const char *mntopts, unsigned long *mntflags, char **mntdata);
extern int mount_entry(const char *fsname, const char *path, const char *type, unsigned long mntflags, char *mntdata, bool optional, ...);