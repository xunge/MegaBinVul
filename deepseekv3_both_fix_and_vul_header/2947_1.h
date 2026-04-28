#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define EOF (-1)
#define gFalse false
#define gTrue true
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

typedef bool GBool;

enum {
    twoDimPass,
    twoDimHoriz,
    twoDimVertR3,
    twoDimVertR2,
    twoDimVertR1,
    twoDimVert0,
    twoDimVertL3,
    twoDimVertL2,
    twoDimVertL1
};

enum {
    errSyntaxError = 1
};

class CCITTFaxStream {
public:
    int lookChar();
private:
    int buf;
    int outputBits;
    GBool eof;
    GBool err;
    int columns;
    int* codingLine;
    int* refLine;
    int a0i;
    GBool nextLine2D;
    GBool endOfBlock;
    int rows;
    GBool endOfLine;
    GBool byteAlign;
    int row;
    int encoding;
    GBool black;
    int inputBits;

    int getTwoDimCode();
    int getBlackCode();
    int getWhiteCode();
    void addPixels(int a1, int blackPixels);
    void addPixelsNeg(int a1, int blackPixels);
    int lookBits(int n);
    void eatBits(int n);
    void error(int type, int pos, const char* msg, ...);
    int getPos();
};