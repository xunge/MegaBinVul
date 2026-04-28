#include <stdint.h>
#include <stdlib.h>

typedef int ClientPtr;
typedef struct {
    int name;
} *CursorPtr;
typedef int Atom;

typedef struct {
    int cursor;
    int nbytes;
} xXFixesSetCursorNameReq;

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_FIXED_SIZE(x, y)
#define REQUEST_AT_LEAST_SIZE(x)
#define VERIFY_CURSOR(a, b, c, d)
#define DixSetAttrAccess 0
#define BAD_RESOURCE 0
#define BadAlloc 0
#define Success 1
#define TRUE 1

Atom MakeAtom(char *name, int length, int makeit) { return 0; }