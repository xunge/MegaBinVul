#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct Error Error;

int64_t guest_file_handle_add(FILE *fh, Error **err);
void slog(const char *fmt, ...);
void error_setg_errno(Error **errp, int errnoval, const char *fmt, ...);
bool error_is_set(Error **err);