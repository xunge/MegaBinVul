#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

struct bfd {
    struct bfd *archive_head;
    struct bfd *archive_next;
    bfd_boolean has_armap;
    bfd_boolean is_thin_archive;
    unsigned int flags;
    const char *target;
    const char *(*get_filename)(struct bfd *);
    const char *(*get_target)(struct bfd *);
    int (*get_format)(struct bfd *);
    int (*set_format)(struct bfd *, int);
    struct bfd *(*openr_next_archived_file)(struct bfd *, struct bfd *);
    int (*close)(struct bfd *);
    int (*stat_arch_elt)(struct bfd *, struct stat *);
    int (*check_format)(struct bfd *, int);
    int (*get_arch)(struct bfd *);
};

typedef struct bfd bfd;

typedef struct {
    const char *name;
} bfd_arch_info_type;

#define STRIP_ALL 1
#define BFD_DETERMINISTIC_OUTPUT (1 << 0)
#define bfd_object 1
#define bfd_arch_unknown 0

extern int status;
extern int strip_symbols;
extern int deterministic;
extern int preserve_dates;
extern const char *output_target;
extern bfd_boolean force_output_target;
extern const bfd_arch_info_type *input_arch;

extern char *make_tempdir(const char *);
extern void fatal(const char *, ...);
extern void non_fatal(const char *, ...);
extern void bfd_nonfatal_message(const char *, bfd *, const char *, const char *);
extern bfd_boolean copy_object(bfd *, bfd *, const bfd_arch_info_type *);
extern bfd_boolean copy_unknown_object(bfd *, bfd *);
extern void set_times(const char *, const struct stat *);
extern void *xmalloc(size_t);
extern char *concat(const char *, const char *, const char *, char *);