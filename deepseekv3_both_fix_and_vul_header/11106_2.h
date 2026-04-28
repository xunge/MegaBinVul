#include <signal.h>
#include <sys/types.h>

struct siginfo {
    int si_signo;
    int si_errno;
    int si_code;
    union {
        struct {
            int _tid;
            int _overrun;
            int _sys_private;
        } _timer;
    } _sifields;
#define si_tid      _sifields._timer._tid
#define si_overrun  _sifields._timer._overrun
#define si_sys_private _sifields._timer._sys_private
};

struct k_itimer {
    int it_requeue_pending;
    long long it_overrun;
    long long it_overrun_last;
    int it_active;
    struct {
        void (*timer_rearm)(struct k_itimer *);
    } *kclock;
};

struct k_itimer *lock_timer(int tid, unsigned long *flags);
void unlock_timer(struct k_itimer *timr, unsigned long flags);
int timer_overrun_to_int(struct k_itimer *timr, int overrun);