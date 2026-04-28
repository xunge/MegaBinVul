#include <stddef.h>
#include <wchar.h>

#define HFS_NAMELEN 31
#define HFS_MAX_NAMELEN 255
#define ENAMETOOLONG 36

struct hfs_name {
    const char *name;
    int len;
};

struct nls_table {
    int (*char2uni)(const unsigned char *, int, wchar_t *);
    int (*uni2char)(wchar_t, unsigned char *, int);
};

struct hfs_sb_info {
    struct nls_table *nls_disk;
    struct nls_table *nls_io;
};

struct super_block {
    void *s_fs_info;
};

#define HFS_SB(sb) ((struct hfs_sb_info *)(sb->s_fs_info))