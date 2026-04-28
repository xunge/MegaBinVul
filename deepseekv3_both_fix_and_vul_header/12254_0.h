#include <unistd.h>
#include <sys/prctl.h>
#include <sys/ioctl.h>
#include <setjmp.h>
#include <stdint.h>
#include <sys/types.h>
#include <grp.h>

#define JUMP_VAL 1
#define SYNC_VAL 1

struct nlconfig_t {
    int cloneflags;
    int consolefd;
};

extern int initpipe(void);
extern void bail(const char *msg);
extern void nl_parse(int pipenum, struct nlconfig_t *config);
extern void nl_free(struct nlconfig_t *config);
extern void start_child(int pipenum, jmp_buf *env, int syncpipe[2], struct nlconfig_t *config);