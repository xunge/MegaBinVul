#include <stdlib.h>
#include <stdint.h>

#define PF_RANDOMIZE 0
#define ADDR_NO_RANDOMIZE 0
#define STACK_RND_MASK 0
#define PAGE_SHIFT 12
#define PAGE_SIZE 4096
#define PAGE_ALIGN(addr) ((addr) & ~(PAGE_SIZE-1))
#define CONFIG_STACK_GROWSUP 0

struct task_struct {
    unsigned long flags;
    unsigned long personality;
};

extern struct task_struct *current;

static unsigned int get_random_int(void) {
    return rand();
}