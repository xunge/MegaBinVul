#include <stdbool.h>
#include <string.h>

struct arpt_arp {
    // Add necessary fields here
    // Since the actual fields are unknown, we'll leave it empty
    // This will make sizeof() work but may not match real usage
};

struct arpt_entry {
    unsigned int target_offset;
    struct arpt_arp arp;
};