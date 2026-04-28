#include <stddef.h>
#include <string.h>

#define PJSUA_INVALID_ID (-1)
#define PJ_ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define PJ_ASSERT_RETURN(expr, ret) do { if (!(expr)) return ret; } while(0)

typedef int pjsua_transport_id;

typedef struct {
    int type;
    union {
        void *tp;
        void *factory;
    } data;
} pjsua_transport_data;

typedef struct {
    pjsua_transport_data *tpdata;
} pjsua_var_t;

extern pjsua_var_t pjsua_var;

typedef struct {
    int type;
    union {
        void *transport;
        void *listener;
    } u;
} pjsip_tpselector;

#define PJSIP_TRANSPORT_DATAGRAM 0x01
#define PJSIP_TPSELECTOR_TRANSPORT 1
#define PJSIP_TPSELECTOR_LISTENER 2

static inline void pj_bzero(void *dst, size_t len) {
    memset(dst, 0, len);
}

unsigned pjsip_transport_get_flag_from_type(int type);