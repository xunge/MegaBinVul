#include <stddef.h>

#define __user
#define compat_uptr_t unsigned long
#define compat_ptr(x) ((void *)(unsigned long)(x))

#define PIO_FONTX 1
#define GIO_FONTX 2
#define KD_FONT_OP_SET 0
#define KD_FONT_OP_GET 1
#define KD_FONT_FLAG_OLD 0x80000000

#define EFAULT 1
#define EPERM 2
#define EINVAL 3

struct compat_consolefontdesc {
    unsigned short charcount;
    unsigned short charheight;
    compat_uptr_t chardata;
};

struct console_font_op {
    unsigned int op;
    unsigned int flags;
    unsigned int width;
    unsigned int height;
    unsigned int charcount;
    unsigned char *data;
};

struct vc {
    void *d;
};

extern struct vc vc_cons[];
extern int fg_console;

extern int copy_from_user(void *, const void *, size_t);
extern int copy_to_user(void *, const void *, size_t);
extern int con_font_op(void *, struct console_font_op *);