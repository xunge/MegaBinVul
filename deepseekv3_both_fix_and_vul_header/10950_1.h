#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct evalstring {
    struct evalstringpart *parts;
    bool visited;
};

struct evalstringpart {
    // define structure members as needed
};

struct scanner {
    int chr;
    // define other members as needed
};

extern struct {
    size_t len;
    // define other members as needed
} buf;

void next(struct scanner *s);
void escape(struct scanner *s, struct evalstringpart ***end);
void bufadd(void *buf, int chr);
void addstringpart(struct evalstringpart ***end, int type);
void space(struct scanner *s);
void *xmalloc(size_t size);