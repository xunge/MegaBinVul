#include <stdlib.h>
#include <string.h>

typedef struct bfd bfd;
typedef unsigned long bfd_vma;
typedef unsigned char bfd_byte;

typedef struct {
    bfd_vma sh_size;
    void *bfd_section;
} Elf_Internal_Shdr;

#define FALSE 0
#define TRUE 1

#define OBJ_ATTR_PROC 1
#define OBJ_ATTR_GNU 2

#define Tag_File 1
#define Tag_Section 2
#define Tag_Symbol 3

#define ATTR_TYPE_FLAG_INT_VAL 1
#define ATTR_TYPE_FLAG_STR_VAL 2

struct elf_backend_data {
    const char *obj_attrs_vendor;
};

extern void _bfd_error_handler(const char *, ...);
extern void *bfd_malloc(bfd_vma);
extern int bfd_get_section_contents(bfd *, void *, bfd_byte *, bfd_vma, bfd_vma);
extern bfd_vma bfd_get_32(bfd *, bfd_byte *);
extern unsigned int _bfd_safe_read_leb128(bfd *, bfd_byte *, unsigned int *, int, bfd_byte *);
extern int _bfd_elf_obj_attrs_arg_type(bfd *, int, unsigned int);
extern void bfd_elf_add_obj_attr_int_string(bfd *, int, unsigned int, bfd_vma, const char *);
extern void bfd_elf_add_obj_attr_string(bfd *, int, unsigned int, const char *);
extern void bfd_elf_add_obj_attr_int(bfd *, int, unsigned int, bfd_vma);
extern struct elf_backend_data *get_elf_backend_data(bfd *);