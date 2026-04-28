#include <stdlib.h>
#include <string.h>
#include <argp.h>

struct crun_global_arguments;
typedef int libcrun_error_t;

struct libcrun_container_exec_options_s {
    size_t struct_size;
    char *path;
    void *process;
    char *cgroup;
};

typedef struct {
    int preserve_fds;
    int listen_fds;
    int detach;
    char *console_socket;
    char *pid_file;
} libcrun_context_t;

typedef struct runtime_spec_schema_config_schema_process_capabilities {
    int *effective;
    int effective_len;
    int *inheritable;
    int inheritable_len;
    int *bounding;
    int bounding_len;
    int *ambient;
    int ambient_len;
    int *permitted;
    int permitted_len;
} runtime_spec_schema_config_schema_process_capabilities;

typedef struct runtime_spec_schema_config_schema_process {
    char **args;
    int args_len;
    char *cwd;
    int terminal;
    char **env;
    int env_len;
    void *user;
    char *selinux_label;
    char *apparmor_profile;
    runtime_spec_schema_config_schema_process_capabilities *capabilities;
    int no_new_privileges;
} runtime_spec_schema_config_schema_process;

struct {
    int detach;
    char *console_socket;
    char *pid_file;
    int preserve_fds;
    char *process;
    char *cwd;
    int tty;
    char **env;
    int env_size;
    void *user;
    char *process_label;
    char *apparmor;
    int *cap;
    int cap_size;
    int no_new_privs;
    char *cgroup;
} exec_options;

extern struct argp run_argp;
extern void *xmalloc0(size_t size);
extern char *xstrdup(const char *s);
extern void *xmalloc(size_t size);
extern int *dup_array(int *arr, int size);
extern void *make_oci_process_user(void *user);
extern int init_libcrun_context(libcrun_context_t *ctx, const char *arg, struct crun_global_arguments *global_args, libcrun_error_t *err);
extern int libcrun_container_exec_with_options(libcrun_context_t *context, const char *arg, struct libcrun_container_exec_options_s *opts, libcrun_error_t *err);
extern void crun_assert_n_args(int argc, int min, int max);
extern void free_process_schema(runtime_spec_schema_config_schema_process **process);

#define UNLIKELY(x) (x)
#define cleanup_process_schema __attribute__((cleanup(free_process_schema)))