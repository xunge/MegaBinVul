#include <stdlib.h>
#include <string.h>

#define HDL_CGI(cgi_base) ((cherokee_handler_cgi_t *)(cgi_base))
#define ENV_VAR_NUM 1024
#define SHOULDNT_HAPPEN

typedef struct cherokee_handler_cgi_base_t cherokee_handler_cgi_base_t;
typedef struct cherokee_handler_cgi_t {
    char **envp;
    int envp_last;
} cherokee_handler_cgi_t;