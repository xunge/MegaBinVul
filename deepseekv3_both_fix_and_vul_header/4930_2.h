#include <stdio.h>

struct DCTStream {
    struct {
        int abort;
    } src;
    char* current;
    int lookChar();
};

#define EOF (-1)