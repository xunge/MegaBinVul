#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <libintl.h>

#define LONG_STRING 1024
#define PATH_MAX 4096
#define POP_CACHE_LEN 10
#define MUTT_PROGRESS_SIZE 100
#define NetInc 1

struct Context;
struct Message;
struct Progress;
struct PopData;
struct PopCache;
struct Header;
struct Envelope;

struct Context {
    void *data;
    struct Header **hdrs;
    void *subj_hash;
    int (*reopen)(struct Context *);
};

struct Message {
    FILE *fp;
};

struct Progress {
    char *msg;
    int size;
    int inc;
    int max;
};

struct PopData {
    void *bcache;
    struct PopCache *cache;
    char *err_msg;
};

struct PopCache {
    char *path;
    int index;
};

struct Header {
    void *data;
    int refno;
    int index;
    struct Content *content;
    struct Envelope *env;
    int lines;
    int security;
};

struct Content {
    long length;
    long offset;
};

struct Envelope {
    char *real_subj;
};

extern FILE *mutt_bcache_get(void *, void *);
extern FILE *mutt_bcache_put(void *, void *);
extern void mutt_bcache_commit(void *, void *);
extern void mutt_perror(const char *);
extern void mutt_error(const char *, ...);
extern void mutt_progress_init(struct Progress *, const char *, int, int, long);
extern int mutt_mktemp(char *, size_t);
extern FILE *mutt_file_fopen(const char *, const char *);
extern void mutt_file_fclose(FILE **);
extern char *mutt_str_strdup(const char *);
extern void mutt_hash_delete(void *, const char *, struct Header *);
extern void mutt_hash_insert(void *, const char *, struct Header *);
extern void mutt_label_hash_remove(struct Context *, struct Header *);
extern void mutt_label_hash_add(struct Context *, struct Header *);
extern void mutt_env_free(struct Envelope **);
extern struct Envelope *mutt_rfc822_read_header(FILE *, struct Header *, int, int);
extern int crypt_query(struct Content *);
extern void mutt_clear_error(void);
extern int pop_reconnect(struct Context *);
extern int pop_fetch_data(struct PopData *, const char *, struct Progress *, void *, FILE *);
extern int fetch_message(void *, const char *, size_t);

#define FREE(ptr) free(*(ptr)), *(ptr) = NULL
#define _(str) gettext(str)
#define WithCrypto 0