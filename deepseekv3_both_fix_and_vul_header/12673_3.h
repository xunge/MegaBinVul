#include <sys/ioctl.h>
#include <stddef.h>

#define __is_defined(x) x
#define BROKEN_GRAPHICS_PROGRAMS 0
#define ENOSYS 38
#define KD_FONT_OP_SET_DEFAULT 0x4B2C

struct vc_data;

struct vc_struct {
    struct vc_data *d;
};

struct console_font_op {
    unsigned int op;
    unsigned int flags;
    unsigned int width, height;
    unsigned int charcount;
    unsigned char *data;
};

extern struct vc_struct *vc_cons;
extern int fg_console;
extern int con_font_op(struct vc_data *, struct console_font_op *);
extern void console_lock(void);
extern void console_unlock(void);
extern int con_set_default_unimap(struct vc_data *);