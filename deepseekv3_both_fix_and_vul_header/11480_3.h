#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MagickPathExtent 4096
#define EOF (-1)

typedef struct _Image Image;

struct tag_spec {
    short id;
    const char *name;
};

extern struct tag_spec tags[];
extern int ReadBlobByte(Image *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *RelinquishMagickMemory(void *);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern int WriteBlobString(Image *, const char *);
extern void formatString(Image *, char *, ssize_t);

struct tag_spec tags[] = {
    {0, ""}
};

typedef struct tag_spec tag_spec;