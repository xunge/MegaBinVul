#include <stdbool.h>
#include <stddef.h>

#define FALSE 0

typedef struct LINE_REC {
    struct LINE_REC *next;
} LINE_REC;

typedef struct TEXT_BUFFER_VIEW_REC {
    struct {
        LINE_REC *first_line;
        LINE_REC *cur_line;
    } *buffer;
    struct {
        int last_linecount;
    } *cache;
    LINE_REC *startline;
    LINE_REC *bottom_startline;
    int subline;
    int bottom_subline;
    int ypos;
    int empty_linecount;
    bool bottom;
    bool more_text;
    void *window;
} TEXT_BUFFER_VIEW_REC;