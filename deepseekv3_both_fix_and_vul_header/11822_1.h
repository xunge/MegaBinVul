#include <stdlib.h>
#include <string.h>

extern char **environ;

#define dVAR
#define pTHX_
#define aTHX 0
#define PL_curinterp 0
#define PL_use_safe_putenv 0
#define PL_origenviron 0
#define USE_ITHREADS
#define PERL_USE_SAFE_PUTENV
#define __amigaos4__
#define __FUNCTION__ ""
#define __CYGWIN__
#define __SYMBIAN32__
#define __riscos__
#define __sun
#define HAS_UNSETENV
#define PERL_DARWIN

#define strnEQ(a,b,c) (strncmp(a,b,c) == 0)
#define Copy(s,d,n,t) memcpy(d,s,n)
#define UV unsigned long
#define Size_t size_t
#define I32 int

void *S_env_alloc(void *ptr, size_t a, size_t b, size_t c, size_t d);
void my_setenv_format(char *buf, const char *nam, size_t nlen, const char *val, size_t vlen);
void *safesysmalloc(size_t size);
void *safesysrealloc(void *ptr, size_t size);
void safesysfree(void *ptr);

void amigaos4_obtain_environ(const char *func);
void amigaos4_release_environ(const char *func);