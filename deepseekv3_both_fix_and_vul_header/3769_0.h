#include <stdlib.h>

#define MAILSMTP_ESMTP_STARTTLS (1 << 0)
#define MAILSMTP_NO_ERROR 0
#define MAILSMTP_ERROR_STARTTLS_NOT_SUPPORTED -1
#define MAILSMTP_ERROR_STREAM -2
#define MAILSMTP_ERROR_SSL -3
#define MAILSMTP_ERROR_STARTTLS_TEMPORARY_FAILURE -4
#define MAILSMTP_ERROR_UNEXPECTED_CODE -5

struct mailstream {
    size_t read_buffer_len;
};

typedef struct {
    int esmtp;
    struct mailstream *stream;
} mailsmtp;

int send_command(mailsmtp *session, const char *command);
int read_response(mailsmtp *session);