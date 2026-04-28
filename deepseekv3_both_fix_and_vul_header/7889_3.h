#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

typedef uint32_t guint32;
typedef uint8_t guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

static int hf_s7comm_data_item = -1;
static int hf_s7comm_data_returncode = -1;
static int ett_s7comm_data_item = -1;

typedef struct {
    int value;
    const char *strptr;
} value_string;

static const value_string s7comm_item_return_valuenames[] = {
    {0, NULL}
};

#define ENC_NA 0

static const char* val_to_str(guint8 val, const value_string *vs, const char *fmt);