#include <stdio.h>
#include <stddef.h>

#define OUTPUT_VALUE_ONLY 0x01
#define OUTPUT_UDEV_LIST 0x02
#define OUTPUT_EXPORT_LIST 0x04

extern void print_udev_format(const char *name, const char *value);
extern void safe_print(const char *value, size_t valsz, const char *quote);