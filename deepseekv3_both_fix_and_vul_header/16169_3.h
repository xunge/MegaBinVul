#include <stdint.h>
#include <cstddef>

#define MC_SECUREMODE_PROCESS 1

struct MCStringRef {
    const char* data;
    size_t length;
};

struct MCExecContext {
    void Throw();
};

struct MCError {
    void add(int, int, int, const MCStringRef&);
    void add(int, int, int, const char*);
};

extern uint32_t MCsecuremode;
extern MCStringRef MCshellcmd;
extern MCError* MCeerror;

enum {
    EE_SHELL_NOPERM,
    EE_SHELL_BADCOMMAND
};

enum {
    IO_NORMAL
};

bool MCStringIsEmpty(const MCStringRef&);
int MCS_runcmd(const MCStringRef&, MCStringRef&);