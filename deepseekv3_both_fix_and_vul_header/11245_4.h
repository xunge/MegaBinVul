#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Bit_Chain {
    unsigned long byte;
} Bit_Chain;

typedef struct {
    int code;
    int size;
    unsigned long value;
} Dwg_Handle;

typedef struct Dwg_Eed_Data Dwg_Eed_Data;

typedef struct Dwg_Eed {
    Dwg_Handle handle;
    unsigned int size;
    void* raw;
    Dwg_Eed_Data* data;
} Dwg_Eed;

typedef struct {
    unsigned long absolute_ref;
} Dwg_Object_APPID;

typedef struct {
    int num_entries;
    Dwg_Object_APPID** apps;
} Dwg_Object_APPID_CONTROL;

typedef struct {
    int is_new_format;
} Dwg_Object_MLEADERSTYLE;

typedef struct {
    unsigned int objid;
    unsigned int size;
    int supertype;
    char* dxfname;
    union {
        Dwg_Object_MLEADERSTYLE* MLEADERSTYLE;
    } tio;
} Dwg_Object;

typedef struct {
    Dwg_Object* object;
    Dwg_Object_APPID_CONTROL appid_control;
} Dwg_Data;

typedef struct {
    void* obj;
    Dwg_Handle handleref;
    unsigned long absolute_ref;
} Dwg_Object_Ref;

typedef struct {
    Dwg_Data* dwg;
    unsigned int objid;
    unsigned int num_eed;
    Dwg_Eed* eed;
    union {
        Dwg_Object_MLEADERSTYLE* MLEADERSTYLE;
    } tio;
} Dwg_Object_Object;

struct Dwg_Eed_Data {
    int code;
    union {
        struct {
            int length;
            int codepage;
            char string[256];
        } eed_0;
        struct {
            int length;
            unsigned short string[256];
        } eed_0_r2007;
        struct {
            unsigned char byte;
        } eed_2;
        struct {
            long layer;
        } eed_3;
        struct {
            int length;
            unsigned char data[256];
        } eed_4;
        struct {
            struct {
                double x;
                double y;
                double z;
            } point;
        } eed_10;
        struct {
            double real;
        } eed_40;
        struct {
            short rs;
        } eed_70;
        struct {
            long rl;
        } eed_71;
    } u;
};

typedef short BITCODE_BS;
typedef unsigned char BITCODE_RC;
typedef short BITCODE_RS;
typedef unsigned short BITCODE_TU;
typedef int BITCODE_RL;
typedef double BITCODE_RD;

#define FORMAT_BS "%hd"
#define FORMAT_RC "%hhu"
#define FORMAT_RS "%hd"
#define FORMAT_RL "%d"
#define FORMAT_RD "%f"
#define FORMAT_TU "%hu"

#define DWG_ERR_INVALIDEED 1
#define DWG_ERR_INVALIDTYPE 2
#define DWG_ERR_VALUEOUTOFBOUNDS 3
#define DWG_SUPERTYPE_OBJECT 0

#define PRE(x)
#define LATER_VERSIONS
#define R_2007

#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define LOG_TRACE(...)
#define LOG_ERROR(...)
#define LOG_INSANE(...)
#define LOG_INSANE_TF(...)

static BITCODE_BS bit_read_BS(Bit_Chain* dat);
static int bit_read_H(Bit_Chain* dat, Dwg_Handle* handle);
static BITCODE_RC bit_read_RC(Bit_Chain* dat);
static BITCODE_RS bit_read_RS(Bit_Chain* dat);
static BITCODE_RS bit_read_RS_LE(Bit_Chain* dat);
static BITCODE_RL bit_read_RL(Bit_Chain* dat);
static BITCODE_RD bit_read_RD(Bit_Chain* dat);
static void* bit_read_TF(Bit_Chain* dat, int size);
static void bit_read_fixed(Bit_Chain* dat, void* buf, int size);
static int dwg_resolve_handleref(Dwg_Object_Ref* ref, Dwg_Object* obj);