#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef struct {
    long namesz;
    char *namedata;
} Elf_Internal_Note;

#define GNU_BUILD_ATTRIBUTE_TYPE_STRING 's'
#define GNU_BUILD_ATTRIBUTE_TYPE_NUMERIC 'n'
#define GNU_BUILD_ATTRIBUTE_TYPE_BOOL_TRUE 't'
#define GNU_BUILD_ATTRIBUTE_TYPE_BOOL_FALSE 'f'

#define GNU_BUILD_ATTRIBUTE_VERSION 1
#define GNU_BUILD_ATTRIBUTE_STACK_PROT 2
#define GNU_BUILD_ATTRIBUTE_RELRO 3
#define GNU_BUILD_ATTRIBUTE_STACK_SIZE 4
#define GNU_BUILD_ATTRIBUTE_TOOL 5
#define GNU_BUILD_ATTRIBUTE_ABI 6
#define GNU_BUILD_ATTRIBUTE_PIC 7
#define GNU_BUILD_ATTRIBUTE_SHORT_ENUM 8

extern void error(const char *fmt, ...);
extern void warn(const char *fmt, ...);
extern int print_symbol(int left, const char *str);
extern int do_wide;