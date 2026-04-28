#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE_MAX UINT_MAX

typedef struct rfbClientRec* rfbClientPtr;
struct rfbClientRec {
    // Minimal definition needed for compilation
    // Actual implementation may contain more fields
};

void rfbErr(const char *format, ...);
void rfbLogPerror(const char *msg);
void rfbCloseClient(rfbClientPtr cl);
int rfbReadExact(rfbClientPtr cl, char *buf, int len);

#define FILEXFER_ALLOWED_OR_CLOSE_AND_RETURN(msg, cl, ret) \
    do { \
        /* Implementation would go here */ \
    } while (0)