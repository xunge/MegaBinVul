#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

struct dump_dir {
    char *dd_dirname;
};

struct problem_item {
    char *content;
    int flags;
};

typedef struct problem_data_t problem_data_t;

#define FILENAME_ANALYZER "analyzer"
#define FILENAME_UID "uid"
#define NEW_PD_SUFFIX ".new"
#define LOCALSTATEDIR "/var"
#define LARGE_DATA_TMP_DIR "/tmp"
#define DEFAULT_DUMP_DIR_MODE 0755
#define CD_FLAG_BIN (1 << 0)

#define INITIALIZE_LIBREPORT()
#define error_msg(...)
#define perror_msg(...)
#define log_info(...)
#define iso_date_string(...) ""
#define xasprintf(...) NULL
#define concat_path_file(...) NULL
#define copy_file(...) -1
#define dd_save_text(...)
#define dd_create_basic_files(...)
#define dd_rename(...)
#define try_dd_create(...) NULL
#define problem_data_get_content_or_NULL(...) NULL

typedef struct {
    void *data;
    void (*free_func)(void *);
} GHashTableIter;

static inline void g_hash_table_iter_init(GHashTableIter *iter, void *hash_table) {}
static inline int g_hash_table_iter_next(GHashTableIter *iter, void **key, void **value) { return 0; }