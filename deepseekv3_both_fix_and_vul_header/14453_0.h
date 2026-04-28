#include <string.h>

typedef unsigned char char_u;

struct growarray {
    int ga_itemsize;
    int ga_growsize;
    int ga_len;
    void *ga_data;
};

struct growarray ignore_error_list;

void ga_init2(struct growarray *gap, int itemsize, int growsize);
void ga_clear_strings(struct growarray *gap);
void ga_add_string(struct growarray *gap, char_u *str);

#define STRCMP strcmp