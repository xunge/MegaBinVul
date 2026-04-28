#include <stdio.h>
#include <string.h>

#define STREQ(a, b) (strcmp((a), (b)) == 0)

struct tac_id {
    char *username;
    char *NAS_name;
    char *NAS_ip;
    char *NAS_port;
    char *NAC_address;
    int priv_lvl;
};

struct author_data {
    struct tac_id *id;
    int authen_method;
    int authen_type;
    int service;
    int status;
};

enum {
    AUTHOR_STATUS_PASS_ADD,
    AUTHOR_STATUS_PASS_REPL,
    AUTHOR_STATUS_FAIL,
    AUTHOR_STATUS_ERROR
};

extern char *tac_strdup(const char *str);
extern int is_valid_name(const char *name);