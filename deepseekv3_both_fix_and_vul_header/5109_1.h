#include <stdbool.h>
#include <stdint.h>

#define unlikely(x) __builtin_expect(!!(x), 0)

enum {
    errInternal,
    errSyntaxError
};

typedef enum {
    xrefEntryNone,
    xrefEntryFree
} XRefEntryType;

typedef struct {
    XRefEntryType type;
} XRefEntry;

class XRef {
public:
    XRefEntry *getEntry(int i, bool complainIfMissing);
};

extern XRefEntry dummyXRefEntry;
extern XRefEntry *entries;
extern int size;
extern int capacity;
extern bool xRefStream;
extern int64_t mainXRefEntriesOffset;

extern void error(int errCode, int pos, const char *msg, ...);
extern bool parseEntry(int64_t offset, XRefEntry *entry);
extern void readXRefUntil(int i);