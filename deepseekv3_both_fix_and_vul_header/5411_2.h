#include <stdint.h>

typedef int32_t FT_Error;
typedef uint32_t FT_ULong;
typedef uint16_t FT_UShort;
typedef uint16_t FT_UInt;
typedef int32_t FT_Int;
typedef uint8_t FT_Byte;

#define FT_NEXT_USHORT(p)  ( ( (p)[0] << 8 ) | (p)[1] ); (p) += 2
#define FT_NEXT_ULONG(p)   ( ( (p)[0] << 24 ) | ( (p)[1] << 16 ) | ( (p)[2] << 8 ) | (p)[3] ); (p) += 4
#define FT_PEEK_USHORT(p)  ( ( (p)[0] << 8 ) | (p)[1] )

#define FT_THROW(e)  (-(e))
#define FT_TRACE3(x) 
#define FT_TRACE4(x) 

enum {
    Invalid_Table,
    Invalid_Argument
};

typedef struct TT_SBitDecoder_ {
    FT_Byte* eblc_base;
    FT_Byte* eblc_limit;
    FT_ULong strike_index_array;
    FT_ULong strike_index_count;
} *TT_SBitDecoder;

static FT_Error tt_sbit_decoder_load_metrics(TT_SBitDecoder decoder, FT_Byte** p, FT_Byte* p_limit, int);
static FT_Error tt_sbit_decoder_load_bitmap(TT_SBitDecoder decoder, FT_UInt image_format, FT_ULong image_start, FT_ULong image_end, FT_Int x_pos, FT_Int y_pos);