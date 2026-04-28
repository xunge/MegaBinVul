#include <linux/fs.h>
#include <stddef.h>

struct inode;
struct file {
    void *private_data;
};
struct cifsFileInfo;
void cifsFileInfo_put(struct cifsFileInfo *);