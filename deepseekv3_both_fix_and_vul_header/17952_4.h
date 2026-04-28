#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <time.h>

struct inode {
    struct super_block *i_sb;
    unsigned int i_mode;
};

struct dentry {
    struct inode *d_inode;
    struct {
        char *name;
        unsigned int len;
    } d_name;
    unsigned long d_time;
};

struct nameidata {
    unsigned int flags;
    struct {
        struct {
            struct file *file;
            int create_mode;
            int f_flags;
        } open;
    } intent;
};

struct file {
    int f_flags;
};

struct cifs_sb_info {
    unsigned int mnt_cifs_flags;
};

struct cifs_tcon {
    bool unix_ext;
    bool broken_posix_open;
};

struct tcon_link {};
struct cifsFileInfo {};
struct super_block {};

#define REQ_OPLOCK 0
#define CIFS_MOUNT_POSIX_PATHS 0
#define LOOKUP_EXCL 0x01
#define LOOKUP_DIRECTORY 0x02
#define LOOKUP_OPEN 0x04
#define O_CREAT 00000100
#define EINVAL 22
#define ENOMEM 12
#define ENOENT 2
#define EOPNOTSUPP 95
#define EACCES 13
#define S_ISREG(mode) (((mode) & 0170000) == 0100000)

typedef unsigned short __u16;
typedef unsigned int __u32;

extern unsigned long jiffies;
extern bool enable_oplocks;
extern int GetXid(void);
extern void FreeXid(int);
extern void cFYI(int, const char*, ...);
extern void cERROR(int, const char*, ...);
extern struct cifs_sb_info *CIFS_SB(struct super_block *);
extern struct tcon_link *cifs_sb_tlink(struct cifs_sb_info *);
extern struct cifs_tcon *tlink_tcon(struct tcon_link *);
extern char *build_path_from_dentry(struct dentry *);
extern int cifs_posix_open(char *, struct inode **, struct super_block *, int, int, __u32 *, __u16 *, int);
extern int cifs_get_inode_info_unix(struct inode **, const char *, struct super_block *, int);
extern int cifs_get_inode_info(struct inode **, const char *, void *, struct super_block *, int, void *);
extern int CIFSSMBClose(int, struct cifs_tcon *, __u16);
extern struct file *lookup_instantiate_filp(struct nameidata *, struct dentry *, int (*)(struct file *, struct dentry *));
extern int generic_file_open(struct file *, struct dentry *);
extern struct cifsFileInfo *cifs_new_fileinfo(__u16, struct file *, struct tcon_link *, __u32);
extern void renew_parental_timestamps(struct dentry *);
extern void cifs_put_tlink(struct tcon_link *);
extern void d_instantiate(struct dentry *, struct inode *);
extern void d_add(struct dentry *, struct inode *);
extern void *ERR_PTR(long);
extern long PTR_ERR(const void *);
extern void kfree(const void *);
extern void fput(struct file *);
extern int IS_ERR(const void *);