#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define ML_EMPTY 0x01

typedef struct u_header u_header_T;

struct u_header {
    struct {
        u_header_T *ptr;
    } uh_next;
    struct {
        u_header_T *ptr;
    } uh_prev;
    struct {
        u_header_T *ptr;
    } uh_alt_next;
    struct {
        u_header_T *ptr;
    } uh_alt_prev;
    long uh_time;
    long uh_save_nr;
    long uh_seq;
    int uh_walk;
};

typedef struct {
    struct {
        int ml_flags;
    } b_ml;
    u_header_T *b_u_curhead;
    u_header_T *b_u_newhead;
    u_header_T *b_u_oldhead;
    long b_u_time_cur;
    long b_u_save_nr_cur;
    long b_u_save_nr_last;
    long b_u_seq_cur;
    long b_u_seq_last;
    int b_u_synced;
} buf_T;

extern buf_T *curbuf;
extern int lastmark;
extern int got_int;
extern long u_newcount;
extern long u_oldcount;

void u_sync(int);
void u_undoredo(int);
void u_undo_end(int, int);
void change_warning(int);
long vim_time(void);
void msg(const char *);
void semsg(const char *, long);
void internal_error(const char *);
const char *_(const char *);
#define e_undo_number_nr_not_found "e_undo_number_nr_not_found"