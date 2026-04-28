#include <string.h>

typedef unsigned char char_u;
typedef unsigned long long_u;

typedef struct expand_T expand_T;
typedef struct hashitem_T hashitem_T;
typedef struct hashtab_T hashtab_T;
typedef struct dictvar dictvar;
typedef struct window window;
typedef struct tabpage tabpage;
typedef struct vimvar vimvar;
typedef struct buffer buffer;

struct expand_T {
    char_u *xp_pattern;
};

struct hashitem_T {
    char_u *hi_key;
};

struct hashtab_T {
    hashitem_T *ht_array;
    long_u ht_used;
};

struct dictvar {
    hashtab_T dv_hashtab;
};

struct buffer {
    dictvar *b_vars;
};

struct window {
    dictvar *w_vars;
    buffer *w_buffer;
};

struct tabpage {
    dictvar *tp_vars;
};

struct vimvar {
    char *vv_name;
};

extern hashtab_T globvarht;
extern vimvar vimvars[];
extern char_u *varnamebuf;
extern int varnamebuflen;
extern int VV_LEN;

#define HASHITEM_EMPTY(hi) ((hi)->hi_key == NULL)
#define STRNCMP(s1, s2, n) strncmp((const char *)(s1), (const char *)(s2), (n))
#define VIM_CLEAR(p) memset((p), 0, sizeof(*(p)))

extern window *prevwin_curwin(void);
extern window *prevwin;
extern window *curwin;
extern buffer *curbuf;
extern tabpage *curtab;
extern int is_in_cmdwin(void);

extern char_u *cat_prefix_varname(int prefix, char_u *name);