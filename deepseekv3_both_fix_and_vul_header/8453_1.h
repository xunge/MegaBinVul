#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct archive;
struct archive_entry;

struct bsdtar {
    struct archive *matching;
    char **argv;
    const char *names_from_file;
    int option_null;
    void *cset;
    const char *filename;
    size_t bytes_per_block;
    const char *option_options;
    int option_ignore_zeros;
    const char *passphrase;
    int uid;
    int gid;
    const char *uname;
    const char *gname;
    int option_chroot;
    int option_stdout;
    int option_fast_read;
    int return_value;
    int verbose;
    int option_interactive;
};

struct progress_data {
    struct bsdtar *bsdtar;
    struct archive *archive;
    struct archive_entry *entry;
};

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1
#define ARCHIVE_WARN (-10)
#define ARCHIVE_RETRY (-20)
#define ARCHIVE_FATAL (-30)

#define ENV_READER_OPTIONS "TAR_READER_OPTIONS"
#define IGNORE_WRONG_MODULE_NAME "@archive_read_set_options@"

extern int archive_match_include_pattern(struct archive *, const char *);
extern const char *archive_error_string(struct archive *);
extern int archive_match_include_pattern_from_file(struct archive *, const char *, int);
extern struct archive *archive_read_new(void);
extern int archive_read_support_filter_all(struct archive *);
extern int archive_read_support_format_all(struct archive *);
extern int archive_read_set_options(struct archive *, const char *);
extern int archive_read_add_passphrase(struct archive *, const char *);
extern int archive_read_set_passphrase_callback(struct archive *, void *, int (*)(struct archive *, void *));
extern int archive_read_open_filename(struct archive *, const char *, size_t);
extern int archive_read_next_header(struct archive *, struct archive_entry **);
extern int archive_match_excluded(struct archive *, struct archive_entry *);
extern int archive_read_data_skip(struct archive *);
extern int archive_read_data_into_fd(struct archive *, int);
extern int archive_read_extract2(struct archive *, struct archive_entry *, struct archive *);
extern int archive_read_close(struct archive *);
extern void archive_read_free(struct archive *);
extern const char *archive_format_name(struct archive *);
extern const char *archive_filter_name(struct archive *, int);
extern void archive_clear_error(struct archive *);
extern void archive_entry_set_uid(struct archive_entry *, int);
extern void archive_entry_set_uname(struct archive_entry *, const char *);
extern void archive_entry_set_gid(struct archive_entry *, int);
extern void archive_entry_set_gname(struct archive_entry *, const char *);
extern const char *archive_entry_pathname(struct archive_entry *);
extern int archive_read_extract_set_progress_callback(struct archive *, void (*)(void *), void *);
extern int archive_match_path_unmatched_inclusions(struct archive *);

extern int lafe_errc(int, int, const char *, ...);
extern void lafe_warnc(int, const char *, ...);
extern int cset_read_support_filter_program(void *, struct archive *);
extern void do_chdir(struct bsdtar *);
extern void progress_func(void *);
extern int passphrase_callback(struct archive *, void *);
extern void safe_fprintf(FILE *, const char *, ...);
extern void list_item_verbose(struct bsdtar *, FILE *, struct archive_entry *);
extern int edit_pathname(struct bsdtar *, struct archive_entry *);
extern int yes(const char *, ...);