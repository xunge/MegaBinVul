#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <limits.h>
#include <stdint.h>

typedef struct vdagent_file_xfers vdagent_file_xfers;
typedef struct VDAgentFileXferDataMessage VDAgentFileXferDataMessage;
typedef struct AgentFileXferTask AgentFileXferTask;

struct vdagent_file_xfers {
    int debug;
    int open_save_dir;
    char *save_dir;
    void *vdagentd;
    void *xfers;
};

struct VDAgentFileXferDataMessage {
    uint32_t id;
    void *data;
    size_t size;
};

struct AgentFileXferTask {
    int file_fd;
    uint32_t id;
    char *file_name;
    size_t read_bytes;
    size_t file_size;
    int file_xfer_nr;
    int file_xfer_total;
};

struct GError {
    char *message;
};

enum {
    VD_AGENT_FILE_XFER_STATUS_SUCCESS,
    VD_AGENT_FILE_XFER_STATUS_ERROR
};

enum {
    VDAGENTD_FILE_XFER_STATUS
};

static AgentFileXferTask *vdagent_file_xfers_get_task(vdagent_file_xfers *xfers, uint32_t id) {
    return NULL;
}

static void udscs_write(void *vdagentd, int type, uint32_t id, int status, void *data, size_t len) {
}

#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define GUINT_TO_POINTER(v) ((void*)(uintptr_t)(v))
#define g_hash_table_size(ht) 0
#define g_hash_table_remove(ht, key) 
#define g_error_free(err) 
#define g_spawn_async(wd, argv, envp, flags, setup, data, pid, error) 0
#define gchar char
#define GError struct GError
#define GSpawnFlags int
#define GSpawnChildSetupFunc void*
#define GPid int
#define G_SPAWN_SEARCH_PATH 0