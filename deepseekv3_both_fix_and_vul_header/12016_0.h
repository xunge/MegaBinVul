#include <stdbool.h>

#define CEPH_MSG_MAX_FRONT_LEN 0
#define CEPH_MSG_MAX_MIDDLE_LEN 0
#define CEPH_MSG_MAX_DATA_LEN 0
#define CEPH_EPILOGUE_PLAIN_LEN 0
#define CEPH_EPILOGUE_SECURE_LEN 0

#define BUG_ON(condition) ((void)0)

static int padded_len(int len);