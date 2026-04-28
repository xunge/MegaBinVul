#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define PHPAPI
#define BAD_MAIL_HOST 1
#define FAILURE 0
#define HOST_NAME_LEN 256
#define W32_SM_PCRE_ERROR 2
#define W32_SM_SENDMAIL_FROM_NOT_SET 3
#define SUCCESS 1

typedef struct _zend_string zend_string;

extern zend_string *zend_string_tolower(zend_string *s);
extern void zend_string_release_ex(zend_string *s, int persistent);
extern void zend_string_release(zend_string *s);
extern char *estrdup(const char *s);
extern char *INI_STR(const char *name);
extern char *estrndup(const char *s, size_t length);
extern void *ecalloc(size_t nmemb, size_t size);
extern void efree(void *ptr);
extern int INI_INT(const char *name);
extern int MailConnect(void);
extern int SendText(char *RPath, char *Subject, char *mailTo, char *mailCc, char *mailBcc, char *data, char *headers_trim, char *headers_lc, char **error_message);
extern void TSMClose(void);
extern zend_string *php_win32_mail_trim_header(char *headers);

struct _zend_string {
    char *val;
    size_t len;
};

#define ZSTR_VAL(zs) ((zs)->val)
#define PW32G(name) name

char mail_host[HOST_NAME_LEN];