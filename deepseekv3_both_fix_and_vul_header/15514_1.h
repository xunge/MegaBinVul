#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned char BITCODE_RC;

typedef enum {
    SECTION_REVHISTORY,
    SECTION_TEMPLATE,
    SECTION_OBJFREESPACE
} Dwg_Section_Type;

typedef struct Bit_Chain {
    BITCODE_RC *chain;
    unsigned int bit;
    unsigned int byte;
    uint64_t size;
    int version;
    int from_version;
} Bit_Chain;

typedef struct r2007_section_page {
    int id;
    uint64_t offset;
    uint64_t comp_size;
    uint64_t uncomp_size;
} r2007_section_page;

typedef struct r2007_page {
    uint64_t offset;
    uint64_t size;
} r2007_page;

typedef struct r2007_section {
    uint64_t data_size;
    uint64_t num_pages;
    r2007_section_page **pages;
} r2007_section;

#define DWG_ERR_SECTIONNOTFOUND 1
#define DWG_ERR_VALUEOUTOFBOUNDS 2
#define DWG_ERR_INVALIDDWG 3
#define DWG_ERR_OUTOFMEM 4
#define DWG_ERR_PAGENOTFOUND 5

#define LOG_WARN(...)
#define LOG_TRACE(...)
#define LOG_ERROR(...)
#define LOG_HANDLE(...)

static r2007_section* get_section(r2007_section* sections_map, Dwg_Section_Type sec_type);
static r2007_page* get_page(r2007_page* pages_map, int id);
static int read_data_page(Bit_Chain* dat, BITCODE_RC* decomp, size_t page_size, size_t comp_size, size_t uncomp_size, BITCODE_RC* decomp_end);