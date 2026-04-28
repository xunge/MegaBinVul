#include <linux/types.h>
#include <limits.h>

#define MAX_LFS_FILESIZE ((loff_t)LLONG_MAX)

typedef long long loff_t;
typedef long long blkcnt_t;
typedef unsigned long long u64;