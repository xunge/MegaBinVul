#include <stdint.h>
#include <stddef.h>

typedef char *caddr_t;
typedef int dtp_t;
typedef int64_t int64;
typedef unsigned int db_buf_t;

typedef struct instruction {
    union {
        struct {
            int op;
            struct ha_op *distinct;
            struct ssl *result;
            struct ssl *arg;
            struct ssl *set_no;
        } agg;
    } _;
} instruction_t;

typedef struct query_instance {
    int qi_n_sets;
    db_buf_t qi_set_mask;
    int qi_set;
} query_instance_t;

typedef struct data_col {
    dtp_t dc_dtp;
    int dc_n_values;
    caddr_t *dc_values;
    struct {
        dtp_t sqt_dtp;
        int sqt_collation;
    } dc_sqt;
    int dc_any_null;
} data_col_t;

typedef struct ssl {
    int ssl_type;
    int ssl_index;
    struct {
        dtp_t sqt_dtp;
        int sqt_collation;
    } ssl_sqt;
} ssl;

typedef struct ha_op {
    int ha_op;
} ha_op;

typedef struct itc_ha_feed_ret {
    int ret;
} itc_ha_feed_ret_t;

#define QNCAST(type, var, ptr) type *var = (type *)(ptr)
#define QST_BOX(type, inst, idx) ((type)((inst) + (idx)))
#define SSL_IS_VEC_OR_REF(ssl) ((ssl)->ssl_type == 1 || (ssl)->ssl_type == 2)
#define SSL_CONSTANT 3
#define DV_LONG_INT 1
#define DV_DB_NULL 2
#define AMMSC_COUNT 1
#define AMMSC_COUNTSUM 2
#define AMMSC_SUM 3
#define AMMSC_MIN 4
#define AMMSC_MAX 5
#define AMMSC_ONE 6
#define HA_ORD_DISTINCT 1
#define DVC_MATCH 1
#define DVC_UNKNOWN 2
#define DVC_LESS 3
#define DVC_GREATER 4
#define SET_LOOP for (set = first_set; set < n_sets; set++)
#define END_SET_LOOP
#define DC_CHECK_LEN(res, set_no)
#define DC_ANY_IS_NULL(res, set_no) 0
#define DV_TYPE_OF(ptr) (*(dtp_t *)(ptr))

void ins_vec_agg_int_sum(instruction_t *ins, caddr_t *inst);
void ins_vec_agg_ord_distinct(instruction_t *ins, caddr_t *inst);
caddr_t qst_get(caddr_t *inst, struct ssl *ssl);
void qst_set(caddr_t *inst, struct ssl *ssl, caddr_t val);
void qst_vec_set_copy(caddr_t *inst, struct ssl *ssl, caddr_t val);
int64_t qst_vec_get_int64(caddr_t *inst, struct ssl *ssl, int set);
caddr_t box_copy_tree(caddr_t arg);
void box_add(caddr_t prev, caddr_t arg, caddr_t *inst, struct ssl *result);
int cmp_boxes(caddr_t arg, caddr_t prev, int coll1, int coll2);
void dc_set_null(data_col_t *res, int inx);
void dc_append_box(data_col_t *res, caddr_t val);
void VEC_QST_CLR_NULL(caddr_t *inst, struct ssl *ssl, int set);