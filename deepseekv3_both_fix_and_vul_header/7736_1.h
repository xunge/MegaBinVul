#include <stddef.h>
#include <string.h>

#define KERN_ALERT ""

struct transaction_id {
    unsigned char id;
};

struct razer_report {
    unsigned char arguments[80];
    struct transaction_id transaction_id;
};

struct razer_report get_razer_report(unsigned char command_class, unsigned char command_id, size_t data_length);

static inline int printk(const char *fmt, ...) {
    return 0;
}