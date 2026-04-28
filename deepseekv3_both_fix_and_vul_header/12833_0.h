#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <sys/wait.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>

#define FALSE 0
#define TRUE 1
#define POSTSRSD_VERSION "1.0"

typedef void (*handle_t)(void*, FILE*, char*, char*, const char**);

typedef struct srs_t srs_t;

char *self;

void show_help(void);
size_t bind_service(char *listen_addr, char *service, int family, int *sockets, size_t max_sockets);
void handle_forward(srs_t *srs, FILE *fp, char *key, char *domain, const char **excludes);
void handle_reverse(srs_t *srs, FILE *fp, char *key, char *domain, const char **excludes);
srs_t *srs_new(void);
void srs_add_secret(srs_t *srs, char *secret);
void srs_set_alwaysrewrite(srs_t *srs, int always_rewrite);
void srs_set_separator(srs_t *srs, char separator);
void srs_set_hashlength(srs_t *srs, int hashlength);
void srs_set_hashmin(srs_t *srs, int hashmin);
char *url_decode(char *buf, size_t len, char *src);