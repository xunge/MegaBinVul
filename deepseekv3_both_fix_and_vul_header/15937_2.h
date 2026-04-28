#include <stdint.h>

struct pt_regs;

struct task_struct {
    void *replacement_session_keyring;
};

#define CONFIG_X86_MCE 1
#define CONFIG_X86_32 1

#define TIF_MCE_NOTIFY 0
#define TIF_SIGPENDING 1
#define TIF_NOTIFY_RESUME 2
#define TIF_USER_RETURN_NOTIFY 3
#define TIF_IRET 4

#define _TIF_MCE_NOTIFY (1 << TIF_MCE_NOTIFY)
#define _TIF_SIGPENDING (1 << TIF_SIGPENDING)
#define _TIF_NOTIFY_RESUME (1 << TIF_NOTIFY_RESUME)
#define _TIF_USER_RETURN_NOTIFY (1 << TIF_USER_RETURN_NOTIFY)

extern struct task_struct *current;
extern void mce_notify_process(void);
extern void do_signal(struct pt_regs *regs);
extern void clear_thread_flag(int flag);
extern void tracehook_notify_resume(struct pt_regs *regs);
extern void key_replace_session_keyring(void);
extern void fire_user_return_notifiers(void);

typedef uint32_t __u32;