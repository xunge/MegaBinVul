#include <assert.h>
#include <stddef.h>

struct mm_struct;
struct security_operations {
    int (*vm_enough_memory)(struct mm_struct *, long);
};
extern struct security_operations *security_ops;

#define WARN_ON(condition) assert(!(condition))