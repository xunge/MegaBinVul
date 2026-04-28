#include <stdbool.h>

typedef struct _GdmManager GdmManager;
typedef struct _GdmDisplay GdmDisplay;

struct _GdmManager {
    struct {
        bool ran_once;
    } *priv;
};

static void maybe_start_pending_initial_login(GdmManager *manager, GdmDisplay *display);

#define TRUE true