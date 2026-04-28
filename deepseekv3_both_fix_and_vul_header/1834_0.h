#include <dlfcn.h>
#include <errno.h>

#define NELEM(x) (sizeof(x)/sizeof((x)[0]))

static const char *jlink_so_name[] = {
    "libjlinkarm.so",
    "libjlinkarm.so.6",
    "libjlinkarm.so.5",
    "libjlinkarm.so.4",
};

struct {
    void *emu_selectbyusbsn;
    void *open;
    void *execcommand;
    void *tif_select;
    void *setspeed;
    void *connect;
    void *getsn;
    void *emu_getproductname;
    void *rtterminal_control;
    void *rtterminal_read;
} jlink;