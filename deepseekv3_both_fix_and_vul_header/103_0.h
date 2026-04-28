#include <string.h>

typedef unsigned char char_u;
typedef struct spellinfo_S spellinfo_T;
typedef struct window_S win_T;

#define MAXWLEN 256
#define NUL '\0'
#define FAIL 1
#define OK 0
#define WF_BANNED 0
#define WF_KEEPCAP 0

struct spellinfo_S {
    void *si_foldroot;
    void *si_keeproot;
    int si_foldwcount;
    int si_keepwcount;
};

struct window_S {
    // dummy window structure
};

static int enc_utf8;
static win_T *curwin;

static int spell_casefold(win_T *wp, char_u *word, int len, char_u *foldword, int maxlen);
static int tree_add_word(spellinfo_T *spin, char_u *word, void *root, int flags, int region, int affixID);
static int captype(char_u *word, char_u *end);
static int utf_valid_string(char_u *s, char_u **endp);
#define STRLEN strlen