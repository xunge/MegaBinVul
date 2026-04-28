#include <stddef.h>
#include <stdlib.h>

typedef enum {
    STF_OK,
    STF_FAIL,
    STF_FATAL,
    STF_SUSPEND,
    STF_INLINE
} stf_status;

enum {
    ISAKMP_NEXT_v2E = 0
};

enum {
    RESPONDER = 0
};

enum {
    RC_CRYPTOFAILED = 0
};

#define DBG_CONTROLMORE 0

struct pcrc {
    void (*pcrc_func)(void);
};

struct msg_digest {
    struct state *st;
    void **chain;
};

struct state {
    void *st_connection;
    void *st_import;
    struct {
        int groupnum;
    } st_oakley;
};

struct dh_continuation {
    struct msg_digest *md;
    struct pcrc dh_pcrc;
};

#define DBG(level, message) printf("%d: %s\n", level, message)
#define DBG_log(message) printf("%s\n", message)

void libreswan_log(const char *message);
void reset_globals(void);
void set_suspended(struct state *st, struct msg_digest *md);
void loglog(int code, const char *message);
void delete_state(struct state *st);
void pcrc_init(struct pcrc *pcrc);
void *alloc_thing(size_t size, const char *desc);
stf_status start_dh_v2(struct pcrc *pcrc, struct state *st, void *imp, int role, int groupnum);
void ikev2_parent_inI2outR2_continue(void);

#define alloc_thing(type, desc) malloc(sizeof(type))