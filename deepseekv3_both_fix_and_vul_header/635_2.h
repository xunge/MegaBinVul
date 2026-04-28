#include <stddef.h>
#include <string.h>
#include <ctype.h>

typedef unsigned long FT_ULong;
typedef unsigned short FT_UShort;
typedef unsigned char FT_Byte;
typedef int FT_Error;
typedef int FT_Bool;
typedef void* FT_Pointer;

#define FT_LOCAL_DEF(x) x
#define FT_Err_Ok 0
#define Invalid_File_Format 1
#define FT_THROW(x) (x)
#define FT_ERROR(x)
#define FT_STREAM_POS() 0
#define FT_STREAM_SKIP(x) 0
#define FT_STREAM_SEEK(x) 0
#define FT_STREAM_READ(x, y) 0
#define FT_ALLOC(x, y) 0
#define FT_MEM_MOVE(dst, src, size) memmove(dst, src, size)
#define FT_BOOL(x) ((x) ? 1 : 0)

struct FT_StreamRec_;
struct FT_MemoryRec_;
typedef struct FT_StreamRec_* FT_Stream;
typedef struct FT_MemoryRec_* FT_Memory;

struct T1_ParserRec_;
struct PSAux_ServiceRec_;
typedef struct T1_ParserRec_* T1_Parser;
typedef struct PSAux_ServiceRec_* PSAux_Service;

struct T1_ParserRec_ {
    FT_Stream stream;
    struct {
        FT_Memory memory;
        FT_Byte* cursor;
        FT_Byte* limit;
        FT_Error error;
        FT_Byte* base;
    } root;
    FT_ULong private_len;
    FT_Byte* private_dict;
    FT_Byte* base_dict;
    FT_ULong base_len;
    FT_Bool in_pfb;
    FT_Bool in_memory;
    FT_Bool single_block;
};

struct PSAux_ServiceRec_ {
    struct {
        FT_Error (*to_bytes)(void*, FT_Byte*, FT_ULong, FT_ULong*, int);
    } *ps_parser_funcs;
    void (*t1_decrypt)(FT_Byte*, FT_ULong, unsigned int);
};

FT_Error read_pfb_tag(FT_Stream stream, FT_UShort* tag, FT_ULong* size);
void T1_Skip_PS_Token(T1_Parser parser);
void T1_Skip_Spaces(T1_Parser parser);

#define ft_strncmp strncmp
#define ft_memchr memchr
#define ft_isxdigit isxdigit