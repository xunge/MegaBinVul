#include <stdint.h>
#include <stddef.h>
#include <limits.h>

typedef struct stream stream;

typedef struct streamIterator {
    int skip_tombstones;
} streamIterator;

typedef struct streamID {
    uint64_t ms;
    uint64_t seq;
} streamID;

void streamIteratorStart(streamIterator *si, stream *s, void *arg1, void *arg2, int flag);
int streamIteratorGetID(streamIterator *si, streamID *id, int64_t *numfields);