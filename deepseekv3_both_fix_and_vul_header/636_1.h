#include <stddef.h>

typedef unsigned char FT_Byte;
typedef int FT_Error;

struct PS_Parser_ {
    FT_Byte* cursor;
    FT_Byte* limit;
    FT_Error error;
};
typedef struct PS_Parser_* PS_Parser;

#define FT_LOCAL_DEF(x) static x
#define FT_Err_Ok 0
#define FT_THROW(x) (x)
#define Invalid_File_Format 1
#define FT_ERROR(x) 

#define IS_PS_DELIM(c) ( (c) == '(' || (c) == ')' || \
                         (c) == '<' || (c) == '>' || \
                         (c) == '[' || (c) == ']' || \
                         (c) == '{' || (c) == '}' || \
                         (c) == '/' || (c) == '%' )

static void skip_spaces(FT_Byte** cur, FT_Byte* limit);
static FT_Error skip_procedure(FT_Byte** cur, FT_Byte* limit);
static FT_Error skip_literal_string(FT_Byte** cur, FT_Byte* limit);
static FT_Error skip_string(FT_Byte** cur, FT_Byte* limit);