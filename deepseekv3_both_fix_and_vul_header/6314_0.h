#include <stddef.h>

#define FALSE 0
#define TRUE 1

#define FEAT_CMDL_INFO
#define FEAT_RIGHTLEFT
#define FEAT_VARTABS

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
} buf_T;

extern int p_paste;
extern int p_sm;
extern int p_sta;
extern int p_ru;
extern int p_ri;
extern int p_hkmap;
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
#ifdef FEAT_VARTABS
extern char *p_vsts;
extern char *p_vsts_nopaste;
extern char *empty_option;
#endif

#define FOR_ALL_BUFFERS(buf) for (buf = NULL; buf != NULL; buf = NULL)

void status_redraw_all(void);
void free_string_option(char *p);
void tabstop_set(char *p, int **array);
char *vim_strsave(const char *string);
void vim_free(void *p);