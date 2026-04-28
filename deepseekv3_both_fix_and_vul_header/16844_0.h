#include <string.h>

#define SUN_EMUL_NARGS 10
#define SUN_EMUL_STATE_NORMAL 0

struct wsemul_sun_emuldata {
    int nargs;
    int args[SUN_EMUL_NARGS];
    int state;
};

struct wsemul_inputstate {
    int inchar;
};

int wsemul_sun_control(struct wsemul_sun_emuldata *edp, struct wsemul_inputstate *instate);