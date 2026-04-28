#include <stddef.h>
#include <errno.h>
#include <string.h>

struct kvm;
typedef unsigned long gfn_t;

#define __user
#define EFAULT 14

unsigned long gfn_to_hva(struct kvm *kvm, gfn_t gfn);
int kvm_is_error_hva(unsigned long addr);
long copy_from_user(void *to, const void *from, unsigned long n);