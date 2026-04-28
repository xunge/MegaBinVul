#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

typedef unsigned int rpm_mode_t;
typedef unsigned int rpm_rdev_t;
typedef unsigned int rpmVerifyAttrs;
typedef unsigned int rpmfileAttrs;

#define RPMVERIFY_NONE 0
#define RPMVERIFY_LSTATFAIL (1 << 0)
#define RPMVERIFY_FILEDIGEST (1 << 1)
#define RPMVERIFY_FILESIZE (1 << 2)
#define RPMVERIFY_MTIME (1 << 3)
#define RPMVERIFY_RDEV (1 << 4)
#define RPMVERIFY_MODE (1 << 5)
#define RPMVERIFY_LINKTO (1 << 6)
#define RPMVERIFY_USER (1 << 7)
#define RPMVERIFY_GROUP (1 << 8)
#define RPMVERIFY_CAPS (1 << 9)
#define RPMVERIFY_READFAIL (1 << 10)
#define RPMVERIFY_READLINKFAIL (1 << 11)
#define RPMVERIFY_FAILURES (1 << 12)

#define RPMFILE_STATE_NETSHARED 0
#define RPMFILE_STATE_NOTINSTALLED 1
#define RPMFILE_STATE_REPLACED 2
#define RPMFILE_STATE_WRONGCOLOR 3
#define RPMFILE_STATE_NORMAL 4
#define RPMFILE_STATE_MISSING 5

#define RPMFILE_GHOST (1 << 0)

#define S_ISDEV(m) (S_ISCHR(m) || S_ISBLK(m))

typedef long long rpm_loff_t;

struct rpmfiles_s;
typedef struct rpmfiles_s * rpmfiles;

int rpmDoDigest(int algo, const char *fn, int unused, unsigned char *digest, rpm_loff_t *size);
int rstreq(const char *s1, const char *s2);
void rpmlog(int level, const char *msg, ...);
const char * _(const char *s);

const unsigned char *rpmfilesFDigest(rpmfiles fi, int ix, int *algo, size_t *diglen);
const char *rpmfilesFLink(rpmfiles fi, int ix);
const char *rpmfilesFN(rpmfiles fi, int ix);
rpmfileAttrs rpmfilesFFlags(rpmfiles fi, int ix);
rpm_mode_t rpmfilesFMode(rpmfiles fi, int ix);
rpm_rdev_t rpmfilesFRdev(rpmfiles fi, int ix);
rpm_loff_t rpmfilesFSize(rpmfiles fi, int ix);
int rpmfilesFState(rpmfiles fi, int ix);
const char *rpmfilesFCaps(rpmfiles fi, int ix);
time_t rpmfilesFMtime(rpmfiles fi, int ix);
const char *rpmfilesFUser(rpmfiles fi, int ix);
const char *rpmfilesFGroup(rpmfiles fi, int ix);
rpmVerifyAttrs rpmfilesVFlags(rpmfiles fi, int ix);

const char *rpmugUname(uid_t uid);
int rpmugUid(const char *name, uid_t *uid);
const char *rpmugGname(gid_t gid);
int rpmugGid(const char *name, gid_t *gid);

#define RPMLOG_WARNING 0