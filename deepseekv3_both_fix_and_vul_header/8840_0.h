#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

#define MAX_KEY_FILE_SIZE (1024 * 1024)
#define SSH_ERR_SYSTEM_ERROR -1
#define SSH_ERR_INVALID_FORMAT -2
#define SSH_ERR_FILE_CHANGED -3

struct sshbuf;
ssize_t atomicio(ssize_t (*)(int, void *, size_t), int, void *, size_t);