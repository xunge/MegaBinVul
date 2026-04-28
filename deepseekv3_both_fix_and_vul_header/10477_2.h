#include <stdlib.h>
#include <errno.h>

struct cred;
struct cred *prepare_creds(void);
int install_process_keyring_to_cred(struct cred *new);
void abort_creds(struct cred *new);
int commit_creds(struct cred *new);

#define ENOMEM 12
#define EEXIST 17