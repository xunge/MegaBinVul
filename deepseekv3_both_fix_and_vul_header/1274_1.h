#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

typedef mode_t __LA_MODE_T;

#define ARCHIVE_ACL_SUNOS_NFS4 0
#define ARCHIVE_ENTRY_ACL_TYPE_POSIX1E 0
#define ARCHIVE_ENTRY_ACL_TYPE_NFS4 1
#define ARCHIVE_ENTRY_ACL_TYPE_ACCESS 0
#define ARCHIVE_ENTRY_ACL_TYPE_DEFAULT 1
#define ARCHIVE_ENTRY_ACL_TYPE_ALLOW 2
#define ARCHIVE_ENTRY_ACL_TYPE_DENY 3
#define ARCHIVE_ENTRY_ACL_TYPE_AUDIT 4
#define ARCHIVE_ENTRY_ACL_TYPE_ALARM 5
#define ARCHIVE_ENTRY_ACL_USER 0
#define ARCHIVE_ENTRY_ACL_GROUP 1
#define ARCHIVE_ENTRY_ACL_USER_OBJ 2
#define ARCHIVE_ENTRY_ACL_GROUP_OBJ 3
#define ARCHIVE_ENTRY_ACL_MASK 4
#define ARCHIVE_ENTRY_ACL_OTHER 5
#define ARCHIVE_ENTRY_ACL_EVERYONE 6

#define ARCHIVE_OK 0
#define ARCHIVE_FAILED -1
#define ARCHIVE_WARN 1
#define ARCHIVE_ERRNO_MISC -1

#define SETACL 0
#define ACE_SETACL 1
#define USER 0x01
#define GROUP 0x02
#define USER_OBJ 0x04
#define GROUP_OBJ 0x08
#define CLASS_OBJ 0x10
#define OTHER_OBJ 0x20
#define ACL_DEFAULT 0x1000

#define ACE_ACCESS_ALLOWED_ACE_TYPE 0
#define ACE_ACCESS_DENIED_ACE_TYPE 1
#define ACE_SYSTEM_AUDIT_ACE_TYPE 2
#define ACE_SYSTEM_ALARM_ACE_TYPE 3
#define ACE_OWNER 0x1000
#define ACE_GROUP 0x2000
#define ACE_EVERYONE 0x4000
#define ACE_IDENTIFIER_GROUP 0x0040

struct archive;
struct archive_acl;
struct archive_acl *archive_acl_reset(struct archive_acl *, int);
int archive_acl_next(struct archive *, struct archive_acl *, int, int *, int *, int *, int *, const char **);
uid_t archive_write_disk_uid(struct archive *, const char *, int);
gid_t archive_write_disk_gid(struct archive *, const char *, int);
void archive_set_error(struct archive *, int, const char *, ...);

typedef struct {
    int a_id;
    int a_type;
    int a_perm;
} aclent_t;

typedef struct {
    int a_who;
    int a_access_mask;
    int a_flags;
    int a_type;
} ace_t;

typedef struct {
    int a_perm;
    int p_perm;
} acl_perm_map_t;

extern const acl_perm_map_t acl_posix_perm_map[];
extern const int acl_posix_perm_map_size;
#if ARCHIVE_ACL_SUNOS_NFS4
extern const acl_perm_map_t acl_nfs4_perm_map[];
extern const int acl_nfs4_perm_map_size;
extern const acl_perm_map_t acl_nfs4_flag_map[];
extern const int acl_nfs4_flag_map_size;
#endif

extern int facl(int fd, int cmd, int nentries, void *aclbufp);
extern int acl(const char *path, int cmd, int nentries, void *aclbufp);