#include <sys/types.h>
#include <string.h>

typedef dev_t (*pack_t)(int, unsigned long[], const char**);
extern pack_t pack_find(const char *);
extern long mtree_atol(char **);

#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_ERRNO_FILE_FORMAT 0

struct archive;
int archive_set_error(struct archive *, int, const char *, ...);
char *la_strsep(char **, const char *);