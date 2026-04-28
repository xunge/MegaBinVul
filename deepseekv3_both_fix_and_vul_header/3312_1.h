#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char guint8;
typedef int gint;
typedef int gboolean;
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define g_warning printf
#define g_printerr printf
#define d(level, expr) if (level) { expr; }
#define g_malloc malloc

typedef struct {
    guint8 opcode;
    unsigned int length;
    guint8 *data;
    long streamPos;
} BiffQuery;

typedef struct {
    BiffQuery *q;
    gint start_offset;
    gint end_offset;
    gint segment_len;
} MSEscherState;

enum {
    BIFF_MS_O_DRAWING,
    BIFF_MS_O_DRAWING_GROUP,
    BIFF_MS_O_DRAWING_SELECTION,
    BIFF_CHART_gelframe,
    BIFF_CONTINUE
};