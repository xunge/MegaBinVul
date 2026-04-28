#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define MAXCOL 1000
#define TAGSTACKSIZE 20
#define NOTAGFILE -1
#define FAIL -1
#define OK 0
#define NUL '\0'
#define GETF_SETMARK 1

typedef unsigned char char_u;

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
} taggy_entry_T;

typedef struct {
    char_u *b_ffname;
    int b_fnum;
} buf_T;

typedef struct {
    taggy_T *w_tagstack;
    int w_tagstackidx;
    int w_tagstacklen;
    pos_T w_cursor;
    int w_set_curswant;
} win_T;

typedef struct {
    char_u *tagname;
    char_u *tagname_end;
    char_u *fname;
    char_u *fname_end;
    char_u *command;
    char_u *command_end;
    char_u *user_data;
    char_u *user_data_end;
} tagptrs_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern int p_tgst;
extern int KeyTyped;
extern int fdo_flags;
extern int postponed_split;
extern int g_do_tagpreview;
extern int tfu_in_use;
extern char_u *tagmatchname;
extern char_u *nofile_fname;
extern char_u *IObuff;
extern int msg_scrolled;
extern int msg_silent;
extern int got_int;
extern int msg_scroll;

#define MT_IC_OFF 0x80
#define TAG_REGEXP 1
#define TAG_NOIC 2
#define TAG_CSCOPE 4
#define TAG_VERBOSE 8
#define TAG_NO_TAGFUNC 16

#define DT_TAG 0
#define DT_POP 1
#define DT_NEXT 2
#define DT_PREV 3
#define DT_FIRST 4
#define DT_LAST 5
#define DT_SELECT 6
#define DT_JUMP 7
#define DT_HELP 8
#define DT_FREE 9
#define DT_CSCOPE 10
#define DT_LTAG 11

#define HL_ATTR(x) (x)
#define HLF_W 0

#define VV_SWAPCOMMAND 0

#define _(x) x
#define e_tag_not_found_str "E426: tag not found: %s"
#define e_tag_stack_empty "E73: tag stack empty"
#define e_at_bottom_of_tag_stack "E555: at bottom of tag stack"
#define e_at_top_of_tag_stack "E556: at top of tag stack"
#define e_cannot_modify_tag_stack_within_tagfunc "E986: Cannot modify tag stack within tagfunc"
#define e_cannot_go_before_first_matching_tag "E425: Cannot go before first matching tag"
#define e_there_is_only_one_matching_tag "E427: There is only one matching tag"
#define e_cannot_go_beyond_last_matching_tag "E428: Cannot go beyond last matching tag"
#define e_file_str_does_not_exist "E429: File \"%s\" does not exist"

static taggy_entry_T ptag_entry;

static int num_matches = 0;
static int max_num_matches = 0;
static char_u **matches = NULL;
static int flags;

void tagstack_clear_entry(taggy_T *entry);
int find_tags(char_u *name, int *num_matches, char_u ***matches, int flags, int max_num_matches, char_u *buf_ffname);
int parse_match(char_u *match, tagptrs_T *tagp);
void FreeWild(int num_matches, char_u **matches);
int jumpto_tag(char_u *match, int forceit, int verbose);
void setpcmark(void);
void check_cursor(void);
void foldOpenCursor(void);
int buflist_getfile(int fnum, int lnum, int flags, int forceit);
buf_T *buflist_findnr(int fnum);
void free_string_option(char_u *p);
void emsg(char *msg);
void semsg(char *msg, char_u *str);
void smsg(char *msg, char_u *str);
void give_warning(char_u *msg, int hl);
void msg(char *msg);
void msg_attr(char *msg, int attr);
int prompt_for_number(int *mouse_used);
int add_llist_tags(char_u *tag, int num_matches, char_u **matches);
void cs_free_tags(void);
void cs_print_tags(void);
void tag_freematch(void);
void print_tag_list(int new_tag, int use_tagstack, int num_matches, char_u **matches);
void set_vim_var_string(int var, char_u *str, int len);
char_u *vim_strsave(char_u *str);
char_u *vim_strnsave(char_u *str, int len);
void vim_snprintf(char *str, size_t size, char *fmt, ...);
void out_flush(void);
void ui_delay(long msec, int ignoreinput);
#define CLEAR_POS(p) memset(p, 0, sizeof(pos_T))
#define VIM_CLEAR(p) do { if (p) { vim_free(p); (p) = NULL; } } while (0)
#define vim_free free
#define STRCMP strcmp
#define STRCAT strcat