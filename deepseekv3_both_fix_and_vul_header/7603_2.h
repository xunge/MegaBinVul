#include <stdlib.h>
#include <string.h>

struct sc_context;

struct sc_card {
    struct sc_context *ctx;
};

struct sc_pkcs15_card {
    struct sc_card *card;
};

struct sc_file {
    int ef_structure;
    size_t size;
    size_t record_length;
    size_t record_count;
};

struct sc_path {
    unsigned char value[256];
    size_t len;
};

struct sc_pkcs15_object {
    void *data;
    struct {
        unsigned char *value;
        size_t len;
    } content;
};

struct sc_pkcs15_auth_info {
    struct {
        struct {
            int reference;
        } pin;
    } attrs;
    unsigned int auth_method;
};

struct sc_acl_entry {
    unsigned int key_ref;
    unsigned int method;
};

#define SC_ERROR_INVALID_ARGUMENTS 1
#define SC_SUCCESS 0
#define SC_ERROR_OUT_OF_MEMORY 2
#define SC_ERROR_RECORD_NOT_FOUND 3
#define SC_ERROR_SECURITY_STATUS_NOT_SATISFIED 4
#define SC_ERROR_INVALID_DATA 5
#define SC_ERROR_DATA_OBJECT_NOT_FOUND 6

#define SC_FILE_EF_TRANSPARENT 0
#define SC_RECORD_BY_REC_NR 0
#define SC_AC_OP_READ 0
#define SC_PKCS15_TYPE_AUTH_PIN 0

#define LOG_FUNC_CALLED(ctx)
#define LOG_TEST_RET(ctx, err, msg) return err
#define LOG_FUNC_RETURN(ctx, err) return err
#define sc_log(ctx, fmt, ...)

static void sc_file_free(struct sc_file *file) {}
static int sc_select_file(struct sc_card *card, struct sc_path *path, struct sc_file **file) { return 0; }
static int sc_read_binary(struct sc_card *card, int pos, unsigned char *buf, size_t len, int flags) { return 0; }
static int sc_read_record(struct sc_card *card, int rec, unsigned char *buf, size_t len, int flags) { return 0; }
static const struct sc_acl_entry *sc_file_get_acl_entry(struct sc_file *file, int op) { return NULL; }
static int sc_pkcs15_get_objects(struct sc_pkcs15_card *p15card, int type, struct sc_pkcs15_object **objs, int max_objs) { return 0; }
static int sc_pkcs15_verify_pin(struct sc_pkcs15_card *p15card, struct sc_pkcs15_object *pin_obj, const unsigned char *pin, size_t pin_len) { return 0; }
static void sc_format_path(const char *in_path, struct sc_path *path) {}