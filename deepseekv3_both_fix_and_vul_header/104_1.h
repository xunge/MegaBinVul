#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define MAXWLEN 256
#define MAXPATHL 1024
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

int utf_valid_string(char_u *s, char_u **endp);
void emsg(const char *msg);
void semsg(const char *msg, ...);
void smsg(const char *msg, ...);
void PERROR(const char *msg);
void vim_free(void *ptr);
void *alloc(size_t size);
void copy_option_part(char_u **spf, char_u *fnamebuf, int maxlen, const char *sep);
buf_T *buflist_findname_exp(char_u *fname);
int bufIsChanged(buf_T *buf);
void buf_reload(buf_T *buf, int mode, int force);
void redraw_all_later(int flags);
void mkspell(int count, char_u **fnames, int ascii, int overwrite, int added_word);
int vim_fgets(char_u *line, int size, FILE *fd);
int dir_of_file_exists(char_u *fname);
char_u *gettail_sep(char_u *fname);
void vim_mkdir(char_u *name, int mode);
char_u *vim_tempname(int c, int suppress);
void init_spellfile(void);
FILE *mch_fopen(const char *name, const char *mode);
void home_replace(void *unused, char_u *fname, char *buff, int len, int flag);
int STRNCMP(const char_u *s1, const char_u *s2, size_t n);

const char *e_illegal_character_in_word;
const char *e_option_str_is_not_set;
const char *e_spellfile_does_not_have_nr_entries;
const char *e_file_is_loaded_in_another_buffer;
const char *e_cant_open_file_str;