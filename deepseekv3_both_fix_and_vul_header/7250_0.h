#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t ut32;
typedef uint16_t ut16;
typedef uint8_t ut8;
typedef uint32_t PE_DWord;

#define UT16_MAX 0xFFFF
#define UT16_ALIGN(x) (((x) + 1) & ~1)
#define TRANSLATION_UTF_16_LEN 24
static const ut16 TRANSLATION_UTF_16[TRANSLATION_UTF_16_LEN/2] = { 'T','r','a','n','s','l','a','t','i','o','n',0 };

typedef struct Var {
    ut16 wLength;
    ut16 wValueLength;
    ut16 wType;
    ut16* szKey;
    ut32 numOfValues;
    ut32* Value;
} Var;

typedef struct RBinPEObj {
    void* b;
} RBinPEObj;

static void free_Var(Var* var);
static void pe_printf(const char* fmt, ...);
static void align32(PE_DWord* addr);
static int r_buf_read_le16_at(void* b, PE_DWord addr);
static int r_buf_read_at(void* b, PE_DWord addr, ut8* buf, int len);