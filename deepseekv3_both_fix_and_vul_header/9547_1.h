#include <stdint.h>
#include <string.h>
#include <ctype.h>

struct magic_set;
#define CAST(type, value) ((type)(value))
#define ELF_ALIGN(a) (((a) + 3) & ~3)
#define ELFCORE
#define FLAGS_DID_NOTE 0x01
#define FLAGS_DID_BUILD_ID 0x02
#define FLAGS_DID_CORE 0x04
#define FLAGS_DID_CORE_STYLE 0x08
#define FLAGS_IS_CORE 0x10
#define NT_GNU_VERSION 1
#define NT_GNU_BUILD_ID 3
#define NT_NETBSD_PAX 1
#define NT_NETBSD_VERSION 1
#define NT_NETBSD_MARCH 2
#define NT_NETBSD_CMODEL 3
#define NT_FREEBSD_VERSION 1
#define NT_OPENBSD_VERSION 1
#define NT_DRAGONFLY_VERSION 1
#define NT_NETBSD_CORE_PROCINFO 1
#define NT_PRPSINFO 1
#define GNU_OS_LINUX 0
#define GNU_OS_HURD 1
#define GNU_OS_SOLARIS 2
#define GNU_OS_KFREEBSD 3
#define GNU_OS_KNETBSD 4
#define OS_STYLE_SVR4 0
#define OS_STYLE_FREEBSD 1
#define OS_STYLE_NETBSD 2
#define NOFFSETS 3

typedef struct {
    uint32_t n_namesz;
    uint32_t n_descsz;
    uint32_t n_type;
} Elf32_Nhdr;

typedef struct {
    uint32_t n_namesz;
    uint32_t n_descsz;
    uint32_t n_type;
} Elf64_Nhdr;

extern size_t xnh_sizeof;
extern void *xnh_addr;
extern uint32_t xnh_namesz;
extern uint32_t xnh_descsz;
extern uint32_t xnh_type;
extern const char *os_style_names[];
extern int file_printf(struct magic_set *, const char *, ...);
extern uint32_t elf_getu32(int, uint32_t);
extern size_t prpsoffsets(int);
extern void do_note_netbsd_version(struct magic_set *, int, void *);
extern void do_note_freebsd_version(struct magic_set *, int, void *);

#define __arraycount(a) (sizeof(a) / sizeof(a[0]))
#define private static