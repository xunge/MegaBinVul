#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff tvbuff_t;
typedef uint64_t guint64;

typedef struct {
    uint64_t high;
    uint64_t low;
} GUID;

typedef struct {
    GUID guid;
    guint64 coherent_set_seq_number;
    guint64 writer_seq_number;
    guint64 expected_coherent_set_end_writers_seq_number;
} coherent_set_entity_info;

typedef struct {
    GUID guid;
    guint64 coherent_set_seq_number;
} coherent_set_key;

typedef struct {
    coherent_set_key* key;
    guint64 writer_seq_number;
    bool is_set;
} coherent_set_info;

typedef struct {
    void* entities_using_map;
    void* coherent_set_registry_map;
} coherent_set_tracking_t;

extern coherent_set_tracking_t coherent_set_tracking;
extern int hf_rtps_coherent_set_start;
extern int hf_rtps_coherent_set_end;

#define RTPS_SEQUENCENUMBER_UNKNOWN ((guint64)-1)
#define FALSE false
#define TRUE true

void* wmem_map_lookup(void* map, const void* key);
void* wmem_memdup(void* scope, const void* source, size_t size);
void* wmem_file_scope(void);
void wmem_map_insert(void* map, const void* key, void* val);
void* wmem_new0(void* scope, size_t size);
proto_item* proto_tree_add_uint64(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, guint64 value);
void proto_item_set_generated(proto_item* item);

// 修正类型声明
typedef proto_item* marked_item_tree_t;
typedef coherent_set_info* coherent_set_info_ptr_t;

// 修正wmem_new0调用方式
#define wmem_new0(scope, type) ((type*)wmem_new0(scope, sizeof(type)))