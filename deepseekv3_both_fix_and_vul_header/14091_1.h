#include <stdlib.h>
#include <string.h>

typedef unsigned long VALUE;

struct State {
    char *array_nl;
    unsigned long array_nl_len;
};

#define GET_STATE(self) struct State *state = (struct State *)0
#define Check_Type(x, t) 
#define T_STRING 0
#define RSTRING_LEN(x) strlen(x)
#define RSTRING_PTR(x) x
#define ruby_xfree free
#define Qnil 0