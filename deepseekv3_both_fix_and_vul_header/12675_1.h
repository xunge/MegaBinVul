#include <errno.h>
#include <string.h>

#define __user
#define EFAULT 14
#define EINVAL 22
#define PIO_FONTX 1
#define GIO_FONTX 2
#define KD_FONT_OP_SET 0
#define KD_FONT_OP_GET 1
#define KD_FONT_FLAG_OLD 0x80000000

struct consolefontdesc {
    unsigned short charcount;
    unsigned short charheight;
    char __user *chardata;
};

struct console_font_op {
    unsigned int op;
    unsigned int flags;
    unsigned int width;
    unsigned int height;
    unsigned int charcount;
    unsigned char __user *data;
};

struct vc {
    void *d;
};

extern struct vc vc_cons[];
extern int fg_console;

static inline int copy_from_user(void *to, const void __user *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void __user *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline int con_font_op(void *d, struct console_font_op *op) {
    return 0;
}