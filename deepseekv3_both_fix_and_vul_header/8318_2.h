#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct sockent sockent_t;
typedef int cdtime_t;

typedef struct value_list_s {
    cdtime_t time;
    cdtime_t interval;
    char host[64];
    char plugin[64];
    char plugin_instance[64];
    char type[64];
    char type_instance[64];
    void *values;
    size_t values_len;
} value_list_t;

typedef struct notification_s {
    cdtime_t time;
    int severity;
    char host[64];
    char plugin[64];
    char plugin_instance[64];
    char type[64];
    char type_instance[64];
    char message[1024];
} notification_t;

typedef struct part_header_s {
    uint16_t type;
    uint16_t length;
} part_header_t;

#define VALUE_LIST_INIT {0}

#define PP_SIGNED 0
#define PP_ENCRYPTED 0
#define HAVE_LIBGCRYPT 0
#define SECURITY_LEVEL_ENCRYPT 0
#define SECURITY_LEVEL_SIGN 0
#define TYPE_ENCR_AES256 0
#define TYPE_SIGN_SHA256 0
#define TYPE_VALUES 0
#define TYPE_TIME 0
#define TYPE_TIME_HR 0
#define TYPE_INTERVAL 0
#define TYPE_INTERVAL_HR 0
#define TYPE_HOST 0
#define TYPE_PLUGIN 0
#define TYPE_PLUGIN_INSTANCE 0
#define TYPE_TYPE 0
#define TYPE_TYPE_INSTANCE 0
#define TYPE_MESSAGE 0
#define TYPE_SEVERITY 0
#define NOTIF_FAILURE 0
#define NOTIF_WARNING 0
#define NOTIF_OKAY 0

#define TIME_T_TO_CDTIME_T(x) (x)

void ERROR(const char *format, ...);
void INFO(const char *format, ...);
void WARNING(const char *format, ...);
void DEBUG(const char *format, ...);
void sfree(void *ptr);
void sstrncpy(char *dest, const char *src, size_t n);
int parse_part_encr_aes256(sockent_t *se, void **buffer, size_t *buffer_size, int flags);
int parse_part_sign_sha256(sockent_t *se, void **buffer, size_t *buffer_size, int flags);
int parse_part_values(void **buffer, size_t *buffer_size, void **values, size_t *values_len);
int parse_part_number(void **buffer, size_t *buffer_size, uint64_t *value);
int parse_part_string(void **buffer, size_t *buffer_size, char *str, size_t str_len);
void network_dispatch_values(value_list_t *vl, const char *username);
void network_dispatch_notification(notification_t *n);