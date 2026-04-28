#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct {
    guint32 interface_id;
    guint32 adapter_id;
} bluetooth_data_t;

typedef union request_parameters_union {
    int dummy;
} request_parameters_union;

typedef struct {
    guint8 opcode;
    guint32 request_in_frame;
    guint32 response_in_frame;
    request_parameters_union parameters;
} request_data_t;

typedef struct {
    unsigned length;
    void *key;
} wmem_tree_key_t;

extern void *wmem_file_scope(void);
extern void *wmem_new(void *scope, size_t size);
extern void wmem_tree_insert32_array(void *tree, wmem_tree_key_t *key, void *data);

extern void *requests;

typedef struct packet_info {
    guint32 num;
    guint32 curr_layer_num;
} packet_info;

#define wmem_new(scope, type) ((type *)malloc(sizeof(type)))