#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned char *descdata;
    uint64_t descsz;
} Elf_Internal_Note;

extern int is_32bit_elf;
extern struct {
    int e_machine;
} elf_header;
extern int do_wide;

#define GNU_PROPERTY_LOPROC 0xc0000000
#define GNU_PROPERTY_HIPROC 0xdfffffff
#define GNU_PROPERTY_LOUSER 0xe0000000
#define GNU_PROPERTY_X86_ISA_1_USED 0xc0000002
#define GNU_PROPERTY_X86_ISA_1_NEEDED 0xc0000001
#define GNU_PROPERTY_X86_FEATURE_1_AND 0xc0000000
#define GNU_PROPERTY_STACK_SIZE 0x1
#define GNU_PROPERTY_NO_COPY_ON_PROTECTED 0x2

#define EM_X86_64 62
#define EM_IAMCU 6
#define EM_386 3

extern unsigned int byte_get(unsigned char *ptr, unsigned int size);
extern void decode_x86_isa(unsigned int isa);
extern void decode_x86_feature(unsigned int type, unsigned int feature);