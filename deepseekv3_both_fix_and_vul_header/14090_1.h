#include <stdlib.h>
#include <string.h>

typedef unsigned long VALUE;

#define T_STRING 0
#define Qnil 0

#define GET_STATE(self) struct State *state = (struct State *)self
#define Check_Type(space, type)
#define RSTRING_LEN(str) strlen(str)
#define RSTRING_PTR(str) str
#define ruby_xfree(ptr) free(ptr)

struct State {
    char *space;
    unsigned long space_len;
};