#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;
typedef unsigned char ut8;

#define R_API

typedef struct RAsm RAsm;
typedef struct RParse RParse;
typedef struct RAsmCode {
    char *assembly;
} RAsmCode;

int r_hex_str2bin(const char *hexstr, ut8 *buf);
RAsmCode* r_asm_mdisassemble(RAsm *a, const ut8 *buf, ut64 len);
void r_parse_parse(RParse *p, const char *assembly, char *output);