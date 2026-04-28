#include <stdlib.h>

typedef struct Line Line;
typedef struct Anchor Anchor;
typedef struct Buffer Buffer;
typedef struct AnchorList AnchorList;
typedef struct Mark Mark;
typedef struct Position Position;

struct Position {
    int line;
    int pos;
};

struct Mark {
    int line;
    int pos;
};

struct HMarkList {
    Mark *marks;
};

struct Line {
    int linenumber;
    int size;
    char *lineBuf;
    char *propBuf;
    Line *next;
    Line *prev;
};

struct Anchor {
    int hseq;
    int rows;
    int y;
    Position start;
    Position end;
    char *url;
    char *target;
};

struct AnchorList {
    int nanchor;
    Anchor *anchors;
};

struct Buffer {
    Line *firstLine;
    struct HMarkList *hmarklist;
    void *formitem;
};

#define COLPOS(line, pos) ((pos))
#define PE_FORM (1 << 0)

int columnPos(Line *l, int col);
void *putAnchor(void *formitem, char *url, char *target, Anchor **a, void *arg1, void *arg2, char c, int line, int pos);