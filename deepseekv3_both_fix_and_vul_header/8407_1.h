#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <set>
#include <string>
#include <memory>
#include <stdio.h>

enum debugger_action_t {
    DEBUGGER_ACTION_DUMP_TOMBSTONE,
    DEBUGGER_ACTION_CRASH,
    DEBUGGER_ACTION_DUMP_BACKTRACE
};

struct debugger_request_t {
    debugger_action_t action;
    pid_t pid;
    pid_t tid;
    uid_t uid;
    gid_t gid;
};

class BacktraceMap {
public:
    static BacktraceMap* Create(pid_t pid);
};

extern int open_tombstone(std::string* path);
extern bool ptrace_attach_thread(pid_t pid, pid_t tid);
extern int get_process_info(pid_t tid, pid_t* pid, uid_t* uid, gid_t* gid);
extern bool should_attach_gdb(const debugger_request_t& request);
extern int init_getevent();
extern void ptrace_siblings(pid_t pid, pid_t tid, std::set<pid_t>& siblings);
extern int activity_manager_connect();
extern bool drop_privileges();
extern bool perform_dump(const debugger_request_t& request, int fd, int tombstone_fd, BacktraceMap* map, const std::set<pid_t>& siblings, int* crash_signal, std::string* amfd_data);
extern bool send_signal(pid_t pid, pid_t tid, int signal);
extern void activity_manager_write(pid_t pid, int signal, int amfd, const std::string& amfd_data);
extern void wait_for_user_action(const debugger_request_t& request);
extern void uninit_getevent();

#define ALOGE(...) fprintf(stderr, __VA_ARGS__)

namespace android {
namespace base {
    bool WriteFully(int fd, const char* data, size_t size);
}
}