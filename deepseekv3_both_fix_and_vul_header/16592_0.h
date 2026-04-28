#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct sshbuf;
struct sshkey;

#define SSH_AGENT_CONSTRAIN_LIFETIME 1
#define SSH_AGENT_CONSTRAIN_CONFIRM 2
#define SSH_AGENT_CONSTRAIN_MAXSIGN 3
#define SSH_AGENT_CONSTRAIN_EXTENSION 4

#define SSH_ERR_INVALID_FORMAT -1
#define SSH_ERR_FEATURE_UNSUPPORTED -2

time_t monotime(void);
int sshbuf_get_u8(struct sshbuf *, u_char *);
int sshbuf_get_u32(struct sshbuf *, u_int *);
int sshbuf_get_cstring(struct sshbuf *, char **, void *);
size_t sshbuf_len(struct sshbuf *);
void sshbuf_free(struct sshbuf *);
int sshkey_enable_maxsign(struct sshkey *, u_int);
void error_f(const char *, ...);
void error_fr(int, const char *, ...);
void debug_f(const char *, ...);