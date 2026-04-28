#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <endian.h>

#define MSDOS_DOT "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define MSDOS_DOTDOT "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define ENTRY_NAME_MAX 255
#define ER_DE_DOT_NAME 0
#define EINVAL 22

typedef uint16_t __le16;
typedef uint16_t __u16;
typedef uint8_t __u8;

struct exfat {
    /* dummy structure */
};

struct exfat_dentry {
    __le16 name_unicode[ENTRY_NAME_MAX];
    __u8 stream_name_len;
    __le16 stream_name_hash;
};

struct exfat_de_iter {
    struct exfat *exfat;
    /* other members */
};

struct exfat_fsck {
    /* dummy structure */
};

extern struct exfat_fsck exfat_fsck;
extern int exfat_repair_ask(struct exfat_fsck *fsck, int code, const char *msg);
extern char *get_rename_from_user(struct exfat_de_iter *iter);
extern char *generate_rename(struct exfat_de_iter *iter);
extern void exfat_info(const char *format, ...);
extern void exfat_de_iter_get_dirty(struct exfat_de_iter *iter, int count, struct exfat_dentry **dentry);
extern int exfat_utf16_enc(const char *src, __le16 *dst, size_t dst_size);
extern int exfat_utf16_len(const __le16 *str, size_t size);
extern uint16_t exfat_calc_name_hash(struct exfat *exfat, const __le16 *name, int len);