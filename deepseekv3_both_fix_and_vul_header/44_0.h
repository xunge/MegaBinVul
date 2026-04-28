#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long BITCODE_RL;
typedef unsigned short BITCODE_RS;
typedef char* BITCODE_TF;

typedef struct {
    int opts;
    size_t byte;
    size_t size;
    unsigned char* chain;
} Bit_Chain;

typedef struct {
    int numheader_vars;
    int numsections;
    struct Dwg_Section* section;
} Dwg_Header;

typedef struct {
    int numentities;
    size_t dwg_size;
} Dwg_Header_Vars;

typedef struct {
    int number;
    int type;
    char name[32];
} Dwg_Section;

typedef enum {
    SECTION_HEADER_R11,
    SECTION_BLOCK,
    SECTION_LAYER,
    SECTION_STYLE,
    SECTION_LTYPE,
    SECTION_VIEW,
    SECTION_UCS,
    SECTION_VPORT,
    SECTION_APPID,
    SECTION_DIMSTYLE,
    SECTION_VX
} Dwg_Section_Type;

typedef struct {
    Dwg_Header header;
    Dwg_Header_Vars header_vars;
    void* next_hdl;
    int dirty_refs;
} Dwg_Data;

typedef struct {
    void* data;
} Dwg_Object;

#define DWG_OPTS_LOGLEVEL 0x01
#define DWG_ERR_INTERNALERROR 1
#define DWG_ERR_OUTOFMEM 2
#define DWG_ERR_INVALIDDWG 3
#define DWG_ERR_CRITICAL 4
#define DWG_ERR_WRONGCRC 5

#define LOG_ERROR(...)
#define LOG_TRACE(...)
#define LOG_WARN(...)
#define LOG_INFO(...)
#define LOG_TRACE_TF(...)

#define PRE(cond) if(0)
#define SINCE(cond) if(1)
#define VERSION(cond) if(0)
#define UNKNOWN_UNTIL(addr)

#define FORMAT_RL "%lu"
#define FORMAT_RLx "%lx"

extern int loglevel;
extern int dwg_add_Document(Dwg_Data* dwg, int arg);
extern int decode_preR13_section_hdr(const char* name, int type, Bit_Chain* dat, Dwg_Data* dwg);
extern int decode_preR13_header_variables(Bit_Chain* dat, Dwg_Data* dwg);
extern int decode_preR13_entities(BITCODE_RL start, BITCODE_RL end, BITCODE_RL num, BITCODE_RL size, BITCODE_RL max, Bit_Chain* dat, Dwg_Data* dwg);
extern int decode_preR13_section(int type, Bit_Chain* dat, Dwg_Data* dwg);
extern void dwg_set_next_hdl(Dwg_Data* dwg, int val);
extern int decode_preR13_section_chk(int type, Bit_Chain* dat, Dwg_Data* dwg);
extern void dwg_resolve_objectrefs_silent(Dwg_Data* dwg);
extern const unsigned char* dwg_sentinel(int type);
extern unsigned short bit_calc_CRC(unsigned short init, const unsigned char* buf, size_t len);
extern BITCODE_RL bit_read_RL(Bit_Chain* dat);
extern BITCODE_RS bit_read_RS(Bit_Chain* dat);
extern BITCODE_TF bit_read_TF(Bit_Chain* dat, int len);
extern char bit_read_RC(Bit_Chain* dat);