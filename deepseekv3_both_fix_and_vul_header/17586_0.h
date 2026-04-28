#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

#define SC_SUCCESS 0
#define SC_ERROR_INTERNAL 1
#define SC_ERROR_OUT_OF_MEMORY 2

#define COOLKEY_V1_OBJECT 0

typedef struct {
    unsigned char *value;
    size_t len;
} coolkey_path_t;

typedef struct {
    coolkey_path_t path;
    unsigned long id;
    size_t length;
    u8 *data;
} sc_cardctl_coolkey_object_t;

typedef struct {
    sc_cardctl_coolkey_object_t *objects_list;
} coolkey_private_data_t;

static coolkey_path_t coolkey_template_path;

static void ulong2bebytes(unsigned char *buf, unsigned long val);
static sc_cardctl_coolkey_object_t *coolkey_find_object_by_id(sc_cardctl_coolkey_object_t *list, unsigned long id);
static int coolkey_add_object_to_list(sc_cardctl_coolkey_object_t **list, sc_cardctl_coolkey_object_t *new_object);