#include <stdlib.h>
#include <string.h>

typedef void pj_pool_t;

struct pjsip_hdr;
struct pjsip_generic_string_hdr {
    char *hvalue;
};

typedef struct pjsip_hdr pjsip_hdr;
typedef struct pjsip_generic_string_hdr pjsip_generic_string_hdr;

struct header_data {
    struct {
        struct {
            struct {
                struct {
                    pj_pool_t *pool;
                } *dlg;
            } *inv_session;
        } *session;
    } *channel;
    char *header_name;
    char *header_value;
    int header_number;
    struct {
        int type;
    } *header_datastore;
};

struct ast_datastore {
    void *data;
    int type;
};

struct hdr_list;

#define AST_LOG_ERROR 1

#define RAII_VAR(type, name, init, cleanup) \
    type name = (init)

static void ao2_cleanup(void **ptr) {
    if (*ptr) {
        free(*ptr);
    }
}

static int ast_log(int level, const char *format, ...) {
    return 0;
}

static void *ast_sip_session_get_datastore(void *session, int type) {
    return NULL;
}

static pjsip_hdr *find_header(struct hdr_list *list, const char *name, int number) {
    return NULL;
}

static void pj_strdup2(pj_pool_t *pool, char **dest, const char *src) {
    if (dest && src) {
        *dest = strdup(src);
    }
}