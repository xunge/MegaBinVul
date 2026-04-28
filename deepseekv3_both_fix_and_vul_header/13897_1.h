#include <string.h>
#include <stdint.h>

#define gs_error_invalidfont 1

typedef struct ttfReader ttfReader;
typedef struct gx_ttfReader gx_ttfReader;
typedef unsigned char byte;
typedef unsigned long ulong;
typedef unsigned int uint;

struct gx_ttfReader {
    int error;
    int extra_glyph_index;
    struct {
        struct {
            const byte *data;
            int size;
        } bits;
    } glyph_data;
    int pos;
    struct {
        struct {
            int (*string_proc)(void *, ulong, ulong, const byte **);
            void *data;
        } data;
    } *pfont;
};

static int gs_note_error(int err) { return err; }