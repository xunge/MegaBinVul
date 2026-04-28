#include <stddef.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define MAXPATHL 1024
#define FNAME_UNESC 0x01
#define FNAME_REL 0x02
#define FNAME_MESS 0x04
#define FINDFILE_FILE 0
#define FINDFILE_DIR 1
#define FINDFILE_BOTH 2

typedef char char_u;

extern char_u *ff_file_to_find;
extern char_u NameBuff[MAXPATHL];
extern void *fdip_search_ctx;

struct Process {
    void *pr_WindowPtr;
};
typedef void *APTR;

void *FindTask(long);
void expand_env_esc(char_u *ptr, char_u *NameBuff, int maxpathlen, int esc, int expand, void *nullptr);
void vim_free(char_u *);
char_u *vim_strsave(const char_u *);
void mch_memmove(char_u *, char_u *, size_t);
size_t STRLEN(const char_u *);
#define STRCPY(dest, src) strcpy((dest), (src))
int vim_ispathsep(int c);
int vim_isAbsName(const char_u *);
int path_with_url(const char_u *);
char_u *gettail(char_u *);
int mch_getperm(const char_u *);
int mch_isdir(const char_u *);
void copy_option_part(char_u **, char_u *, int, const char *);
void vim_findfile_free_visited(void *);
char_u *vim_findfile(void *);
void vim_findfile_cleanup(void *);
char_u *alloc(int);
char_u *vim_findfile_stopdir(char_u *);
void *vim_findfile_init(char_u *, char_u *, char_u *, int, int, int, void *, int, char_u *);
void semsg(const char *, const char_u *);
const char *_(const char *);