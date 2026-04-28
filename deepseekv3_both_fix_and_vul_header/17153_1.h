#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0

#define WTAP_ERR_NOT_REGULAR_FILE -1
#define WTAP_ERR_CANT_WRITE_TO_PIPE -2
#define WTAP_ERR_UNWRITABLE_FILE_TYPE -3
#define WTAP_ERR_UNWRITABLE_ENCAP -4
#define WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED -5
#define WTAP_ERR_CANT_OPEN -6
#define WTAP_ERR_SHORT_WRITE -7
#define WTAP_ERR_COMPRESSION_NOT_SUPPORTED -8

char *output_file_description(const char *filename);
void cmdarg_err(const char *fmt, ...);
char *wtap_file_type_subtype_short_string(int file_type_subtype);
char *wtap_strerror(int err);
char *file_open_error_message(int err, int for_writing);
void g_free(void *ptr);