#include <sys/types.h>

#define VT100_EMUL_STATE_CSI 0
#define VT100_EMUL_STATE_NORMAL 0
#define VT100_EMUL_NARGS 0
#define VTFL_LASTCHAR 0
#define VT100_DEBUG 0
#define COLS_LEFT 0

struct wsemul_vt100_emuldata {
    int nargs;
    int args[VT100_EMUL_NARGS];
    char modif1;
    char modif2;
    int flags;
    int state;
};

struct wsemul_inputstate {
    int inchar;
};

typedef unsigned int u_int;

int wsemul_vt100_handle_csi(struct wsemul_vt100_emuldata *edp, struct wsemul_inputstate *instate);