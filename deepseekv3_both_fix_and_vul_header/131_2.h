#include <string.h>
#include <stdlib.h>

typedef unsigned char char_u;

typedef struct typval_S {
    int dummy;
} typval_T;

typedef struct compl_S {
    char_u *cp_str;
    char_u *cp_fname;
    int cp_flags;
    int cp_number;
    char_u *cp_text[4];  // CPT_COUNT is 4
    struct compl_S *cp_next;
    struct compl_S *cp_prev;
    typval_T cp_user_data;
} compl_T;

#define UNUSED
#define FAIL 1
#define NOTDONE 2
#define OK 0
#define NUL '\0'
#define CP_FAST 0x01
#define CP_ORIGINAL_TEXT 0x02
#define CP_FREE_FNAME 0x04
#define CPT_COUNT 4
#define FORWARD 1
#define BACKWARD 2

static compl_T *compl_first_match = NULL;
static compl_T *compl_curr_match = NULL;
static int compl_direction = 0;
static int compl_get_longest = 0;
static int got_int = 0;

static int fast_breakcheck(void) { return 0; }
static int ui_breakcheck(void) { return 0; }
static int match_at_original_text(compl_T *match) { return 0; }
static int is_first_match(compl_T *match) { return 0; }
static void ins_compl_del_pum(void) {}
static char_u *vim_strnsave(char_u *str, int len) { return NULL; }
static char_u *vim_strsave(char_u *str) { return NULL; }
static void vim_free(void *ptr) {}
static void ins_compl_longest_match(compl_T *match) {}

#define STRLEN strlen
#define STRNCMP strncmp
#define STRCMP strcmp
#define ALLOC_CLEAR_ONE(type) (type *)calloc(1, sizeof(type))