#include <stdio.h>
#include <ctype.h>

typedef struct _object PyObject;
typedef struct {
    char tag;
    union {
        char b;
        unsigned char B;
        short h;
        unsigned short H;
        int i;
        unsigned int I;
        long l;
        unsigned long L;
        long long q;
        unsigned long long Q;
        float f;
        double d;
        char c;
        void *p;
    } value;
} PyCArgObject;

static int is_literal_char(unsigned char c) {
    return isprint(c) && c != '\'' && c != '\\';
}

static PyObject* PyUnicode_FromString(const char *u) {
    return (PyObject*)u;
}