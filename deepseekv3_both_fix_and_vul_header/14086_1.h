#include <stdlib.h>
#include <string.h>

typedef unsigned long VALUE;

typedef struct {
    char *indent;
    unsigned long indent_len;
} State;

#define GET_STATE(self) State *state = (State *)(self)
#define Check_Type(x, t) 
#define RSTRING_LEN(x) strlen(x)
#define RSTRING_PTR(x) x
#define ruby_xfree free
#define Qnil 0
#define T_STRING 0