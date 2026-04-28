#include <stdlib.h>
#include <string.h>

typedef unsigned long VALUE;

typedef struct {
    char *space_before;
    unsigned long space_before_len;
} State;

#define GET_STATE(self) State *state = (State *)(self)
#define Check_Type(x, t) 
#define T_STRING 0
#define RSTRING_LEN(x) strlen((const char *)(x))
#define RSTRING_PTR(x) (const char *)(x)
#define ruby_xfree free
#define Qnil 0