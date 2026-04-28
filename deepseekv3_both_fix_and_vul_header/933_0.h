#include <unistd.h>
#include <signal.h>

#define REDIS_OK 0
#define REDIS_ERR -1
#define REDIS_WARNING 1

struct redisServer {
    int bgsavechildpid;
    int appendonly;
    int appendfd;
    int vm_enabled;
    char *vm_swap_file;
    int saveparamslen;
    char *dbfilename;
    int daemonize;
    char *pidfile;
};

extern struct redisServer server;

void redisLog(int level, const char *fmt, ...);
int rdbRemoveTempFile(int pid);
int aof_fsync(int fd);
int rdbSave(char *filename);