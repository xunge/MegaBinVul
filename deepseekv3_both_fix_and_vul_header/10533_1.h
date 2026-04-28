#include <stdio.h>
#include <stdbool.h>

#define EM_ARM 40
#define EM_MIPS 8
#define EM_MIPS_RS3_LE 10
#define EM_MSP430 105
#define EM_NDS32 167
#define EM_PPC 20
#define EM_PPC64 21
#define EM_S390 22
#define EM_S390_OLD 0xA390
#define EM_SPARC 2
#define EM_SPARC32PLUS 18
#define EM_SPARCV9 43
#define EM_TI_C6000 140

#define SHT_ARM_ATTRIBUTES 64
#define SHT_MSP430_ATTRIBUTES 65
#define SHT_GNU_ATTRIBUTES 0x6ffffff5
#define SHT_C6000_ATTRIBUTES 0x70000003

#define TRUE true
#define FALSE false

typedef bool bfd_boolean;

struct {
    int e_machine;
} elf_header;

extern bool do_arch;
extern bfd_boolean process_attributes(FILE*, const char*, int, void*, void*);
extern bfd_boolean process_mips_specific(FILE*);
extern bfd_boolean process_nds32_specific(FILE*);
extern void display_arm_attribute(void);
extern void display_generic_attribute(void);
extern void display_msp430x_attribute(void);
extern void display_power_gnu_attribute(void);
extern void display_s390_gnu_attribute(void);
extern void display_sparc_gnu_attribute(void);
extern void display_tic6x_attribute(void);
extern void display_public_gnu_attributes(void);