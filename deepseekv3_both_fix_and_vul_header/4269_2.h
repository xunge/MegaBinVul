#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    void* addr;
    size_t length;
} MemMapping;

#define LOGV(...) printf(__VA_ARGS__)
#define LOGW(...) printf(__VA_ARGS__)
#define LOGE(...) printf(__VA_ARGS__)

int sysMapBlockFile(FILE* mapf, MemMapping* pMap);
int sysMapFD(int fd, MemMapping* pMap);