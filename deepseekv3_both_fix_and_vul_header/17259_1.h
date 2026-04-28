#include <stddef.h>

typedef struct field_info {
    int length;
} field_info;

typedef struct proto_item proto_item;

#define PITEM_FINFO(pi) ((field_info *)NULL)