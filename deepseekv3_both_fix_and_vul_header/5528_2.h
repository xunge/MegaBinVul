#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <signal.h>
#include <unistd.h>

#define ARCHIVE_EXTRACT_NO_AUTODIR 0x0001
#define ARCHIVE_EXTRACT_NO_OVERWRITE_NEWER 0x0002
#define ARCHIVE_EXTRACT_SECURE_SYMLINKS 0x0004
#define ARCHIVE_EXTRACT_SECURE_NODOTDOT 0x0008
#define ARCHIVE_EXTRACT_SECURE_NOABSOLUTEPATHS 0x0010
#define ARCHIVE_EXTRACT_PERM 0x0020
#define ARCHIVE_EXTRACT_FFLAGS 0x0040
#define ARCHIVE_EXTRACT_ACL 0x0080
#define ARCHIVE_EXTRACT_OWNER 0x0100
#define ARCHIVE_EXTRACT_TIME 0x0200
#define ARCHIVE_OK 0
#define HAVE_SIGACTION 1
#define HAVE_SETLOCALE 1

#define OPTION_B64ENCODE 256
#define OPTION_GRZIP 257
#define OPTION_INSECURE 258
#define OPTION_LRZIP 259
#define OPTION_LZ4 260
#define OPTION_LZMA 261
#define OPTION_LZOP 262
#define OPTION_NO_PRESERVE_OWNER 263
#define OPTION_PASSPHRASE 264
#define OPTION_PRESERVE_OWNER 265
#define OPTION_QUIET 266
#define OPTION_UUENCODE 267
#define OPTION_VERSION 268

struct cpio {
    char *buff;
    size_t buff_size;
    int uid_override;
    int gid_override;
    char **argv;
    int argc;
    char mode;
    int verbose;
    char compress;
    int extract_flags;
    int bytes_per_block;
    char *filename;
    void *matching;
    int option_null;
    int option_append;
    int option_atime_restore;
    int option_follow_links;
    int option_link;
    int option_list;
    int option_numeric_uid_gid;
    int option_rename;
    int quiet;
    int dot;
    char *format;
    char *argument;
    char *uname_override;
    char *gname_override;
    void *gname_cache;
    void *uname_cache;
    char *destdir;
    void *ppbuff;
    int return_value;
    int add_filter;
    char *passphrase;
};

extern int cpio_getopt(struct cpio *);
extern void lafe_setprogname(char *, const char *);
extern void lafe_warnc(int, const char *, ...);
extern void lafe_errc(int, int, const char *, ...);
extern void usage(void);
extern void long_help(void);
extern void version(void);
extern const char *owner_parse(const char *, int *, int *);
extern void mode_out(struct cpio *);
extern void mode_list(struct cpio *);
extern void mode_in(struct cpio *);
extern void mode_pass(struct cpio *, const char *);
extern void free_cache(void *);
extern void passphrase_free(void *);
extern void *archive_match_new(void);
extern const char *archive_error_string(void *);
extern int archive_match_include_pattern(void *, const char *);
extern int archive_match_include_pattern_from_file(void *, const char *, int);
extern int archive_match_exclude_pattern(void *, const char *);
extern void archive_match_free(void *);