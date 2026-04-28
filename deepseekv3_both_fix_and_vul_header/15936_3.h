#include <stdint.h>

typedef uint32_t __u32;

struct pt_regs;

struct task_struct {
    void *replacement_session_keyring;
};

#define CONFIG_X86_MCE 1
#define CONFIG_X86_32 1

#define _TIF_MCE_NOTIFY (1 << 0)
#define _TIF_SIGPENDING (1 << 1)
#define _TIF_NOTIFY_RESUME (1 << 2)
#define _TIF_USER_RETURN_NOTIFY (1 << 3)
#define TIF_NOTIFY_RESUME (1 << 2)
#define TIF_IRET (1 << 4)

extern void mce_notify_process(void);
extern void do_signal(struct pt_regs *regs);
extern void clear_thread_flag(int flag);
extern void tracehook_notify_resume(struct pt_regs *regs);
extern void key_replace_session_keyring(void);
extern void fire_user_return_notifiers(void);

extern struct task_struct *current;