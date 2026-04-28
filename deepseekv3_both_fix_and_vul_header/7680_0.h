#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWLEN 256
#define MAXPATHL 1024
#define NUL '\0'
#define FALSE 0
#define TRUE 1
#define SOME_VALID 0

#define SPELL_ADD_BAD 0
#define SPELL_ADD_RARE 1

typedef unsigned char char_u;

typedef struct buf_T {
    int b_orig_mode;
    struct {
        void *ml_mfp;
    } b_ml;
    int b_changed;
} buf_T;

typedef struct win_T {
    struct {
        char_u *b_p_spf;
    } *w_s;
} win_T;

extern win_T *curwin;
extern char_u *int_wordlist;
extern char NameBuff[MAXPATHL];
extern int enc_utf8;

#define _(x) x
#define e_illegal_character_in_word "E777: Illegal character in word"
#define e_option_str_is_not_set "E518: Unknown option: %s"
#define e_spellfile_does_not_have_nr_entries "E764: Spellfile doesn't have %d entries"
#define e_file_is_loaded_in_another_buffer "E766: File is loaded in another buffer"
#define e_cant_open_file_str "E482: Can't open file %s"

void init_spellfile(void);
buf_T *buflist_findname_exp(char_u *fname);
int bufIsChanged(buf_T *buf);
void vim_free(void *ptr);
void *alloc(int size);
void copy_option_part(char_u **spf, char_u *fnamebuf, int maxlen, const char *delim);
int vim_fgets(char_u *line, int maxlen, FILE *fd);
void home_replace(void *unused, char_u *fname, char *NameBuff, int maxlen, int flag);
void smsg(const char *fmt, ...);
void semsg(const char *fmt, ...);
void emsg(const char *msg);
void PERROR(const char *msg);
char_u *vim_tempname(int c, int unused);
int dir_of_file_exists(char_u *fname);
char_u *gettail_sep(char_u *fname);
void vim_mkdir(char_u *name, int mode);
void mkspell(int count, char_u **fnames, int ascii, int overwrite, int added_word);
void buf_reload(buf_T *buf, int orig_mode, int message);
void redraw_all_later(int type);
FILE *mch_fopen(const char *fname, const char *mode);
int utf_valid_string(char_u *s, char_u **endp);
#define STRNCMP strncmp