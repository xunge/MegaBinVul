#include <time.h>

#define DBUG_ENTER(x)
#define DBUG_PRINT(x, y)
#define DBUG_RETURN(x) return x

#define FN_REFLEN 512
#define MY_BACKUP_NAME_EXTRA_LENGTH 64

#define MY_REDEL_MAKE_BACKUP (1 << 0)

typedef int myf;

extern int my_disable_copystat_in_redel;
extern int my_copystat(const char *, const char *, myf);
extern void my_create_backup_name(char *, const char *, time_t);
extern int my_rename(const char *, const char *, myf);
extern int my_delete(const char *, myf);