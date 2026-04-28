#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

typedef enum {
    DEBUGGER_ACTION_CRASH,
    DEBUGGER_ACTION_DUMP_BACKTRACE
} debugger_action_t;

typedef struct debugger_msg_t {
    debugger_action_t action;
    int32_t tid;
    uintptr_t abort_msg_address;
    int32_t original_si_code;
} debugger_msg_t;

typedef struct debugger_request_t {
    debugger_action_t action;
    int32_t tid;
    pid_t pid;
    uid_t uid;
    gid_t gid;
    uintptr_t abort_msg_address;
    int32_t original_si_code;
} debugger_request_t;

#define AID_SYSTEM 1000
#define ALOGE(...)
#define ALOGV(...)

static int get_process_info(int tid, pid_t* pid, uid_t* uid, gid_t* gid) { return -1; }
static int selinux_action_allowed(int fd, debugger_request_t* request) { return 1; }
static int pid_contains_tid(pid_t pid, int tid) { return 1; }