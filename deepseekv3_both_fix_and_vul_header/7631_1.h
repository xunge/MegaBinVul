#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <features.h>

#define EX_USAGE 1
#define MAX_ADDRESS_LEN 256
#define MAX_OPTIONS_LEN 4096
#define GMT_NAME_LEN 28
#define GMT_FORMAT "@GMT-%Y.%m.%d-%H.%M.%S"
#define NTFS_TIME_OFFSET 116444736000000000ULL

#define MS_USERS 0x10000000
#define MS_USER 0x20000000

enum opt_token {
    OPT_USERS,
    OPT_USER,
    OPT_PASS,
    OPT_SEC,
    OPT_IP,
    OPT_UNC,
    OPT_DOM,
    OPT_CRED,
    OPT_UID,
    OPT_CRUID,
    OPT_GID,
    OPT_FMASK,
    OPT_FILE_MODE,
    OPT_DMASK,
    OPT_DIR_MODE,
    OPT_NO_SUID,
    OPT_SUID,
    OPT_NO_DEV,
    OPT_NO_LOCK,
    OPT_MAND,
    OPT_NOMAND,
    OPT_DEV,
    OPT_NO_EXEC,
    OPT_EXEC,
    OPT_GUEST,
    OPT_RO,
    OPT_RW,
    OPT_REMOUNT,
    OPT_IGNORE,
    OPT_BKUPUID,
    OPT_BKUPGID,
    OPT_NOFAIL,
    OPT_SNAPSHOT
};

struct parsed_mount_info {
    char options[MAX_OPTIONS_LEN];
    unsigned long flags;
    char username[256];
    int got_user;
    int got_password;
    int is_krb5;
    char addrlist[MAX_ADDRESS_LEN];
    char domain[256];
    int got_domain;
    int verboseflag;
    int nofail;
    uid_t sudo_uid;
};

extern char *thisprogram;

static size_t strlcpy(char *dest, const char *src, size_t size);
static size_t strlcat(char *dest, const char *src, size_t size);
static enum opt_token parse_opt_token(const char *data);
static int set_password(struct parsed_mount_info *parsed_info, const char *value);
static int parse_unc(const char *value, struct parsed_mount_info *parsed_info, const char *thisprogram);
static int open_cred_file(const char *value, struct parsed_mount_info *parsed_info);