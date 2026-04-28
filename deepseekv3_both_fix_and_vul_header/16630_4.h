#include <stdlib.h>
#include <string.h>

#define PJ_DEF(ret_type) ret_type
#define PJ_EINVAL (-1)
#define PJ_SUCCESS 0
#define PJ_POOL_ZALLOC_T(pool, type) ((type*)calloc(1, sizeof(type)))
#define PJ_ASSERT_RETURN(expr, retval) do { if (!(expr)) return (retval); } while(0)
#define PJ_LOG(level, args)

typedef int pj_status_t;
typedef void (*pjsip_send_callback)(void*);

typedef struct {
    struct {
        char *host;
        int count;
    } addr;
    struct {
        char *s;
        int slen;
    } name;
} pjsip_host_info;

typedef struct pjsip_send_state {
    void *token;
    void *endpt;
    void *tdata;
    pjsip_send_callback app_cb;
} pjsip_send_state;

typedef struct {
    void *pool;
    struct {
        struct {
            char *host;
            int count;
        } addr;
        struct {
            char *s;
            int slen;
        } name;
    } dest_info;
} pjsip_tx_data;

typedef struct pjsip_endpoint pjsip_endpoint;

extern pj_status_t pjsip_process_route_set(pjsip_tx_data *tdata, pjsip_host_info *dest_info);
extern void pjsip_endpt_resolve(pjsip_endpoint *endpt, void *pool, pjsip_host_info *dest_info,
                               pjsip_send_state *state, void (*cb)(pj_status_t, pjsip_send_state*, const pjsip_host_info*));
extern void stateless_send_resolver_callback(pj_status_t status, pjsip_send_state *state, const pjsip_host_info *info);
extern char* pjsip_tx_data_get_info(pjsip_tx_data *tdata);
extern void pj_strdup(void *pool, void *dest, void *src);