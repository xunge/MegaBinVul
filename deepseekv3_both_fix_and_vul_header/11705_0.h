#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern FILE *log_file;

char *make_file_name(const char *name, const char *prog, const char *namespace, const char *instance);
#define FREE(ptr) free(ptr)