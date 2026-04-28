#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define LOG_MESSAGE_LEN 256
#define WITH_HANDLE_REDIRECT

typedef void* SQLHDESC;
typedef short SQLSMALLINT;
typedef void* SQLPOINTER;
typedef long SQLINTEGER;
typedef int SQLRETURN;

#define SQL_HANDLE_DESC 4
#define SQL_INVALID_HANDLE (-2)
#define SQL_ERROR (-1)
#define SQL_NTS (-3)
#define LOG_INFO 1

#define SQL_IS_POINTER 0
#define SQL_IS_INTEGER 1
#define SQL_IS_UINTEGER 2
#define SQL_IS_SMALLINT 3
#define SQL_IS_USMALLINT 4

#define SQL_PARAM_INPUT 0
#define SQL_PARAM_OUTPUT 1
#define SQL_PARAM_INPUT_OUTPUT 2
#define SQL_PARAM_INPUT_OUTPUT_STREAM 3
#define SQL_PARAM_OUTPUT_STREAM 4

#define ERROR_HY010 0
#define ERROR_07009 1
#define ERROR_HY090 2
#define ERROR_HY105 3
#define ERROR_IM001 4

#define SQL_DESC_ALLOC_TYPE 1001
#define SQL_DESC_ARRAY_SIZE 1002
#define SQL_DESC_ARRAY_STATUS_PTR 1003
#define SQL_DESC_BIND_OFFSET_PTR 1004
#define SQL_DESC_BIND_TYPE 1005
#define SQL_DESC_COUNT 1006
#define SQL_DESC_ROWS_PROCESSED_PTR 1007
#define SQL_DESC_AUTO_UNIQUE_VALUE 1008
#define SQL_DESC_CASE_SENSITIVE 1009
#define SQL_DESC_CONCISE_TYPE 1010
#define SQL_DESC_DATA_PTR 1011
#define SQL_DESC_DATETIME_INTERVAL_CODE 1012
#define SQL_DESC_DATETIME_INTERVAL_PRECISION 1013
#define SQL_DESC_DISPLAY_SIZE 1014
#define SQL_DESC_FIXED_PREC_SCALE 1015
#define SQL_DESC_INDICATOR_PTR 1016
#define SQL_DESC_LENGTH 1017
#define SQL_DESC_NULLABLE 1018
#define SQL_DESC_NUM_PREC_RADIX 1019
#define SQL_DESC_OCTET_LENGTH 1020
#define SQL_DESC_OCTET_LENGTH_PTR 1021
#define SQL_DESC_PARAMETER_TYPE 1022
#define SQL_DESC_PRECISION 1023
#define SQL_DESC_ROWVER 1024
#define SQL_DESC_SCALE 1025
#define SQL_DESC_SEARCHABLE 1026
#define SQL_DESC_TYPE 1027
#define SQL_DESC_UNNAMED 1028
#define SQL_DESC_UNSIGNED 1029
#define SQL_DESC_UPDATABLE 1030
#define SQL_DESC_BASE_COLUMN_NAME 1031
#define SQL_DESC_BASE_TABLE_NAME 1032
#define SQL_DESC_CATALOG_NAME 1033
#define SQL_DESC_LABEL 1034
#define SQL_DESC_LITERAL_PREFIX 1035
#define SQL_DESC_LITERAL_SUFFIX 1036
#define SQL_DESC_LOCAL_TYPE_NAME 1037
#define SQL_DESC_NAME 1038
#define SQL_DESC_SCHEMA_NAME 1039
#define SQL_DESC_TABLE_NAME 1040
#define SQL_DESC_TYPE_NAME 1041

typedef char SQLCHAR;

struct Connection {
    int state;
    int unicode_driver;
    struct {
        int requested_version;
    } *environment;
};

struct DMHDESC_struct {
    struct Connection *connection;
    SQLHDESC driver_desc;
    char msg[LOG_MESSAGE_LEN];
    struct {
        int log_flag;
    } log_info;
    int error;
};

typedef struct DMHDESC_struct* DMHDESC;

typedef enum {
    STATE_C4,
    STATE_S8,
    STATE_S9,
    STATE_S10,
    STATE_S11,
    STATE_S12,
    STATE_S13,
    STATE_S14,
    STATE_S15
} ConnectionState;

extern struct {
    int log_flag;
} log_info;

int __validate_desc(DMHDESC descriptor);
void dm_log_write(const char *file, int line, int level1, int level2, const char *message);
DMHDESC find_parent_handle(DMHDESC descriptor, int handle_type);
int CHECK_SQLSETDESCFIELDW(SQLHDESC connection);
SQLRETURN SQLSETDESCFIELDW(SQLHDESC connection, SQLHDESC descriptor, SQLSMALLINT rec_number, SQLSMALLINT field_identifier, SQLPOINTER value, SQLINTEGER buffer_length);
void function_entry(DMHDESC descriptor);
const char *__desc_attr_as_string(SQLCHAR *buf, SQLSMALLINT field_identifier);
void thread_protect(int handle_type, DMHDESC descriptor);
int __check_stmt_from_desc(DMHDESC descriptor, ConnectionState state);
void __post_internal_error(int *error, int code, const char *message, int version);
SQLRETURN function_return_nodrv(int handle_type, DMHDESC descriptor, SQLRETURN ret);
SQLRETURN function_return(int handle_type, DMHDESC descriptor, SQLRETURN ret);
const char *__get_return_status(SQLRETURN ret, SQLCHAR *buf);
int CHECK_SQLSETDESCFIELD(SQLHDESC connection);
SQLRETURN SQLSETDESCFIELD(SQLHDESC connection, SQLHDESC descriptor, SQLSMALLINT rec_number, SQLSMALLINT field_identifier, SQLPOINTER value, SQLINTEGER buffer_length);
SQLCHAR *unicode_to_ansi_alloc(SQLPOINTER value, SQLINTEGER length, SQLHDESC connection, void *param);