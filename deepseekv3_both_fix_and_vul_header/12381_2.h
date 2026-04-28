#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

#define UNDO_HASH_SIZE 40
#define UF_START_MAGIC_LEN 12
#define UF_START_MAGIC "VIM UNDO FILE"
#define UF_VERSION 2
#define UF_VERSION_CRYPT 3
#define UF_HEADER_MAGIC 0x5f75
#define UF_HEADER_END_MAGIC 0xe7a5
#define UF_LAST_SAVE_NR 1
#define LONG_MAX 2147483647L
#define U_ALLOC_LINE malloc
#define CRYPT_BUF_SIZE 8192
#define FEAT_CRYPT 1
#define U_DEBUG 1
#define UNIX 1
#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define FAIL (-1)

typedef struct stat stat_T;

typedef struct {
    int method_nr;
} cryptstate_T;

typedef struct {
    void *bi_buf;
    FILE *bi_fp;
    cryptstate_T *bi_state;
    char_u *bi_buffer;
    int bi_avail;
    int bi_used;
} bufinfo_T;

typedef struct u_header {
    long uh_seq;
    struct {
        long seq;
        struct u_header *ptr;
    } uh_next, uh_prev, uh_alt_next, uh_alt_prev;
} u_header_T;

typedef struct {
    char_u *b_ffname;
    char_u *b_p_key;
    struct {
        linenr_T ml_line_count;
    } b_ml;
    struct {
        u_header_T *b_u_oldhead;
        u_header_T *b_u_newhead;
        u_header_T *b_u_curhead;
        char_u *b_u_line_ptr;
        linenr_T b_u_line_lnum;
        colnr_T b_u_line_colnr;
        long b_u_numhead;
        long b_u_seq_last;
        long b_u_seq_cur;
        time_t b_u_time_cur;
        long b_u_save_nr_last;
        long b_u_save_nr_cur;
        int b_u_synced;
    };
} buf_T;

extern buf_T *curbuf;
extern int p_verbose;
extern void verbose_enter();
extern void verbose_leave();
extern void smsg(char_u *msg, ...);
extern char_u *u_get_undo_file_name(char_u *name, int flag);
extern int mch_stat(char *name, stat_T *st);
extern uid_t getuid();
extern FILE *mch_fopen(char *name, char *mode);
extern void EMSG2(const char *msg, char_u *name);
extern void corruption_error(char *msg, char_u *name);
extern void give_warning(char_u *msg, int flag);
extern long get2c(FILE *fp);
extern int undo_read(bufinfo_T *bi, char_u *hash, size_t size);
extern long undo_read_4c(bufinfo_T *bi);
extern char_u *read_string_decrypt(bufinfo_T *bi, long len);
extern time_t undo_read_time(bufinfo_T *bi);
extern int undo_read_byte(bufinfo_T *bi);
extern int undo_read_2c(bufinfo_T *bi);
extern u_header_T *unserialize_uhp(bufinfo_T *bi, char_u *name);
extern void u_blockfree(buf_T *buf);
extern void u_free_uhp(u_header_T *uhp);
extern void vim_memset(void *s, int c, size_t n);
extern void vim_free(void *p);
extern void *alloc(size_t size);
extern void *alloc_clear(size_t size);
extern void EMSGN(const char *msg, long n);
extern void u_check(int flag);
extern void crypt_free_state(cryptstate_T *state);
extern cryptstate_T *crypt_create_from_file(FILE *fp, char_u *key);
extern int crypt_whole_undofile(int method_nr);
extern const char *_(const char *str);