#include <stdio.h>
#include <string.h>

#define XkbNumVirtualMods 16
#define BUFFER_SIZE 256
#define None 0L
#define XkbCFile 1

typedef unsigned long Atom;

typedef struct {
    Atom *vmods;
} XkbNamesRec, *XkbNamesPtr;

typedef struct {
    XkbNamesPtr names;
} XkbDescRec, *XkbDescPtr;

extern char *tbGetBuffer(int len);
extern char *NameForAtom(Atom atom);