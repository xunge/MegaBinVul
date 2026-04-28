#include <stdbool.h>

typedef struct XRefEntry {
    int offset;
    int gen;
    int type;
    int flags;
} XRefEntry;

class XRef {
public:
    XRefEntry *getEntry(int i, bool complainIfMissing);
};

enum {
    xrefEntryNone,
    xrefEntryFree,
    errInternal,
    errSyntaxError
};

extern XRefEntry dummyXRefEntry;
extern XRefEntry *entries;
extern int size;
extern int capacity;
extern bool xRefStream;
extern unsigned long mainXRefEntriesOffset;

void error(int errCode, int pos, const char *msg, ...);
bool parseEntry(unsigned long offset, XRefEntry *entry);
void readXRefUntil(int i);
#define unlikely(expr) (expr)