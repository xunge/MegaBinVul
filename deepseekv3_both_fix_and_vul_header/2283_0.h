#include <stdio.h>
#include <string.h>

#define VMOD_BUFFER_SIZE 256
#define BUFFER_SIZE 256
#define XkbNumVirtualMods 16
#define XkbCFile 1

typedef struct _XkbDescRec *XkbDescPtr;

extern char *tbGetBuffer(int size);
extern char *XkbModMaskText(unsigned modMask, unsigned format);
extern char *XkbVModIndexText(XkbDescPtr xkb, int i, unsigned format);