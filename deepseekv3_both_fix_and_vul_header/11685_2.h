#include <stdlib.h>
#include <string.h>

typedef struct GooString {
    GooString* copy();
} GooString;

enum ErrorCategory {
    errInternal
};

extern void error(ErrorCategory category, int code, const char *msg, ...);

struct GfxColorSpace {
    void *displayProfile;
    GooString *displayProfileName;
    void setDisplayProfileName(GooString *name);
};