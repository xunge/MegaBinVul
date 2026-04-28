#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } bfd_boolean;

typedef struct {
    unsigned int e_phnum;
} Elf_Internal_Ehdr;

typedef struct {
} Elf_Internal_Phdr;
typedef struct {
} Elf32_External_Phdr;
typedef struct {
} Elf64_External_Phdr;

extern Elf_Internal_Ehdr elf_header;
extern bfd_boolean is_32bit_elf;
extern size_t current_file_size;
extern Elf_Internal_Phdr *program_headers;

extern void *cmalloc(size_t, size_t);
extern void error(const char *, ...);
extern bfd_boolean get_32bit_program_headers(FILE *, Elf_Internal_Phdr *);
extern bfd_boolean get_64bit_program_headers(FILE *, Elf_Internal_Phdr *);