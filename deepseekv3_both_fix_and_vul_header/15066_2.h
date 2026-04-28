#include <stddef.h>
#include <string.h>

#define GFP_ATOMIC 0
#define CONFIG_COMPAT_VDSO 1
#define FIX_VDSO 0
#define PAGE_READONLY 0
#define X86_FEATURE_SEP 0
#define __init

void *syscall_page;
struct page { int unused; };
struct page *syscall_pages[1];
unsigned long vsyscall_int80_start;
unsigned long vsyscall_int80_end;
unsigned long vsyscall_sysenter_start;
unsigned long vsyscall_sysenter_end;

void *get_zeroed_page(int flags);
struct page *virt_to_page(void *addr);
void __set_fixmap(int idx, unsigned long phys, unsigned long flags);
unsigned long __pa(void *addr);
unsigned long __fix_to_virt(int idx);
int printk(const char *fmt, ...);
int boot_cpu_has(int feature);