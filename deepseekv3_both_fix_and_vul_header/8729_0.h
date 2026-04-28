#include <stddef.h>

typedef struct {
    int line;
    int pos;
} Point;

typedef struct {
    int hseq;
    Point start;
    Point end;
} Anchor;

typedef struct {
    Anchor *anchors;
    size_t nanchor;
} AnchorList;

typedef struct {
    Point *marks;
} HmarkerList;

int onAnchor(Anchor *a, int line, int pos);