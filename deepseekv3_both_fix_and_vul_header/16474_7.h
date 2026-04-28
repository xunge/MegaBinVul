#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <errno.h>

#define FALSE false
#define TRUE true
typedef bool gboolean;

#define G_FILE_TEST_IS_DIR 1
#define G_FILE_TEST_IS_SYMLINK 2
#define G_FILE_TEST_EXISTS 4

typedef struct {
    char **envp;
    unsigned int shares;
    unsigned int devices;
    unsigned int sockets;
} FlatpakBwrap;

typedef struct {
    unsigned int shares;
    unsigned int devices;
    unsigned int sockets;
} FlatpakContext;

typedef struct {
    // empty struct for exports
} FlatpakExports;

typedef struct {
    char *message;
} GError;

typedef struct {
    // empty struct for cancellable
} GCancellable;

typedef struct {
    // empty struct for file
} GFile;

typedef struct {
    // empty struct for ptr array
} GPtrArray;

enum {
    FLATPAK_CONTEXT_SHARED_IPC = 1 << 0,
    FLATPAK_CONTEXT_SHARED_NETWORK = 1 << 1,
    FLATPAK_CONTEXT_DEVICE_ALL = 1 << 0,
    FLATPAK_CONTEXT_DEVICE_DRI = 1 << 1,
    FLATPAK_CONTEXT_DEVICE_KVM = 1 << 2,
    FLATPAK_CONTEXT_DEVICE_SHM = 1 << 3,
    FLATPAK_CONTEXT_SOCKET_WAYLAND = 1 << 0,
    FLATPAK_CONTEXT_SOCKET_FALLBACK_X11 = 1 << 1,
    FLATPAK_CONTEXT_SOCKET_X11 = 1 << 2,
    FLATPAK_CONTEXT_SOCKET_SSH_AUTH = 1 << 3,
    FLATPAK_CONTEXT_SOCKET_PULSEAUDIO = 1 << 4,
    FLATPAK_CONTEXT_SOCKET_PCSC = 1 << 5,
    FLATPAK_CONTEXT_SOCKET_CUPS = 1 << 6
};

typedef enum {
    FLATPAK_RUN_FLAG_NONE = 0
} FlatpakRunFlags;

#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof((arr)[0]))
#define flatpak_bwrap_empty_env false

static inline char* g_environ_getenv(char **envp, const char *name) {
    if (!envp) return NULL;
    for (; *envp; envp++) {
        char *eq = strchr(*envp, '=');
        if (eq && strncmp(*envp, name, eq - *envp) == 0)
            return eq + 1;
    }
    return NULL;
}

static inline int g_file_test(const char *path, int test) {
    struct stat st;
    if (stat(path, &st) != 0) return 0;
    
    if ((test & G_FILE_TEST_IS_DIR) && S_ISDIR(st.st_mode)) return 1;
    if ((test & G_FILE_TEST_IS_SYMLINK) && S_ISLNK(st.st_mode)) return 1;
    if (test & G_FILE_TEST_EXISTS) return 1;
    return 0;
}

static inline char* flatpak_readlink(const char *path, void *unused) {
    static char buf[PATH_MAX];
    ssize_t len = readlink(path, buf, sizeof(buf)-1);
    if (len == -1) return NULL;
    buf[len] = '\0';
    return buf;
}

static inline int g_strcmp0(const char *a, const char *b) {
    if (!a) return -(b != NULL);
    if (!b) return 1;
    return strcmp(a, b);
}

static inline int g_snprintf(char *str, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}

static inline void g_clear_error(GError **error) {
    if (error && *error) {
        free((*error)->message);
        free(*error);
        *error = NULL;
    }
}

static inline void* g_steal_pointer(void **pp) {
    void *ptr = *pp;
    *pp = NULL;
    return ptr;
}

static inline void g_debug(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputc('\n', stderr);
}

static inline void g_warning(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputc('\n', stderr);
}

static inline FlatpakBwrap* flatpak_bwrap_new(bool empty_env) {
    return calloc(1, sizeof(FlatpakBwrap));
}

static inline bool flatpak_bwrap_is_empty(FlatpakBwrap *bwrap) {
    return true;
}

static inline void flatpak_bwrap_add_args(FlatpakBwrap *bwrap, ...) {
    // dummy implementation
}

static inline void flatpak_bwrap_unset_env(FlatpakBwrap *bwrap, const char *name) {
    // dummy implementation
}

static inline bool flatpak_run_in_transient_unit(const char *app_id, GError **error) {
    return true;
}

static inline bool start_dbus_proxy(FlatpakBwrap *bwrap, FlatpakBwrap *proxy_arg_bwrap, 
                                  const char *app_info_path, GError **error) {
    return true;
}

static inline bool flatpak_run_add_wayland_args(FlatpakBwrap *bwrap) {
    return false;
}

static inline void flatpak_run_add_x11_args(FlatpakBwrap *bwrap, bool allow_x11) {
    // dummy implementation
}

static inline void flatpak_run_add_ssh_args(FlatpakBwrap *bwrap) {
    // dummy implementation
}

static inline void flatpak_run_add_pulseaudio_args(FlatpakBwrap *bwrap) {
    // dummy implementation
}

static inline void flatpak_run_add_pcsc_args(FlatpakBwrap *bwrap) {
    // dummy implementation
}

static inline void flatpak_run_add_cups_args(FlatpakBwrap *bwrap) {
    // dummy implementation
}

static inline void flatpak_run_add_session_dbus_args(FlatpakBwrap *bwrap, FlatpakBwrap *proxy_arg_bwrap,
                                                   FlatpakContext *context, FlatpakRunFlags flags,
                                                   const char *app_id) {
    // dummy implementation
}

static inline void flatpak_run_add_system_dbus_args(FlatpakBwrap *bwrap, FlatpakBwrap *proxy_arg_bwrap,
                                                  FlatpakContext *context, FlatpakRunFlags flags) {
    // dummy implementation
}

static inline void flatpak_run_add_a11y_dbus_args(FlatpakBwrap *bwrap, FlatpakBwrap *proxy_arg_bwrap,
                                                FlatpakContext *context, FlatpakRunFlags flags) {
    // dummy implementation
}

static inline void flatpak_context_append_bwrap_filesystem(FlatpakContext *context, FlatpakBwrap *bwrap,
                                                         const char *app_id, GFile *app_id_dir,
                                                         GPtrArray *previous_app_id_dirs,
                                                         FlatpakExports **exports) {
    // dummy implementation
}

#define g_autoptr(type) __attribute__((cleanup(free_ptr))) type *
#define g_autofree __attribute__((cleanup(free_ptr)))

static inline void free_ptr(void *p) {
    free(*(void**)p);
}