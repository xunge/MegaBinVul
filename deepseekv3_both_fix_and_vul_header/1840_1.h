#include <signal.h>
#include <ucontext.h>
#include <stddef.h>

#define HAVE_BACKTRACE 1
#define UNUSED(x) (void)(x)

enum {
    LL_WARNING
};

void serverLogFromHandler(int level, const char *msg);
void logStackTrace(void *addr, int frames);
void *getAndSetMcontextEip(ucontext_t *uc, void *eip);
void *getMcontextEip(ucontext_t *uc);