#include <stddef.h>

typedef unsigned char char_u;
#define GO_ALL ((char_u*)0)

typedef struct {
    void *os_varp;
    char *os_errbuf;
    size_t os_errbuflen;
    struct {
        char *string;
    } os_oldval;
} optset_T;

char *did_set_option_listflag(char_u *varp, char_u *flag, char *os_errbuf, ...);
void gui_init_which_components(char *string);