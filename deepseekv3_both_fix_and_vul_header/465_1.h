#include <stddef.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char FT_Byte;
typedef unsigned short FT_UShort;
typedef unsigned long FT_ULong;
typedef int FT_Error;
typedef int FT_Bool;
typedef void* FT_Pointer;
typedef void* FT_Memory;
typedef void* FT_Stream;

#define FT_LOCAL_DEF(x) x
#define FT_Err_Ok 0
#define Invalid_File_Format 1
#define FT_THROW(x) x
#define FT_ERROR(x)
#define FT_STREAM_POS() 0
#define FT_STREAM_SKIP(x) 0
#define FT_STREAM_SEEK(x) 0
#define FT_STREAM_READ(x, y) 0
#define FT_ALLOC(x, y) 0
#define FT_MEM_MOVE(dest, src, n) memmove(dest, src, n)
#define FT_BOOL(x) ((x) ? 1 : 0)

typedef struct T1_ParserRec_* T1_Parser;
typedef struct PSAux_ServiceRec_* PSAux_Service;

struct T1_ParserRec_ {
    FT_Stream stream;
    struct {
        FT_Memory memory;
        FT_Byte* cursor;
        FT_Byte* limit;
        FT_Byte* base;
        FT_Error error;
    } root;
    FT_ULong private_len;
    FT_Byte* private_dict;
    FT_Bool in_pfb;
    FT_Byte* base_dict;
    FT_ULong base_len;
    FT_Bool in_memory;
    FT_Bool single_block;
};

struct PSAux_ServiceRec_ {
    struct {
        FT_Error (*to_bytes)(struct T1_ParserRec_*, FT_Byte*, FT_ULong, FT_ULong*, int);
    } *ps_parser_funcs;
    void (*t1_decrypt)(FT_Byte*, FT_ULong, unsigned int);
};

static FT_Error read_pfb_tag(FT_Stream stream, FT_UShort* tag, FT_ULong* size) {
    return FT_Err_Ok;
}

static void T1_Skip_PS_Token(T1_Parser parser) {}
static void T1_Skip_Spaces(T1_Parser parser) {}

static int ft_isxdigit(int c) {
    return isxdigit(c);
}

static void* ft_memchr(const void* s, int c, size_t n) {
    return memchr(s, c, n);
}

static int ft_strncmp(const char* s1, const char* s2, size_t n) {
    return strncmp(s1, s2, n);
}