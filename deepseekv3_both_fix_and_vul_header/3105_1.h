#include <errno.h>

#define CLONE_NEWUSER 0x10000000

struct cred;
struct cred *prepare_creds(void);
int create_user_ns(struct cred *cred);