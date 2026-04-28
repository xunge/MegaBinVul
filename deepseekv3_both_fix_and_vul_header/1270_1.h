#include <stddef.h>
#include <stdint.h>

#define MAXWLEN 256
#define NUL '\0'
#define FAIL 1
#define OK 0
#define TRUE 1

typedef int idx_T;
typedef unsigned char char_u;

struct spellinfo_S {
    void *si_foldroot;
    int si_sugtree;
    int si_blocks_cnt;
};

struct slang_S {
    char_u *sl_fbyts;
    idx_T *sl_fidxs;
    int sl_fbyts_len;
};

typedef struct spellinfo_S spellinfo_T;
typedef struct slang_S slang_T;

extern int got_int;
extern void line_breakcheck(void);
extern void smsg(const char *fmt, ...);
extern void *wordtree_alloc(spellinfo_T *spin);
extern int tree_add_word(spellinfo_T *spin, char_u *word, void *node, int flags, int region, int prefix);
extern void spell_soundfold(slang_T *slang, char_u *word, int foldcase, char_u *res);
extern const char *_(const char *str);