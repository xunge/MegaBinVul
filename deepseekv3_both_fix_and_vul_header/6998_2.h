#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define R_API

typedef struct r_list_t RList;
struct r_list_t {
    void (*free)(void *);
};

int r_cons_is_interactive(void);
void R_LOG_ERROR(const char *msg);
void r_str_replace_ch(char *str, char a, char b, bool c);
RList *r_list_new(void);
bool r_list_append(RList *list, void *data);
void r_list_free(RList *list);
char *r_cons_hud_line(RList *list, void *user);