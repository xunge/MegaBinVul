#include <stdio.h>
#include <stdlib.h>

typedef int rpmTagVal;
typedef struct Header *Header;
typedef struct HeaderIterator *HeaderIterator;

struct rpmtd_s {
    int tag;
    int type;
    int count;
    void *data;
};

struct taglate_s {
    int stag;
    int xtag;
    int count;
};

static const struct taglate_s xlateTags[] = {
    {0, 0, 0}
};

#define HEADERGET_RAW 0
#define HEADERGET_MINMEM 0
#define HEADERPUT_DEFAULT 0

#define RPMSIGTAG_SIZE 1000
#define RPMSIGTAG_PGP 1001
#define RPMSIGTAG_MD5 1002
#define RPMSIGTAG_GPG 1003
#define RPMSIGTAG_PGP5 1004
#define RPMSIGTAG_PAYLOADSIZE 1005
#define RPMSIGTAG_FILESIGNATURES 1006
#define RPMSIGTAG_FILESIGNATURELENGTH 1007
#define RPMSIGTAG_VERITYSIGNATURES 1008
#define RPMSIGTAG_VERITYSIGNATUREALGO 1009
#define RPMSIGTAG_SHA1 1010
#define RPMSIGTAG_SHA256 1011
#define RPMSIGTAG_DSA 1012
#define RPMSIGTAG_RSA 1013

#define RPMTAG_SIGSIZE 2000
#define RPMTAG_SIGPGP 2001
#define RPMTAG_SIGMD5 2002
#define RPMTAG_SIGGPG 2003
#define RPMTAG_SIGPGP5 2004
#define RPMTAG_ARCHIVESIZE 2005
#define RPMTAG_FILESIGNATURES 2006
#define RPMTAG_FILESIGNATURELENGTH 2007

#define HEADER_SIGBASE 1000
#define HEADER_TAGBASE 2000

#define RPM_NULL_TYPE 0
#define RPM_CHAR_TYPE 1
#define RPM_INT8_TYPE 2
#define RPM_INT16_TYPE 3
#define RPM_INT32_TYPE 4
#define RPM_INT64_TYPE 5
#define RPM_STRING_TYPE 6
#define RPM_STRING_ARRAY_TYPE 7
#define RPM_BIN_TYPE 8
#define RPM_I18NSTRING_TYPE 9

static int headerIsEntry(Header h, int tag) { return 0; }
static int headerGet(Header h, int tag, struct rpmtd_s *td, int flags) { return 0; }
static int headerPut(Header h, struct rpmtd_s *td, int flags) { return 0; }
static HeaderIterator headerInitIterator(Header h) { return NULL; }
static int headerNext(HeaderIterator hi, struct rpmtd_s *td) { return 0; }
static void headerFreeIterator(HeaderIterator hi) {}
static void rpmtdReset(struct rpmtd_s *td) {}
static void rpmtdFreeData(struct rpmtd_s *td) {}
static const char *rpmTagGetName(int tag) { return NULL; }
static int rpmTagGetTagType(int tag) { return 0; }
static int rasprintf(char **strp, const char *fmt, ...) { return 0; }