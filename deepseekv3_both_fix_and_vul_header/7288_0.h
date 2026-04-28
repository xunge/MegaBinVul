#include <stdbool.h>
#include <errno.h>

#define APITAG ""
#define EINVAL 22
#define ENOTSUP 95

#define WCALL_CALL_TYPE_FORCED_AUDIO 0
#define WCALL_CALL_TYPE_NORMAL 1
#define WCALL_CALL_TYPE_VIDEO 2

#define WCALL_STATE_ANSWERED 0

#define ICALL_VIDEO_STATE_STARTED 0
#define ICALL_VIDEO_STATE_STOPPED 1

struct wcall {
    bool disable_audio;
    void *icall;
};

void warning(const char *fmt, ...);
void info(const char *fmt, ...);
const char *wcall_call_type_name(int call_type);
void set_state(struct wcall *wcall, int state);

#define ICALL_CALL(icall, func, ...) 0
#define ICALL_CALLE(icall, func, ...) 0