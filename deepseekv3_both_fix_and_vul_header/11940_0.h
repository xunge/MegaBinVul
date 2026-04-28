#include <string.h>
#include <stdlib.h>

struct archive_acl;
struct archive_string_conv;

#define ARCHIVE_ENTRY_ACL_TYPE_POSIX1E 0
#define ARCHIVE_ENTRY_ACL_TYPE_ACCESS 1
#define ARCHIVE_ENTRY_ACL_TYPE_DEFAULT 2
#define ARCHIVE_ENTRY_ACL_TYPE_NFS4 3
#define ARCHIVE_ENTRY_ACL_TYPE_DENY 4
#define ARCHIVE_ENTRY_ACL_TYPE_ALLOW 5
#define ARCHIVE_ENTRY_ACL_TYPE_AUDIT 6
#define ARCHIVE_ENTRY_ACL_TYPE_ALARM 7

#define ARCHIVE_ENTRY_ACL_USER_OBJ 0
#define ARCHIVE_ENTRY_ACL_GROUP_OBJ 1
#define ARCHIVE_ENTRY_ACL_OTHER 2
#define ARCHIVE_ENTRY_ACL_MASK 3
#define ARCHIVE_ENTRY_ACL_USER 4
#define ARCHIVE_ENTRY_ACL_GROUP 5
#define ARCHIVE_ENTRY_ACL_EVERYONE 6

#define ARCHIVE_FATAL -1
#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1

#define __LA_FALLTHROUGH

void next_field(const char **text, const char **start, const char **end, char *sep);
int isint(const char *start, const char *end, int *result);
int ismode(const char *start, const char *end, int *permset);
int is_nfs4_perms(const char *start, const char *end, int *permset);
int is_nfs4_flags(const char *start, const char *end, int *permset);
int archive_acl_add_entry_len_l(struct archive_acl *acl, int type, int permset, int tag, int id, const char *name, size_t len, struct archive_string_conv *sc);
void archive_acl_reset(struct archive_acl *acl, int types);