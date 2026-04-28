#include <stdlib.h>

#define ENC_UTF8 1

typedef struct VTerm VTerm;
typedef struct VTermState VTermState;
typedef struct VTermLineInfo {
    /* minimal definition for sizeof to work */
    int dummy;
} VTermLineInfo;

typedef struct VTermEncoding {
    void (*init)(struct VTermEncoding *, void *);
    /* other members omitted */
} VTermEncoding;

struct VTermState {
    VTerm *vt;
    size_t combine_chars_size;
    void *combine_chars;
    int cols;
    unsigned char *tabstops;
    int rows;
    VTermLineInfo *lineinfo;
    struct {
        VTermEncoding *enc;
        void *data;
    } encoding_utf8;
};

struct VTerm {
    VTermState *state;
};

extern VTermState *vterm_state_new(VTerm *vt);
extern void *vterm_allocator_malloc(VTerm *vt, size_t size);
extern VTermEncoding *vterm_lookup_encoding(int enc, char c);
extern void vterm_parser_set_callbacks(VTerm *vt, void *parser_callbacks, VTermState *state);

static void *parser_callbacks;