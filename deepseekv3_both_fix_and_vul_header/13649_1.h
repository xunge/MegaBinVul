#include <stdint.h>
#include <string.h>

struct cli_exe_section {
    uint32_t raw;
    uint32_t rsz;
    uint32_t ursz;
    uint32_t vsz;
};

struct pe_image_file_hdr {
    uint16_t SizeOfOptionalHeader;
    uint16_t NumberOfSections;
};

#define EC16(x) (x)
uint32_t cli_readint32(const void *);
void cli_writeint32(void *, uint32_t);
int cli_writen(int, const void *, unsigned int);
void cli_dbgmsg(const char *, ...);
int yc_poly_emulator(char *, char *, uint32_t, ...);