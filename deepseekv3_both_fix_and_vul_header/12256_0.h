#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BUFSIZ 1024
#define XpmNoMemory 1
#define XpmSuccess 0
#define XpmExtensions (1L << 0)
#define XpmHotspot (1L << 1)

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned int ncolors;
    unsigned int cpp;
    char **colorTable;
    char *data;
} XpmImage;

typedef struct {
    unsigned long valuemask;
    int x_hotspot;
    int y_hotspot;
    unsigned int nextensions;
    void *extensions;
} XpmInfo;

#define RETURN(status) { ErrorStatus = (status); goto exit; }
#define XpmMalloc malloc
#define XpmCalloc calloc
#define XpmFree free