#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 256
#define XkbCFile 1

typedef unsigned long Atom;

extern const char *NameForAtom(Atom atm);
extern char *tbGetBuffer(int len);
extern char *XkbStringText(char *str, unsigned format);