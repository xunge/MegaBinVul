#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_TREE_SIZE 256

struct smb_vol {
    const char *UNC;
    const char *prepath;
};

struct cifs_sb_info;

#define CIFS_DIR_SEP(cifs_sb) '\\'
#define GFP_KERNEL 0
#define FYI 1
#define ENOMEM 12

#define ERR_PTR(err) ((void *)(long)(err))

void convert_delimiter(char *path, char delim);
void cifs_dbg(int level, const char *fmt, ...);