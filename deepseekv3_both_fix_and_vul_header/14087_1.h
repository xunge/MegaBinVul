#include <stdlib.h>
#include <string.h>

typedef unsigned long VALUE;

typedef struct {
    char *object_nl;
    unsigned long object_nl_len;
} State;

#define GET_STATE(self) State *state = (State *)DATA_PTR(self)
#define Check_Type(x, t) 
#define RSTRING_LEN(x) 0
#define RSTRING_PTR(x) NULL
#define DATA_PTR(x) NULL
#define Qnil 0
#define T_STRING 0
#define ruby_xfree free