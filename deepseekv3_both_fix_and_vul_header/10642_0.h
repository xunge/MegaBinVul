#include <assert.h>
#include <stdint.h>

typedef struct XHCIState XHCIState;
typedef struct XHCIEPContext XHCIEPContext;

#define DPRINTF(fmt, ...) 

struct XHCIEPContext {
    int kick_active;
};

struct XHCIState {
    unsigned int numslots;
    struct {
        int enabled;
        XHCIEPContext *eps[31];
    } slots[32];
};

static void xhci_kick_epctx(XHCIEPContext *epctx, unsigned int streamid);