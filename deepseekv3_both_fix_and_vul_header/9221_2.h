#include <stdint.h>
#include <string.h>
#include <limits.h>

#define G_MAXUINT UINT_MAX
#define TRUE 1
#define FALSE 0

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef unsigned int guint;
typedef int gboolean;

typedef struct _packet_info {
    struct {
        guint32 num;
    } *fd;
    void *pool;
} packet_info;

typedef struct _wmem_tree_key_t {
    guint32 length;
    void *key;
} wmem_tree_key_t;

typedef struct _wmem_tree_t wmem_tree_t;

typedef struct {
    guint32 interface_id;
    guint32 adapter_id;
} bluetooth_data_t;

typedef struct {
    guint32 offset;
    guint32 length;
    guint8 *data;
    guint32 data_in_frame;
} fragment_data_t;

extern wmem_tree_t *fragments;
extern void *wmem_alloc(void *pool, size_t size);
extern void *wmem_tree_lookup32_array(wmem_tree_t *tree, wmem_tree_key_t *key);
extern void *wmem_tree_lookup32_le(wmem_tree_t *tree, guint32 frame_number);