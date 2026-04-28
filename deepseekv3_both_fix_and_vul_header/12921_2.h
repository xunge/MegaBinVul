#include <stddef.h>
#include <sys/types.h>

#define ARCHIVE_WRITE_MAGIC 0xbad1dea0
#define ARCHIVE_STATE_NEW 0
#define ARCHIVE_STATE_HEADER 1
#define ARCHIVE_WARN 0
#define ARCHIVE_FATAL 1

struct archive {
    int magic;
    int state;
};

struct archive_write {
    struct archive archive;
    void *client_data;
    void *client_writer;
    void *client_opener;
    void *client_closer;
    void *client_freer;
    int (*format_init)(struct archive_write *);
};

struct archive_write_filter {
    int (*open)(struct archive_write_filter *);
    ssize_t (*write)(struct archive_write_filter *, const void *, size_t);
    int (*close)(struct archive_write_filter *);
    int (*free)(struct archive_write_filter *);
};

typedef int (*archive_open_callback)(struct archive *, void *);
typedef ssize_t (*archive_write_callback)(struct archive *, void *, const void *, size_t);
typedef int (*archive_close_callback)(struct archive *, void *);
typedef int (*archive_free_callback)(struct archive *, void *);

void archive_check_magic(struct archive *, int, int, const char *);
void archive_clear_error(struct archive *);
struct archive_write_filter *__archive_write_allocate_filter(struct archive *);
int __archive_write_filters_open(struct archive_write *);
int __archive_write_filters_close(struct archive_write *);
void __archive_write_filters_free(struct archive *);
int archive_write_client_open(struct archive_write_filter *);
ssize_t archive_write_client_write(struct archive_write_filter *, const void *, size_t);
int archive_write_client_close(struct archive_write_filter *);
int archive_write_client_free(struct archive_write_filter *);