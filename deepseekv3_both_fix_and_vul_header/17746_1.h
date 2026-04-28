#include <stdbool.h>

struct vc_data;
struct kbd_struct {
    int kbdmode;
};

extern int shift_state;
extern int shift_down[];
extern bool rep;
extern struct kbd_struct *kbd;
extern bool npadch_active;
extern int npadch_value;
extern int npadch;

#define KVAL(x) (x)
#define K_CAPSSHIFT 1
#define K_SHIFT 2
#define VC_CAPSLOCK 1
#define VC_UNICODE 2

void clr_vc_kbd_led(struct kbd_struct *kbd, int led);
void to_utf8(struct vc_data *vc, int c);
void put_queue(struct vc_data *vc, int c);