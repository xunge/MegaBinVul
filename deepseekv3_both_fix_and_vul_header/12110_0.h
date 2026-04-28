#include <stdio.h>
#include <stdlib.h>

typedef enum {
    DLT_RETURN_OK,
    DLT_RETURN_ERROR,
    DLT_RETURN_WRONG_PARAMETER
} DltReturnValue;

typedef struct {
    FILE *handle;
    long *index;
    int counter;
    int position;
} DltFile;

#define PRINT_FUNCTION_VERBOSE(verbose)
#define LOG_WARNING 0

void dlt_vlog(int level, const char *format, ...);
int dlt_file_read_header(DltFile *file, int verbose);
int dlt_file_read_header_extended(DltFile *file, int verbose);
int dlt_file_read_data(DltFile *file, int verbose);