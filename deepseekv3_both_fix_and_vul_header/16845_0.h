#include <stdint.h>

#define VT100_EMUL_STATE_DCS 0
#define VT100_EMUL_STATE_STRING 0
#define VT100_EMUL_STATE_DCS_DOLLAR 0
#define VT100_EMUL_NARGS 0
#define VT100_DEBUG 0
#define VT100_PRINTNOTIMPL 0
#define VT100_PRINTUNKNOWN 0
#define ARG(x) 0

struct wsemul_vt100_emuldata {
    int nargs;
    int args[VT100_EMUL_NARGS];
    int state;
};

struct wsemul_inputstate {
    uint8_t inchar;
};

typedef unsigned int u_int;