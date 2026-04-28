#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>

#define NUL '\0'
#define GETF_SETMARK 1
#define FDO_TAG 1
#define IOSIZE 1024

typedef unsigned char char_u;

#define FALSE 0
#define TRUE 1
#define MAXCOL 1000
#define TAGSTACKSIZE 20
#define FAIL 0
#define OK 1
#define NOTAGFILE 2

#define FEAT_CSCOPE
#define FEAT_EVAL
#define FEAT_QUICKFIX
#define FEAT_FOLDING

#define _(x) x
#define STRCMP strcmp
#define STRCAT strcat
#define VIM_CLEAR(x) memset(&(x), 0, sizeof(x))
#define CLEAR_POS(x) memset(x, 0, sizeof(*x))
#define FreeWild(n, m) free(m)
#define vim_strsave strdup
#define vim_strnsave strndup
#define vim_free free
#define emsg(x) fprintf(stderr, "%s\n", x)
#define semsg(x, ...) fprintf(stderr, x, __VA_ARGS__)
#define smsg printf
#define msg(x) printf("%s\n", x)
#define msg_attr(x, y) printf("%s\n", x)
#define give_warning(x, y) printf("WARNING: %s\n", x)
#define msg_scrolled 0
#define msg_silent 0
#define out_flush() fflush(stdout)
#define ui_delay(x, y) usleep(x)
#define setpcmark() 
#define check_cursor() 
#define foldOpenCursor() 
#define set_vim_var_string(x, y, z) 
#define vim_snprintf snprintf

typedef struct {
    int lnum;
    int col;
} pos_T;

typedef struct {
    pos_T mark;
    int fnum;
} fmark_T;

typedef struct {
    char_u *tagname;
    int cur_match;
    int cur_fnum;
    fmark_T fmark;
    char_u *user_data;
} taggy_T;

typedef struct {
    char_u *tagname;
    int cur_match;
    int cur_fnum;
    char_u *user_data;
    char_u *user_data_end;
} tagptrs_T;

typedef struct {
    char *b_ffname;
    int b_fnum;
} buf_T;

typedef struct {
    taggy_T *w_tagstack;
    int w_tagstackidx;
    int w_tagstacklen;
    pos_T w_cursor;
    int w_set_curswant;
} win_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern char_u *tagmatchname;
extern char_u *nofile_fname;
extern int p_tgst;
extern int g_do_tagpreview;
extern int tfu_in_use;
extern int fdo_flags;
extern int KeyTyped;
extern int postponed_split;
extern int verbose;
extern int forceit;
extern int got_int;
extern int msg_scroll;

static char_u IObuff[IOSIZE];
static int num_matches = 0;
static int max_num_matches = 0;
static char_u **matches = NULL;
static int flags;

#define HL_ATTR(x) 0
#define HLF_W 0

#define e_cannot_modify_tag_stack_within_tagfunc "Cannot modify tag stack within tagfunc"
#define e_tag_stack_empty "Tag stack empty"
#define e_at_bottom_of_tag_stack "At bottom of tag stack"
#define e_at_top_of_tag_stack "At top of tag stack"
#define e_cannot_go_before_first_matching_tag "Cannot go before first matching tag"
#define e_tag_not_found_str "Tag not found: %s"
#define e_there_is_only_one_matching_tag "There is only one matching tag"
#define e_cannot_go_beyond_last_matching_tag "Cannot go beyond last matching tag"
#define e_file_str_does_not_exist "File %s does not exist"
#define e_window_unexpectedly_close_while_searching_for_tags "Window unexpectedly closed while searching for tags"

enum {
    DT_TAG,
    DT_POP,
    DT_NEXT,
    DT_PREV,
    DT_FIRST,
    DT_LAST,
    DT_SELECT,
    DT_JUMP,
    DT_HELP,
    DT_FREE,
    DT_CSCOPE,
    DT_LTAG
};

#define MT_IC_OFF 0x80
#define TAG_REGEXP 1
#define TAG_NOIC 2
#define TAG_CSCOPE 4
#define TAG_VERBOSE 8
#define TAG_NO_TAGFUNC 16

static taggy_T ptag_entry;

int find_tags(char_u *name, int *num_matches, char_u ***matches, int flags, int max_num_matches, char_u *buf_ffname);
int parse_match(char_u *match, tagptrs_T *tagp);
int jumpto_tag(char_u *match, int forceit, int verbose);
int buflist_getfile(int fnum, int lnum, int flags, int forceit);
void tagstack_clear_entry(taggy_T *entry);
void tag_freematch(void);
int add_llist_tags(char_u *tag, int num_matches, char_u **matches);
void cs_free_tags(void);
void cs_print_tags(void);
buf_T *buflist_findnr(int fnum);
void free_string_option(char_u *p);
int print_tag_list(int new_tag, int use_tagstack, int num_matches, char_u **matches);
int prompt_for_number(char *prompt);