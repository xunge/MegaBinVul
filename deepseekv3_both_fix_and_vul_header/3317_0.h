#include <stdio.h>
#include <string.h>

typedef struct ASSCodesCallbacks {
    void (*text)(void *priv, const char *text, int len);
    void (*new_line)(void *priv, int forced);
    void (*style)(void *priv, char style, int close);
    void (*color)(void *priv, unsigned int color, int component);
    void (*alpha)(void *priv, int alpha, int component);
    void (*font_name)(void *priv, const char *name);
    void (*font_size)(void *priv, int size);
    void (*alignment)(void *priv, int alignment);
    void (*cancel_overrides)(void *priv, const char *style);
    void (*move)(void *priv, int x1, int y1, int x2, int y2, int t1, int t2);
    void (*origin)(void *priv, int x, int y);
    void (*end)(void *priv);
} ASSCodesCallbacks;

#define AVERROR_INVALIDDATA -1