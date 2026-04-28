#include <stddef.h>
#include <stdio.h>

#define unlikely(x) (x)

class Stream {
public:
    virtual int doGetChars(int n, unsigned char *buffer) = 0;
};

class ImageStream {
public:
    unsigned char *getLine();
    unsigned char *inputLine;
    unsigned char *imgLine;
    int inputLineSize;
    int nBits;
    int nVals;
    Stream *str;
};