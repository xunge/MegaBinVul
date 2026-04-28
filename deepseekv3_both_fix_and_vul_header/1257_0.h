#include <stddef.h>

typedef struct request_rec request_rec;

#define APLOG_MARK
#define APLOG_ERR 0
#define HTTP_BAD_REQUEST 400
#define OK 0

#define AM_LOG_RERROR(mark, level, status, r, msg)