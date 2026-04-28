#include <stdint.h>
#include <stddef.h>

#define CONFIG_LSM_MMAP_MIN_ADDR mmap_min_addr
extern unsigned long mmap_min_addr;

extern int selinux_checkreqprot;

struct file;
struct avc_has_perm;

typedef uint32_t u32;
typedef uint16_t u16;

u32 current_sid(void);
int avc_has_perm(u32 sid, u32 tsid, u16 tclass, u32 perms, struct avc_has_perm *avcp);
int cap_file_mmap(struct file *file, unsigned long reqprot, unsigned long prot, unsigned long flags, unsigned long addr, unsigned long addr_only);
int file_map_prot_check(struct file *file, unsigned long prot, int shared);

#define SECCLASS_MEMPROTECT 1
#define MEMPROTECT__MMAP_ZERO 1
#define MAP_TYPE 0x0f
#define MAP_SHARED 0x01