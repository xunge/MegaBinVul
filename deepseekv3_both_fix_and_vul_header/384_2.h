#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mxml_node_s mxml_node_t;

#define DEBUG_printf(...) printf(__VA_ARGS__)

#define MXML_ADD_AFTER 0
#define MXML_ADD_TO_PARENT 1

static size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t len = strlen(src);
    if (size) {
        size_t n = size - 1;
        if (n > len) n = len;
        memcpy(dst, src, n);
        dst[n] = '\0';
    }
    return len;
}

mxml_node_t* mxmlGetFirstChild(mxml_node_t *node);
mxml_node_t* mxmlGetNextSibling(mxml_node_t *node);
mxml_node_t* mxmlGetLastChild(mxml_node_t *node);
const char* mxmlGetText(mxml_node_t *node, int *whitespace);
void mxmlDelete(mxml_node_t *node);
mxml_node_t* mxmlNewElement(mxml_node_t *parent, const char *name);
void mxmlElementSetAttr(mxml_node_t *node, const char *name, const char *value);
void mxmlAdd(mxml_node_t *node, int where, int to, mxml_node_t *child);