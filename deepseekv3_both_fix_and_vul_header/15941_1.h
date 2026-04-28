#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define WEECHAT_STRING_SPLIT_STRIP_LEFT  (1 << 0)
#define WEECHAT_STRING_SPLIT_STRIP_RIGHT (1 << 1)
#define WEECHAT_STRING_SPLIT_COLLAPSE_SEPS (1 << 2)

struct t_irc_server;
struct t_irc_channel {
    char *modes;
};

char irc_mode_get_chanmode_type(struct t_irc_server *server, char mode);
char *weechat_strndup(const char *string, size_t n);
char **weechat_string_split(const char *string, const char *separators,
                            int keep_eol, int flags, int max_items,
                            int *num_items);
void weechat_string_free_split(char **split_string);