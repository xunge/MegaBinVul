#include <stddef.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0
#define NUL '\0'

typedef struct typval_S {
    int v_type;
    union {
        char *v_string;
        void *v_list;
    } vval;
} typval_T;

typedef struct term_S {
    void *tl_winpty_config;
    void *tl_winpty;
    int tl_cols;
    int tl_rows;
    void *tl_job;
    void *tl_out_fd;
    void *tl_vterm;
} term_T;

typedef struct jobopt_S {
    char *jo_cwd;
    void *jo_env;
    int jo_set;
    int jo_io_buf[2];
    int jo_set2;
    void *jo_ansi_colors;
    int jo_io[2];
    char *jo_io_name[2];
} jobopt_T;

typedef struct channel_S {
    int ch_write_text_mode;
} channel_T;

typedef struct job_S {
    void *jv_argv;
    int jv_in_buf;
    void *jv_channel;
    struct {
        void *hProcess;
        uint32_t dwProcessId;
    } jv_proc_info;
    void *jv_job_object;
    int jv_status;
    char *jv_tty_in;
    char *jv_tty_out;
    int jv_refcount;
} job_T;

typedef struct garray_S {
    void *ga_data;
    int ga_len;
} garray_T;

typedef char char_u;
typedef unsigned short short_u;
typedef int sock_T;
typedef uint32_t DWORD;
typedef void* HANDLE;
typedef unsigned short WCHAR;

#define VAR_STRING 0
#define VAR_LIST 1
#define FAIL 1
#define OK 0
#define JOB_STARTED 0
#define PART_IN 0
#define PART_OUT 1
#define JO_IN_BUF 0
#define JO2_ANSI_COLORS 0
#define JIO_FILE 0
#define WRITEBIN "wb"
#define WINPTY_MOUSE_MODE_FORCE 0
#define WINPTY_SPAWN_FLAG_AUTO_SHUTDOWN 0
#define WINPTY_SPAWN_FLAG_EXIT_AFTER_SHUTDOWN 0
#define GENERIC_WRITE 0
#define GENERIC_READ 0
#define OPEN_EXISTING 0

#define UNUSED
#define _(x) x
#define EMSG(x)
#define EMSG2(x, y)
#define ch_log(x, y, z)
#define e_invarg "E_invarg"
#define e_notopen "E_notopen"