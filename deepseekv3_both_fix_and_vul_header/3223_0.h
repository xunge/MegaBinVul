#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

extern int transfer_file_attrs(FILE *from_fp, FILE *to_fp, const char **err_status);