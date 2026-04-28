#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint8_t ut8;

typedef struct r_bin_t {
    int (*cb_printf)(const char *format, ...);
} r_bin_t;

typedef struct RBinFile {
    r_bin_t *rbin;
    struct {
        size_t length;
    } *buf;
} RBinFile;

typedef struct {
    unsigned int class_offset;
    unsigned int data_offset;
    unsigned int data_size;
    unsigned int class_size;
    unsigned int types_size;
} dex_header_t;

typedef struct {
    int descriptor_id;
} dex_type_t;

typedef struct RBinDexObj {
    dex_header_t header;
    dex_type_t *types;
    void *classes_list;
} RBinDexObj;

typedef struct dex_class_data_item_t {
    int static_fields_size;
    int instance_fields_size;
    int direct_methods_size;
    int virtual_methods_size;
} dex_class_data_item_t;

typedef struct RBinDexClass {
    unsigned int access_flags;
    unsigned int interfaces_offset;
    unsigned int class_data_offset;
    unsigned int source_file;
    dex_class_data_item_t *class_data;
} RBinDexClass;

typedef struct RBinClass {
    char *name;
    int index;
    unsigned long addr;
    void *methods;
    void *fields;
} RBinClass;

extern int dexdump;
extern int kAccessForClass;

char *dex_class_name(RBinDexObj *bin, RBinDexClass *c);
char *r_str_replace(char *str, const char *key, const char *val, int g);
char *dex_class_super_name(RBinDexObj *bin, RBinDexClass *c);
char *getstr(RBinDexObj *bin, int tid);
char *createAccessFlagStr(int flags, int type);
const ut8 *r_buf_get_at(void *buf, int offset, void *unused);
int r_read_le32(const ut8 *p);
int r_read_le16(const ut8 *p);
const ut8 *r_uleb128(const ut8 *p, int len, int *v);
const ut8 *parse_dex_class_fields(RBinFile *binfile, RBinDexObj *bin, RBinDexClass *c, RBinClass *cls, const ut8 *p, const ut8 *p_end, int *sym_count, int size, bool is_static);
const ut8 *parse_dex_class_method(RBinFile *binfile, RBinDexObj *bin, RBinDexClass *c, RBinClass *cls, const ut8 *p, const ut8 *p_end, int *sym_count, int size, int *methods, bool is_direct);

typedef struct r_list_t {
    void *head;
} RList;

#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))
RList *r_list_new(void);
void r_list_free(RList *list);
void r_list_append(RList *list, void *data);

#define DEX_CLASS_SIZE 32