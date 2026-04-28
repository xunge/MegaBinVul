#include <stdlib.h>
#include <string.h>
#include <wchar.h>

struct cifsSesInfo {
    char *serverOS;
    char *serverNOS;
    char *serverDomain;
    unsigned int flags;
};

#define cFYI(level, format...) 
#define GFP_KERNEL 0
#define CIFS_SES_NT4 (1 << 0)

typedef unsigned short __le16;

static int UniStrnlen(const wchar_t *str, int maxlen);
static int cifs_strfromUCS_le(char *to, const __le16 *from, int len, const struct nls_table *cp);

void kfree(void *ptr);
void *kzalloc(size_t size, int flags);