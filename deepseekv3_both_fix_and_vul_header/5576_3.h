#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <elf.h>
#include <errno.h>

#define SIZE_UNKNOWN ((off_t)-1)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct magic_set;
typedef struct magic_set magic_set;

typedef struct {
    const char *cd_name;
    uint64_t cd_mask;
} cap_desc_t;

extern cap_desc_t cap_desc_sparc[];
extern cap_desc_t cap_desc_386[];

extern int file_printf(magic_set *, const char *, ...);
extern void file_badread(magic_set *);
extern void file_badseek(magic_set *);
extern void file_error(magic_set *, int, const char *);
extern int donote(magic_set *, void *, size_t, size_t, int, int, int, int *);

extern size_t xsh_sizeof;
extern void *xsh_addr;
extern size_t xsh_offset;
extern size_t xsh_name;
extern size_t xsh_type;
extern size_t xsh_size;

extern size_t xcap_sizeof;
extern void *xcap_addr;
extern size_t xcap_tag;
extern size_t xcap_val;

#define SF1_SUNW_FPUSED 0x1
#define SF1_SUNW_FPKNWN 0x2
#define SF1_SUNW_MASK (SF1_SUNW_FPUSED|SF1_SUNW_FPKNWN)

#define CA_SUNW_NULL 0
#define CA_SUNW_HW_1 1
#define CA_SUNW_SF_1 2

#define INT64_T_FORMAT "ll"

typedef struct {
    uint32_t c_tag;
    uint32_t c_un;
} Elf32_Cap;

typedef struct {
    uint64_t c_tag;
    uint64_t c_un;
} Elf64_Cap;

#define SHT_SUNW_cap 0x6ffffff5
#define EM_AMD64 62
#define EM_SPARC 2
#define EM_SPARCV9 43
#define EM_IA_64 50
#define EM_386 3
#define EM_SPARC32PLUS 18

#define private static