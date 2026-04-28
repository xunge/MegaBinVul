#include <signal.h>
#include <stddef.h>
#include <sys/types.h>
#include <ucontext.h>

#define UNUSED(x) (void)(x)
#define HAVE_BACKTRACE 1
#define LL_WARNING 1
#define REDIS_VERSION ""

typedef void (*invalidFunctionWasCalledType)();

void bugReportStart();
void serverLog(int level, const char *fmt, ...);
void bugReportEnd(int exitcode, int sig);
void printCrashReport();
void* getAndSetMcontextEip(ucontext_t *uc, void *addr);
void* getMcontextEip(ucontext_t *uc);
void logStackTrace(void *eip, int skip);
void logRegisters(ucontext_t *uc);
void dumpCodeAroundEIP(void *eip);
void invalidFunctionWasCalled();