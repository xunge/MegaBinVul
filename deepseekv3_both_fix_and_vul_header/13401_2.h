#include <stddef.h>
#include <setjmp.h>

typedef char *caddr_t;
typedef long ptrlong;
typedef long OFF_T;

#define QNCAST(type, var, ptr) type *var = (type *)(ptr)
#define QST_INT(inst, field) (*(int *)(inst[(int)(ptrlong)(field)]))
#define QST_GET(inst, field) (inst[(int)(ptrlong)(field)])
#define unbox(x) ((int)(ptrlong)(x))
#define qst_get(inst, field) (inst[(int)(ptrlong)(field)])
#define qst_set_long(inst, field, val) (inst[(int)(ptrlong)(field)] = (caddr_t)(long)(val))
#define PREFETCH_ALL 0
#define DV_ARRAY_OF_POINTER 0
#define QA_ROW 0
#define QA_ROW_LAST_IN_BATCH 0
#define PARTIAL 0
#define RST_AT_END 0
#define RST_ENOUGH 0
#define CALLER_CLIENT 0

typedef struct query_instance_t {
    int qi_lc;
    int qi_caller;
    struct client_t *qi_client;
    int qi_set;
    int qi_prefetch_bytes;
    int qi_bytes_selected;
    struct thread_t *qi_thread;
} query_instance_t;

typedef struct state_slot_t {
    int ssl_is_alias;
    struct state_slot_t *ssl_alias_of;
} state_slot_t;

typedef struct data_source_t {
    struct query_t *src_query;
    int src_out_fill;
    struct data_source_t *src_prev;
    caddr_t *src_state;
} data_source_t;

typedef struct select_node_t {
    struct data_source_t src_gen;
    int sel_out_quota;
    int sel_out_fill;
    int sel_top;
    int sel_top_skip;
    int sel_row_ctr;
    int sel_set_no;
    int sel_n_value_slots;
    state_slot_t **sel_out_slots;
    int sel_client_batch_start;
} select_node_t;

typedef struct session_t {
    OFF_T dks_bytes_sent;
} session_t;

typedef struct thread_t {
    jmp_buf thr_reset_ctx;
} thread_t;

typedef struct client_t {
    void *cli_session;
} client_t;

typedef struct query_t {
} query_t;

extern session_t *__ses;

void select_node_lc_input(select_node_t *sel, query_instance_t *qi, int n_rows, int top, int skip);
void sqlr_new_error(const char *code, const char *state, const char *message);
void dks_array_head(session_t *ses, int slots, int type);
void print_int(int val, session_t *ses);
void print_object(caddr_t value, session_t *ses, void *a, void *b);
void PRPC_ANSWER_START(thread_t *thread, int partial);
void PRPC_ANSWER_END(int code);
void subq_init(query_t *query, caddr_t *inst);
void SRC_RETURN(data_source_t *src, caddr_t *inst);
void longjmp_splice(jmp_buf env, int val);
#define SRC_IN_STATE(sel, inst) ((sel)->src_gen.src_state)