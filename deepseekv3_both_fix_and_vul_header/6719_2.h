#include <stdint.h>

#define _X_COLD

typedef int ClientPtr;
typedef uint32_t Window;
typedef struct {
    int length;
    Window window;
    unsigned long eventMask;
    int xfixesReqType;
} xXFixesSelectCursorInputReq;
#define REQUEST(x) xXFixesSelectCursorInputReq *stuff = (xXFixesSelectCursorInputReq *)client
#define REQUEST_SIZE_MATCH(x)
#define swaps(x)
#define swapl(x)
extern int (*ProcXFixesVector[])(ClientPtr);