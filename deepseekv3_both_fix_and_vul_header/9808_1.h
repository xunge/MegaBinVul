#include <string.h>
#include <stddef.h>

struct page;
#define __user
#define KM_USER0 0
#define EFAULT 14

unsigned long s_copy_to_user;
unsigned long s_copy_from_user;

void rds_stats_add(unsigned long stat, unsigned long bytes);
void *kmap_atomic(struct page *page, int idx);
void kunmap_atomic(void *addr, int idx);
void *kmap(struct page *page);
void kunmap(struct page *page);
unsigned long __copy_to_user_inatomic(void __user *to, const void *from, unsigned long n);
unsigned long __copy_from_user_inatomic(void *to, const void __user *from, unsigned long n);
unsigned long copy_to_user(void __user *to, const void *from, unsigned long n);
unsigned long copy_from_user(void *to, const void __user *from, unsigned long n);