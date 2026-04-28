#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

struct ldb_context;
struct ldb_module;
struct ldb_dn;

typedef struct TALLOC_CTX TALLOC_CTX;

#define LDB_SUCCESS 0
#define LDB_ERR_COMPARE_TRUE 1
#define LDB_ERR_CONSTRAINT_VIOLATION 2
#define LDB_ERR_NO_SUCH_OBJECT 3

struct ldb_message {
    struct ldb_dn *dn;
};

struct samldb_ctx {
    struct ldb_module *module;
    struct ldb_message *msg;
};

struct ldb_message_element {
    unsigned int num_values;
    struct ldb_val *values;
};

struct ldb_val {
    uint8_t *data;
    size_t length;
};

#define DBG_INFO(fmt, ...) 
#define DBG_ERR(fmt, ...) 

static int ldb_oom(struct ldb_context *ldb) { return -1; }
static void ldb_asprintf_errstring(struct ldb_context *ldb, const char *fmt, ...) {}
static struct ldb_context *ldb_module_get_ctx(struct ldb_module *module) { return NULL; }
static int count_spn_components(struct ldb_val val) { return 0; }
static int check_spn_direct_collision(struct ldb_context *ldb, TALLOC_CTX *ctx, const char *spn, struct ldb_dn *dn) { return 0; }
static int check_spn_alias_collision(struct ldb_context *ldb, TALLOC_CTX *ctx, const char *spn, struct ldb_dn *dn) { return 0; }
static void *talloc_new(void *ctx) { return NULL; }
static void talloc_free(void *ptr) {}