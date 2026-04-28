#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short umode_t;

struct inode {
    unsigned long i_ino;
    struct {
        const char *s_id;
    } *i_sb;
    unsigned short i_mode;
};

struct dentry {
    struct dentry *d_parent;
    struct {
        unsigned int len;
        const char *name;
    } d_name;
};

struct file {
    unsigned int f_mode;
};

struct nfs_open_context {
    struct dentry *dentry;
};

struct nfs_server {
    unsigned int namelen;
    unsigned int attr_bitmask[3];
};

struct iattr {
    unsigned int ia_valid;
    umode_t ia_mode;
    off_t ia_size;
};

struct wait_queue_head {};
#define DECLARE_WAIT_QUEUE_HEAD_ONSTACK(name) struct wait_queue_head name
#define BUG_ON(cond) do { if (cond) abort(); } while(0)
#define dfprintk(facility, format, ...)
#define d_inode(dentry) ((struct inode*)NULL)
#define d_in_lookup(dentry) (0)
#define LOOKUP_OPEN 0
#define LOOKUP_DIRECTORY 0
#define ATTR_OPEN 0
#define ATTR_MODE 0
#define ATTR_SIZE 0
#define FATTR4_WORD2_MODE_UMASK 0
#define NFS_CAP_CASE_INSENSITIVE 0
#define FMODE_CREATED 0
#define d_drop(dentry)
#define d_alloc_parallel(parent, name, wq) NULL
#define d_lookup_done(dentry)
#define dput(dentry)
#define d_splice_alias(inode, dentry) NULL
#define nfs_set_verifier(dentry, verifier)
#define nfs_save_change_attribute(dir) 0
#define inode_peek_iversion_raw(dir) 0
#define nfs_server_capable(dir, cap) 0
#define NFS_SERVER(dir) ((struct nfs_server*)NULL)
#define NFS_PROTO(dir) ((struct { int (*open_context)(); }*)NULL)
#define put_nfs_open_context(ctx)
#define create_nfs_open_context(dentry, flags, file) NULL
#define nfs_finish_open(ctx, dentry, file, flags) 0
#define nfs_check_flags(flags) 0
#define finish_no_open(file, dentry) 0
#define nfs_lookup(dir, dentry, flags) NULL
#define trace_nfs_atomic_open_enter(dir, ctx, flags)
#define trace_nfs_atomic_open_exit(dir, ctx, flags, err)
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define unlikely(cond) (cond)
#define current_umask() (0)
#define ERR_PTR(err) ((void*)(err))