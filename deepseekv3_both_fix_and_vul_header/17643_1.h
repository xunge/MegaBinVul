#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef int ret_t;

#define ENV_VAR_NUM 64
#define ret_ok 0

typedef struct cherokee_handler_t {
    ret_t (*read_post)(void);
    ret_t (*add_headers)(void);
    ret_t (*step)(void);
} cherokee_handler_t;

typedef struct cherokee_module_props_t cherokee_module_props_t;
typedef struct cherokee_module_t {
    ret_t (*init)(void);
    ret_t (*free)(void);
} cherokee_module_t;

typedef struct handler_cgi {
    cherokee_module_t module;
    cherokee_handler_t handler;
    int pipeInput;
    int pipeOutput;
    pid_t pid;
    int envp_last;
    char *envp[ENV_VAR_NUM];
} handler_cgi;

typedef struct cherokee_handler_cgi_base_t {
    cherokee_module_t module;
    cherokee_handler_t handler;
} cherokee_handler_cgi_base_t;

#define CHEROKEE_NEW_STRUCT(n, type) handler_cgi *n = (handler_cgi *)malloc(sizeof(handler_cgi))
#define HDL_CGI_BASE(h) ((cherokee_handler_cgi_base_t *)(h))
#define PLUGIN_INFO_HANDLER_PTR(type) NULL
#define HANDLER_PROPS(props) props
#define MODULE(h) (&((handler_cgi *)(h))->module)
#define HANDLER(h) (&((handler_cgi *)(h))->handler)

typedef ret_t (*module_func_init_t)(void);
typedef ret_t (*module_func_free_t)(void);
typedef ret_t (*handler_func_read_post_t)(void);
typedef ret_t (*handler_func_add_headers_t)(void);
typedef ret_t (*handler_func_step_t)(void);

ret_t cherokee_handler_cgi_base_init(cherokee_handler_cgi_base_t *hdl, void *cnt, void *info, 
                                   cherokee_module_props_t *props, 
                                   ret_t (*add_env_pair)(void), 
                                   ret_t (*read_from_cgi)(void));
ret_t cherokee_handler_cgi_init(void);
ret_t cherokee_handler_cgi_free(void);
ret_t cherokee_handler_cgi_read_post(void);
ret_t cherokee_handler_cgi_base_add_headers(void);
ret_t cherokee_handler_cgi_base_step(void);
ret_t cherokee_handler_cgi_add_env_pair(void);
ret_t read_from_cgi(void);