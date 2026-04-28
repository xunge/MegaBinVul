#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdbool.h>

#define TOMBSTONE_DIR "/data/tombstones"
#define AID_SYSTEM 1000

enum logtype {
    ERROR
};

typedef struct log_t {
    pid_t current_tid;
    pid_t crashed_tid;
    int tfd;
    int amfd;
} log_t;

void _LOG(log_t* log, enum logtype type, const char* fmt, ...);
int selinux_android_restorecon(const char* path, unsigned int flags);
char* find_and_open_tombstone(int* fd);
int activity_manager_connect();
bool dump_crash(log_t* log, pid_t pid, pid_t tid, int signal, int original_si_code, 
               uintptr_t abort_msg_address, bool dump_sibling_threads, int* total_sleep_time_usec);
#define ALOGI(fmt, ...)