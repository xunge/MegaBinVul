#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <errno.h>
#include <limits.h>

struct nlist {
    union {
        char *n_name;
        long n_strx;
    } n_un;
    unsigned char n_type;
    char n_other;
    short n_desc;
    unsigned long n_value;
};

#define ISLAST(p) ((p)->n_un.n_name == NULL || (p)->n_un.n_name[0] == '\0')
#define SIZE_T_MAX ((size_t)-1)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef Elf64_Off Elf_Off;
typedef Elf64_Word Elf_Word;
typedef Elf64_Sword Elf_Sword;
typedef Elf64_Sym Elf_Sym;
typedef Elf64_Ehdr Elf_Ehdr;
typedef Elf64_Shdr Elf_Shdr;

int __elf_is_okay__(Elf64_Ehdr *ehdr);
void elf_sym_to_nlist(struct nlist *p, Elf64_Sym *s, Elf64_Shdr *shdr, Elf64_Word e_shnum);