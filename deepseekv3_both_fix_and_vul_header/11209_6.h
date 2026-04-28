#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ImapData;

char *mutt_str_strdup(const char *str);
void imap_utf_encode(struct ImapData *idata, char **buf);
void imap_quote_string(char *dest, size_t dlen, const char *src, ...);
void FREE(char **ptr);