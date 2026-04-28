#include <string.h>
#include <strings.h>

struct mailaddr {
    char user[256];
    char domain[256];
};

int text_to_mailaddr(struct mailaddr *maddr, const char *line);
int valid_localpart(const char *user);
int valid_domainpart(const char *domain);