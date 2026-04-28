#include <limits.h>
#include <string.h>

typedef unsigned long Window;
typedef struct _XDisplay Display;
typedef unsigned long Atom;

#define USHRT_MAX 65535
#define PropModeReplace 0
#define XA_STRING ((Atom) 31)
#define XA_WM_CLASS ((Atom) 67)

typedef struct {
    char *res_name;
    char *res_class;
} XClassHint;

size_t safestrlen(const char *str);
void *Xmalloc(size_t size);
void Xfree(void *ptr);
int XChangeProperty(Display *display, Window w, Atom property, Atom type,
                    int format, int mode, const unsigned char *data,
                    int nelements);