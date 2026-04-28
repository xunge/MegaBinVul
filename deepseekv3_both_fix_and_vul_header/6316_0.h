#include <stdlib.h>

#ifdef FEAT_CLIPBOARD
extern int check_clipboard_option(void);
#endif
#ifdef FEAT_VARTABS
extern void vim_free(void *ptr);
extern void tabstop_set(char *var, char **array);
#endif

extern int highlight_changed(void);
extern void check_opt_wim(void);
extern int set_chars_option(void *win, char **opt);
extern struct window *curwin;
extern struct buffer *curbuf;
extern char *p_fcs;

struct window {
    char *w_p_lcs;
};

struct buffer {
#ifdef FEAT_VARTABS
    char *b_p_vsts;
    char *b_p_vsts_array;
    char *b_p_vts;
    char *b_p_vts_array;
#endif
};