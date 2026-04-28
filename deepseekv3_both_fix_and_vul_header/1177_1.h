#define KD_GRAPHICS 0x0001
#define KD_TEXT0 0x0002
#define KD_TEXT1 0x0004
#define KD_TEXT 0x0008
#define EINVAL 22

#define fallthrough do {} while (0)

extern int fg_console;
extern void console_lock(void);
extern void console_unlock(void);
extern void do_blank_screen(int);
extern void do_unblank_screen(int);

struct vc_data {
    unsigned int vc_num;
    unsigned long vc_mode;
};