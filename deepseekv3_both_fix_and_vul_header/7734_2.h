#include <string.h>
#include <stddef.h>

struct razer_report {
    unsigned char arguments[80];
};

struct razer_report get_razer_report(unsigned char command_class, unsigned char command_id, unsigned char data_size);

#define KERN_ALERT ""