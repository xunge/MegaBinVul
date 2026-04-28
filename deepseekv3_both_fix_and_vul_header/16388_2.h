#include <stdbool.h>
#include <stddef.h>

#define TRUE true
#define FALSE false

typedef struct {
    void* entities_using_map;
    void* coherent_set_registry_map;
} coherent_set_tracking_t;

typedef struct {
    int guid;
    int coherent_set_seq_number;
} coherent_set_key;

typedef struct {
    int guid;
    int coherent_set_seq_number;
    int expected_coherent_set_end_writers_seq_number;
    int writer_seq_number;
} coherent_set_entity_info;

typedef struct {
    bool is_set;
    int writer_seq_number;
} coherent_set_info;

extern coherent_set_tracking_t coherent_set_tracking;
extern void* wmem_map_lookup(void* map, const void* key);