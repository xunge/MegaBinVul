#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAPOPT_CROSSDOMAINS 0
#define MAX_MAILBOX_BUFFER 1024
#define MAX_MAILBOX_NAME 1024
#define IMAP_MAILBOX_BADNAME 1

#define CYRUSDB_DONE 0
#define CYRUSDB_OK 0

#define MBNAME_INBOX 0
#define MBNAME_INBOXSUB 1
#define MBNAME_OWNER 2
#define MBNAME_ALTINBOX 3
#define MBNAME_ALTPREFIX 4
#define MBNAME_OTHERUSER 5
#define MBNAME_SHARED 6

#define NAMESPACE_USER 0
#define NAMESPACE_SHARED 1

typedef struct glob glob;
typedef struct ptrarray ptrarray;
typedef struct strarray_t strarray_t;
typedef struct namespace namespace;

struct ptrarray {
    int count;
    void **data;
};

struct glob {
    // glob implementation details
};

struct strarray_t {
    int count;
    const char **data;
};

struct namespace {
    char hier_sep;
    int isalt;
    const char *prefix[2];
    int accessible[2];
};

struct find_rock {
    const char *userid;
    int isadmin;
    struct namespace *namespace;
    void *db;
    int singlepercent;
    int mb_category;
    int (*proc)(void *, void *);
    void *procrock;
    struct ptrarray globs;
};

typedef int (*find_cb_t)(void *db, const char *key, size_t keylen, void *data, void *rock);
typedef int (*find_p_t)(void *db, const char *key, size_t keylen, void *data, void *rock);

int config_getswitch(int option);
int config_virtdomains;
void *xmalloc(size_t size);
int strlcpy(char *dst, const char *src, size_t size);
int snprintf(char *str, size_t size, const char *format, ...);
size_t strlen(const char *s);
char *strchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void free(void *ptr);

int cyrusdb_forone(void *db, const char *key, size_t keylen, find_p_t find_p, find_cb_t find_cb, void *rock, void *txn);
int cyrusdb_foreach(void *db, const char *key, size_t keylen, find_p_t find_p, find_cb_t find_cb, void *rock, void *txn);

int find_p(void *db, const char *key, size_t keylen, void *data, void *rock);
int find_cb(void *db, const char *key, size_t keylen, void *data, void *rock);

int mboxlist_find_category(struct find_rock *rock, const char *domainpat, size_t domainlen);

struct glob *glob_init(const char *pattern, char sep);
void glob_free(struct glob **g);
const char *strarray_nth(const struct strarray_t *sa, int i);
void ptrarray_append(struct ptrarray *pa, void *item);
void *ptrarray_nth(const struct ptrarray *pa, int i);
void ptrarray_fini(struct ptrarray *pa);

#define MIN(a, b) ((a) < (b) ? (a) : (b))