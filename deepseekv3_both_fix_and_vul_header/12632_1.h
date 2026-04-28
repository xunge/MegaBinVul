#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bit_Chain {
    unsigned char *chain;
    size_t size;
    size_t byte;
    size_t bit;
    int version;
    int from_version;
} Bit_Chain;

typedef struct Dwg_Section {
    uint32_t address;
} Dwg_Section;

typedef struct Dwg_Section_Info {
    char *name;
    uint32_t fixedtype;
    uint32_t num_sections;
    uint32_t max_decomp_size;
    uint32_t compressed;
    uint32_t size;
    Dwg_Section **sections;
} Dwg_Section_Info;

typedef struct {
    uint32_t num_desc;
} Section_InfoHdr;

typedef struct {
    Section_InfoHdr section_infohdr;
    Dwg_Section_Info *section_info;
} Dwg_Header;

typedef struct Dwg_Data {
    Dwg_Header header;
} Dwg_Data;

typedef enum {
    SECTION_REVHISTORY,
    SECTION_TEMPLATE,
    SECTION_OBJFREESPACE
} Dwg_Section_Type;

typedef struct encrypted_section_header {
    union {
        unsigned char char_data[32];
        uint32_t long_data[8];
        struct {
            uint32_t tag;
            uint32_t section_type;
            uint32_t data_size;
            uint32_t section_size;
            uint32_t address;
            uint32_t unknown;
            uint32_t checksum_1;
            uint32_t checksum_2;
        } fields;
    };
} encrypted_section_header;

typedef unsigned char BITCODE_RC;
typedef unsigned long BITCODE_BL;

#define FORMAT_BL "%lu"
#define LOG_WARN(...)
#define LOG_TRACE(...)
#define LOG_ERROR(...)
#define LOG_INFO(...)
#define LOG_HANDLE(...)
#define LOG_INSANE(...)
#define DWG_ERR_SECTIONNOTFOUND 1
#define DWG_ERR_INVALIDDWG 2
#define DWG_ERR_OUTOFMEM 3
#define DWG_ERR_CRITICAL 4
#define DWG_ERR_VALUEOUTOFBOUNDS 5

static int decompress_R2004_section(Bit_Chain *dat, BITCODE_RC *decomp, uint32_t max_decomp_size, uint32_t data_size);
static int bit_read_fixed(Bit_Chain *dat, unsigned char *data, int bits);
#define MIN(a, b) ((a) < (b) ? (a) : (b))