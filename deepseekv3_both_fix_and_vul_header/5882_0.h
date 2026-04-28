#include <string.h>

#define ENAMETOOLONG 36
#define EIO 5

struct super_block;

struct pathComponent {
    int componentType;
    int lengthComponentIdent;
    unsigned char componentIdent[0];
};

extern int udf_get_filename(struct super_block *sb, unsigned char *from,
                           int fromlen, unsigned char *to, int tolen);