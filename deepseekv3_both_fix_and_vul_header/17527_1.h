#include <stdint.h>
#include <errno.h>

#define KEY_MAX 0x2ff
#define INPUT_KEYMAP_BY_INDEX 0x01
#define EINVAL 22

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct input_dev {
    unsigned int keycodesize;
    unsigned int keycodemax;
    void *keycode;
    unsigned long *keybit;
};

struct input_keymap_entry {
    unsigned int flags;
    unsigned int index;
    unsigned int keycode;
};

extern int input_scancode_to_scalar(const struct input_keymap_entry *ke, unsigned int *index);
extern unsigned int input_fetch_keycode(struct input_dev *dev, int index);

static inline void __set_bit(int nr, volatile unsigned long *addr) {
    addr[nr / (8 * sizeof(long))] |= (1UL << (nr % (8 * sizeof(long))));
}

static inline void __clear_bit(int nr, volatile unsigned long *addr) {
    addr[nr / (8 * sizeof(long))] &= ~(1UL << (nr % (8 * sizeof(long))));
}