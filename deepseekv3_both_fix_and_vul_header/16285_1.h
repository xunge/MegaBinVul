#include <linux/kd.h>
#include <linux/vt.h>
#include <errno.h>

struct vc_data;
struct console_font_op;

extern int con_font_set(struct vc_data *vc, struct console_font_op *op);
extern int con_font_get(struct vc_data *vc, struct console_font_op *op);
extern int con_font_default(struct vc_data *vc, struct console_font_op *op);
extern int con_font_copy(struct vc_data *vc, struct console_font_op *op);