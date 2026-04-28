#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct sc_context_param {
    int ver;
    const char *app_name;
} sc_context_param_t;

typedef struct sc_card {
    int type;
} sc_card_t;

typedef struct sc_context sc_context_t;

extern char *app_name;
extern char *exec_program;
extern int opt_reader;
extern int opt_wait;
extern int exit_status;

extern void decode_options(int argc, char **argv);
extern int sc_context_create(sc_context_t **ctx, sc_context_param_t *param);
extern const char *sc_strerror(int err);
extern int util_connect_card(sc_context_t *ctx, sc_card_t **card, int reader, int wait, int verbose);
extern void do_esteid(sc_card_t *card);
extern void do_belpic(sc_card_t *card);
extern void sc_unlock(sc_card_t *card);
extern void sc_disconnect_card(sc_card_t *card);
extern void sc_release_context(sc_context_t *ctx);

#define SC_CARD_TYPE_MCRD_ESTEID_V30 1
#define SC_CARD_TYPE_BELPIC_EID 2