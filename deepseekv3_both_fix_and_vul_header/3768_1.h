#include <stdio.h>

#define POP3_STRING_SIZE 1024

#define MAILPOP3_ERROR_STREAM -1
#define MAILPOP3_ERROR_STLS_NOT_SUPPORTED -2
#define MAILPOP3_ERROR_SSL -3
#define MAILPOP3_NO_ERROR 0

#define RESPONSE_OK 0

typedef struct mailstream {
    int read_buffer_len;
} mailstream;

typedef struct mailpop3 {
    mailstream *pop3_stream;
} mailpop3;

int send_command(mailpop3 *f, const char *command);
char *read_line(mailpop3 *f);
int parse_response(mailpop3 *f, const char *response);