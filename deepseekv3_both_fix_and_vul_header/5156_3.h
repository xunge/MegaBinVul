#include <stddef.h>

typedef void* HANDLE;
typedef unsigned char char_u;
typedef int sock_T;

typedef struct term term_T;
typedef struct job job_T;
typedef struct channel channel_T;
typedef struct buf buf_T;
typedef struct jobopt jobopt_T;

struct term {
    int tl_rows;
    int tl_cols;
    job_T *tl_job;
};

struct job {
    int jv_refcount;
    int jv_status;
    channel_T *jv_channel;
    char_u *jv_tty_in;
    char_u *jv_tty_out;
};

struct channel {
    int ch_keep_open;
    int ch_named_pipe;
};

struct buf {
    int b_fnum;
};

#define FAIL 1
#define OK 0
#define TRUE 1
#define FALSE 0
#define PIPE_ACCESS_OUTBOUND 0x00000002
#define PIPE_ACCESS_INBOUND 0x00000001
#define PIPE_TYPE_MESSAGE 0x00000004
#define PIPE_NOWAIT 0x00000001
#define PIPE_UNLIMITED_INSTANCES 255
#define NMPWAIT_NOWAIT 1
#define INVALID_HANDLE_VALUE ((HANDLE)((void*)-1))
#define JOB_FINISHED 2

extern buf_T *curbuf;

static int create_vterm(term_T *term, int rows, int cols);
static job_T *job_alloc(void);
static channel_T *add_channel(void);
static void channel_set_pipes(channel_T *channel, sock_T in, sock_T out, sock_T err);
static void channel_set_job(channel_T *channel, job_T *job, jobopt_T *options);
static char_u *vim_strsave(char_u *str);
static int vim_snprintf(char *str, size_t size, const char *format, ...);
static int GetCurrentProcessId(void);
static HANDLE CreateNamedPipe(const char* name, unsigned long dwOpenMode, 
                            unsigned long dwPipeMode, unsigned long nMaxInstances,
                            unsigned long nOutBufferSize, unsigned long nInBufferSize,
                            unsigned long nDefaultTimeOut, void* lpSecurityAttributes);
static int ConnectNamedPipe(HANDLE hNamedPipe, void* lpOverlapped);
static int CloseHandle(HANDLE hObject);