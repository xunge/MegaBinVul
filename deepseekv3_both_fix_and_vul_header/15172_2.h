#include <stdint.h>
#include <stddef.h>

struct file;

typedef uint32_t u32;
typedef uint16_t u16;

static u32 current_sid(void);
static int avc_has_perm(u32 ssid, u32 tsid, u16 tclass, u32 perms, void *auditdata);
static int file_map_prot_check(struct file *file, unsigned long prot, int shared);

extern unsigned long mmap_min_addr;
extern int selinux_checkreqprot;

#define SECCLASS_MEMPROTECT 1
#define MEMPROTECT__MMAP_ZERO 1
#define MAP_TYPE 0
#define MAP_SHARED 1