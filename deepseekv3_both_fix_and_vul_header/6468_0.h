#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

typedef struct rpmfi_s *rpmfi;
typedef struct rpmpsm_s *rpmpsm;
typedef struct FD_s *FD_t;

#define RPMERR_OPEN_FAILED (-1)

extern FD_t Fopen(const char *path, const char *mode);
extern int Ferror(FD_t fd);
extern int Fclose(FD_t fd);
extern int rpmfiArchiveReadToFilePsm(rpmfi fi, FD_t fd, int nodigest, rpmpsm psm);