#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define REDIS_OK 0
#define REDIS_ERR -1
#define REDIS_WARNING 1
#define DEFAULT_DIR_MODE 0755

struct redisServer {
    char *ds_path;
    char *diskstore_path;
};

extern struct redisServer server;

void redisLog(int level, const char *fmt, ...);

#define mkdir(path) mkdir(path, DEFAULT_DIR_MODE)