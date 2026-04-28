#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WTAP_ERR_NOT_REGULAR_FILE 1
#define WTAP_ERR_RANDOM_OPEN_PIPE 2
#define WTAP_ERR_FILE_UNKNOWN_FORMAT 3
#define WTAP_ERR_UNSUPPORTED 4
#define WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED 5
#define WTAP_ERR_BAD_FILE 6
#define WTAP_ERR_CANT_OPEN 7
#define WTAP_ERR_SHORT_READ 8
#define WTAP_ERR_DECOMPRESS 9

#define FALSE 0
#define TRUE 1

typedef char gchar;

char *input_file_description(const char *filename);
void cmdarg_err(const char *fmt, ...);
char *file_open_error_message(int err, int for_writing);
char *wtap_strerror(int err);
void g_free(void *ptr);