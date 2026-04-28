#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define HUGE_STRING 8192
#define USE_HCACHE
#define ReadInc 10
#define MUTT_PROGRESS_MSG 0

typedef unsigned int anum_t;

struct Context {
    void *data;
    int msgcount;
    int hdrmax;
    struct Header **hdrs;
    int quiet;
};

struct NntpData {
    char *group;
    struct NntpServer *nserv;
    void *bcache;
    int deleted;
    anum_t last_loaded;
};

struct NntpServer {
    int hasLISTGROUP;
    int hasLISTGROUPrange;
    int hasOVER;
    int hasXOVER;
};

struct Header {
    int index;
    bool read;
    bool old;
    bool deleted;
    bool changed;
    void *env;
    time_t received;
    time_t date_sent;
    void *data;
};

struct NntpHeaderData {
    anum_t article_num;
};

struct FetchCtx {
    struct Context *ctx;
    anum_t first;
    anum_t last;
    int restore;
    unsigned char *messages;
    void *hc;
    void *progress;
};

#define NHDR(h) ((struct NntpHeaderData *)(h)->data)

extern int NntpListgroup;
extern int mutt_bcache_del(void *bcache, const char *str);
extern void *mutt_hcache_fetch(void *hc, const char *str, size_t len);
extern void mutt_hcache_free(void *hc, void **data);
extern void mutt_hcache_delete(void *hc, const char *str, size_t len);
extern struct Header *mutt_hcache_restore(void *data);
extern void mutt_header_free(struct Header **hdr);
extern struct Header *mutt_header_new(void);
extern void *mutt_mem_calloc(size_t nmemb, size_t size);
extern void mutt_debug(int level, const char *fmt, ...);
extern void mutt_error(const char *fmt, ...);
extern void mutt_clear_error(void);
extern void mutt_message(const char *fmt, ...);
extern void mutt_perror(const char *s);
extern FILE *mutt_file_mkstemp(void);
extern void mutt_file_fclose(FILE **fp);
extern void *mutt_rfc822_read_header(FILE *fp, struct Header *hdr, int flags, int weed);
extern void mx_alloc_memory(struct Context *ctx);
extern void mx_update_context(struct Context *ctx, int count);
extern void mutt_progress_init(void *progress, const char *msg, int type, int inc, size_t count);
extern void mutt_progress_update(void *progress, int pos, int percent);
extern int nntp_fetch_lines(struct NntpData *nntp_data, char *buf, size_t buflen, void *data, int (*callback)(void *, char *), void *arg);
extern int fetch_numbers(void *vctx, char *line);
extern int fetch_tempfile(void *vctx, char *line);
extern int parse_overview_line(void *vctx, char *line);
extern void nntp_article_status(struct Context *ctx, struct Header *hdr, char *group, anum_t anum);
extern void nntp_parse_xref(struct Context *ctx, struct Header *hdr);
extern void FREE(void **ptr);
extern const char *_(const char *str);
extern int mutt_str_strncmp(const char *a, const char *b, size_t len);