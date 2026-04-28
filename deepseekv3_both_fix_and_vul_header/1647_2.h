#include <stddef.h>
#include <stdbool.h>

#define FALSE false
#define TRUE true

typedef struct buf_S buf_T;
typedef struct compl_S compl_T;
typedef struct gui_S {
    bool in_use;
} gui_T;

extern buf_T *curbuf;
extern compl_T *compl_shown_match;
extern char *compl_leader;
extern int compl_started;
extern bool compl_get_longest;
extern bool compl_restarting;
extern bool compl_used_match;
extern bool compl_no_insert;
extern char *compl_orig_text;
extern bool compl_enter_selects;
extern void **compl_match_array;
extern gui_T gui;

struct compl_S {
    char *cp_fname;
};

struct buf_S {
    // buffer fields
};

static int match_at_original_text(compl_T *match);
static void ins_compl_update_shown_match(void);
static void ins_compl_delete(void);
static int find_next_completion_match(int allow_get_expansion, int todo, bool advance, int *num_matches);
static int get_compl_len(void);
static void ins_bytes(char *text);
static void ins_compl_insert(int in_compl_func);
static void ins_compl_upd_pum(void);
static bool pum_enough_matches(void);
static void pum_call_update_screen(void);
static void update_screen(int flags);
static void ins_compl_show_pum(void);
static void setcursor(void);
static void out_flush_cursor(bool force, bool clear_selection);
static void ins_compl_show_filename(void);