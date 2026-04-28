#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned int u32;

struct iscsi_param_list {
    /* dummy structure to make compilation work */
    int dummy;
};

struct iscsi_conn {
    struct iscsi_param_list *param_list;
};

struct iscsi_param {
    /* dummy structure to make compilation work */
    int dummy;
};

#define PHASE_SECURITY 0x01
#define GFP_KERNEL 0
#define IS_PSTATE_PROPOSER(param) (0)
#define SET_PSTATE_RESPONSE_GOT(param) do {} while (0)
#define SET_PSTATE_ACCEPTOR(param) do {} while (0)

#define kzalloc(size, flags) calloc(1, size)
#define kfree free
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define pr_debug(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

int iscsi_extract_key_value(char *start, char **key, char **value);
int iscsi_check_for_auth_key(char *key);
struct iscsi_param *iscsi_check_key(char *key, u8 phase, u8 sender, struct iscsi_param_list *param_list);
int iscsi_add_notunderstood_response(char *key, char *value, struct iscsi_param_list *param_list);
int iscsi_check_value(struct iscsi_param *param, char *value);
int iscsi_check_proposer_state(struct iscsi_param *param, char *value);
int iscsi_check_acceptor_state(struct iscsi_param *param, char *value, struct iscsi_conn *conn);