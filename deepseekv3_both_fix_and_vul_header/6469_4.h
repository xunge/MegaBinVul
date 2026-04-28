#include <stdlib.h>
#include <unistd.h>

typedef struct rpmfi_s *rpmfi;
typedef struct rpmfiles_s *rpmfiles;
typedef struct rpmpsm_s *rpmpsm;

#define RPMERR_LINK_FAILED (-1)

int rpmfiFNlink(rpmfi fi);
int rpmfiFX(rpmfi fi);
int rpmfiArchiveHasContent(rpmfi fi);
char *rpmfilesFN(rpmfiles files, int ix);
int expandRegular(rpmfi fi, const char *dest, rpmpsm psm, int nodigest, int setmeta, ...);