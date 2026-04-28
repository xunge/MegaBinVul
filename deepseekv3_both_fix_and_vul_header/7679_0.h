#include <string.h>

#define MAXWLEN 256
#define NUL '\0'
#define OK 1
#define FAIL 0
#define WF_KEEPCAP 0x01

typedef struct spellinfo_S spellinfo_T;
typedef unsigned char char_u;

struct spellinfo_S {
    void *si_foldroot;
    void *si_keeproot;
    int si_foldwcount;
    int si_keepwcount;
};

extern int enc_utf8;
extern struct window_S *curwin;

int captype(char_u *word, char_u *end);
int spell_casefold(struct window_S *win, char_u *word, int len, char_u *foldword, int maxlen);
int tree_add_word(spellinfo_T *spin, char_u *word, void *root, int flags, int region, int affix);
int utf_valid_string(char_u *s, char_u **endp);

#define STRLEN strlen