#include <sys/types.h>

#define ARCHIVE_OK 0
#define ARCHIVE_ACL_LIBRICHACL 0
#define ARCHIVE_ACL_LIBACL 0
#define ARCHIVE_ENTRY_ACL_TYPE_NFS4 0
#define ARCHIVE_ENTRY_ACL_TYPE_POSIX1E 0
#define ARCHIVE_ENTRY_ACL_TYPE_ACCESS 0
#define ARCHIVE_ENTRY_ACL_TYPE_DEFAULT 0

typedef int __LA_MODE_T;

struct archive;
struct archive_acl;

int set_richacl(struct archive *, int, const char *, struct archive_acl *, __LA_MODE_T, int, const char *);
int set_acl(struct archive *, int, const char *, struct archive_acl *, int, const char *);
int archive_acl_types(struct archive_acl *);