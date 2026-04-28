#include <stddef.h>

#define FALSE 0
#define TRUE 1

#ifdef FEAT_CMDL_INFO
extern int p_ru;
#endif
#ifdef FEAT_RIGHTLEFT
extern int p_ri;
extern int p_hkmap;
#endif
#ifdef FEAT_VARTABS
extern char *p_vsts;
extern char *p_vsts_nopaste;
extern char *empty_option;
#endif

extern int p_paste;
extern int p_sm;
extern int p_sta;
extern int p_ai;
extern int p_et;
extern int p_sts;
extern int p_tw;
extern int p_wm;
extern int p_ai_nopaste;
extern int p_et_nopaste;
extern int p_sts_nopaste;
extern int p_tw_nopaste;
extern int p_wm_nopaste;

typedef struct buf {
    int b_p_tw;
    int b_p_wm;
    int b_p_sts;
    int b_p_ai;
    int b_p_et;
    int b_p_tw_nopaste;
    int b_p_wm_nopaste;
    int b_p_sts_nopaste;
    int b_p_ai_nopaste;
    int b_p_et_nopaste;
#ifdef FEAT_VARTABS
    char *b_p_vsts;
    char *b_p_vsts_nopaste;
    int *b_p_vsts_array;
#endif
    struct buf *b_next;
} buf_T;

#define FOR_ALL_BUFFERS(buf) for (buf = first_buffer; buf != NULL; buf = buf->b_next)
extern buf_T *first_buffer;

#ifdef FEAT_VARTABS
extern void free_string_option(char *p);
extern char *vim_strsave(const char *string);
extern void vim_free(void *ptr);
extern int tabstop_set(char *var, int **array);
#endif

#ifdef FEAT_CMDL_INFO
extern void status_redraw_all(void);
#endif