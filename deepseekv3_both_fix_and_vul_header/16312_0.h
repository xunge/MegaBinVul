#include <stdio.h>
#include <string.h>
#include <syslog.h>

#define DLT_COMMON_BUFFER_LENGTH 255
#define DLT_ID_SIZE 4
#define DLT_FILTER_MAX 100

typedef enum {
    DLT_RETURN_OK,
    DLT_RETURN_ERROR,
    DLT_RETURN_WRONG_PARAMETER
} DltReturnValue;

typedef struct {
    int counter;
} DltFilter;

#define PRINT_FUNCTION_VERBOSE(verbose)

void dlt_vlog(int priority, const char *format, ...);
void dlt_set_id(char *id, const char *str);
void dlt_filter_add(DltFilter *filter, const char *apid, const char *ctid, int verbose);