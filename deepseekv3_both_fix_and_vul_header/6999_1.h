#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define R_API

typedef struct r_list_t RList;

struct r_list_t {
    void (*free)(void *);
};

int r_cons_is_interactive(void);
void R_LOG_ERROR(const char *);
char *r_str_replace_ch(char *str, char ch1, char ch2, bool b);
RList *r_list_new(void);
bool r_list_append(RList *list, void *data);
void r_list_free(RList *list);
char *r_cons_hud(RList *list, void *user);