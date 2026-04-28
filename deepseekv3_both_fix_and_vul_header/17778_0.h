#include <stdlib.h>

typedef struct rfbClientRec* rfbClientPtr;
typedef struct rfbClientIterator* rfbClientIteratorPtr;

struct rfbClientIterator {
    rfbClientPtr next;
};

void rfbDecrClientRef(rfbClientPtr client);