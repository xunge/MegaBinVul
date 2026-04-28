#include <stdlib.h>

typedef int x3f_return_t;
#define X3F_ARGUMENT_ERROR 1
#define X3F_OK 0

#define X3F_SECp 1
#define X3F_SECi 2
#define X3F_SECc 3

#define FREE(ptr) free(ptr)

typedef struct x3f_property_list_s x3f_property_list_t;
typedef struct x3f_image_data_s x3f_image_data_t;
typedef struct x3f_camf_s x3f_camf_t;

typedef struct {
    int size;
    struct {
        char *name_utf8;
        char *value_utf8;
    } *element;
} property_table_t;

struct x3f_property_list_s {
    property_table_t property_table;
    void *data;
};

struct x3f_image_data_s {
    void *huffman;
    void *tru;
    void *quattro;
    void *data;
};

typedef struct {
    int size;
    void *element;
} camf_entry_table_t;

struct x3f_camf_s {
    void *data;
    void *tree;
    void *decoded_data;
    camf_entry_table_t entry_table;
    property_table_t table;
};

typedef struct x3f_directory_entry_header_s {
    int identifier;
    union {
        x3f_property_list_t property_list;
        x3f_image_data_t image_data;
        x3f_camf_t camf;
    } data_subsection;
} x3f_directory_entry_header_t;

typedef struct x3f_directory_entry_s {
    x3f_directory_entry_header_t header;
} x3f_directory_entry_t;

typedef struct x3f_directory_section_s {
    int num_directory_entries;
    x3f_directory_entry_t *directory_entry;
} x3f_directory_section_t;

typedef struct x3f_s {
    x3f_directory_section_t directory_section;
} x3f_t;

void cleanup_huffman(void *h);
void cleanup_true(void *t);
void cleanup_quattro(void *q);
void cleanup_huffman_tree(void *t);
void free_camf_entry(void *e);