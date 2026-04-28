#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

struct dump_dir;
int dd_openfd(const char *path);
int fdump_dir_accessible_by_uid(int dir_fd, uid_t uid);
struct dump_dir *dd_fdopendir(int dir_fd, const char *path, unsigned flags);
void dd_close(struct dump_dir *dd);
int dot_or_dotdot(const char *name);
char *concat_path_file(const char *path, const char *filename);

#define VERB2
extern int logmode;

#define DD_OPEN_READONLY (1 << 0)
#define DD_FAIL_QUIETLY_EACCES (1 << 1)
#define DD_DONT_WAIT_FOR_LOCK (1 << 2)