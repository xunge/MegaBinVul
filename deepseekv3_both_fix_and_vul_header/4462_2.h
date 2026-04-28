#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdbool.h>

struct kiocb;
struct compat_iovec;

#define CONFIG_COMPAT
#define UIO_FASTIOV 8

#define __user

extern ssize_t compat_rw_copy_check_uvector(int, struct compat_iovec *, unsigned long, unsigned long, struct iovec *, struct iovec **);
extern ssize_t rw_copy_check_uvector(int, struct iovec *, unsigned long, unsigned long, struct iovec *, struct iovec **);