#include <string.h>
#include <errno.h>

#define asmlinkage
#define __user

#define SMBFS_NAME "smbfs"
#define NCPFS_NAME "ncpfs" 
#define NFS4_NAME "nfs4"
#define EINVAL 22

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

extern int copy_mount_options(const void *, unsigned long *);
extern void do_smb_super_data_conv(void *);
extern void do_ncp_super_data_conv(void *);
extern int do_nfs4_super_data_conv(void *);
extern int do_mount(char *, char *, char *, unsigned long, void *);
extern char *getname(const char *);
extern void putname(char *);
extern void free_page(unsigned long);
extern void lock_kernel(void);
extern void unlock_kernel(void);