#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>

#define PACKET_LENGTH 4096
#define SERIAL_NUMBER_LENGTH_MAX 256
#define MODEL_NAME_LENGTH_MAX 256

#define EXIT_CODE_INVALID_SOCKET_INTERFACES_LIST 1
#define EXIT_CODE_CANNOT_GET_INTERFACES_LIST 2
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_1 3
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_2 4
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_3 5
#define EXIT_CODE_GENERIC 6
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_4 7
#define EXIT_CODE_INVALID_SOCKET_1 8
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_5 9
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_6 10
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_7 11
#define EXIT_CODE_INVALID_SOCKET_2 12
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_8 13
#define EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_9 14
#define EXIT_CODE_SUCCESS 0

typedef int socket_handle_t;
#define INVALID_SOCKET (-1)

typedef ssize_t gssize;
typedef size_t gsize;
typedef int64_t gint64;
typedef uint64_t guint64;
typedef unsigned int guint;

typedef struct extcap_parameters extcap_parameters;

#define G_GSSIZE_FORMAT "zd"

void errmsg_print(const char *format, ...);
void verbose_print(const char *format, ...);
char *g_strstr_len(const char *haystack, gssize haystack_len, const char *needle);
int g_snprintf(char *str, gsize n, const char *format, ...);
gint64 g_ascii_strtoll(const char *nptr, char **endptr, guint base);
guint64 g_ascii_strtoull(const char *nptr, char **endptr, guint base);
void new_interface(extcap_parameters *extcap_conf, int interface_type, const char *model_name, const char *serial_number, const char *description);

socket_handle_t adb_connect(const char *adb_server_ip, unsigned short *adb_server_tcp_port);
int adb_send(socket_handle_t sock, const char *packet);
char *adb_send_and_receive(socket_handle_t sock, const char *command, char *packet, size_t packet_size, gssize *data_length);
char *adb_send_and_read(socket_handle_t sock, const char *command, char *packet, size_t packet_size, gssize *data_length);
int closesocket(socket_handle_t sock);

#define INTERFACE_ANDROID_WIFI_TCPDUMP 0
#define INTERFACE_ANDROID_LOGCAT_MAIN 1
#define INTERFACE_ANDROID_LOGCAT_SYSTEM 2
#define INTERFACE_ANDROID_LOGCAT_RADIO 3
#define INTERFACE_ANDROID_LOGCAT_EVENTS 4
#define INTERFACE_ANDROID_LOGCAT_TEXT_MAIN 5
#define INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM 6
#define INTERFACE_ANDROID_LOGCAT_TEXT_RADIO 7
#define INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS 8
#define INTERFACE_ANDROID_LOGCAT_TEXT_CRASH 9
#define INTERFACE_ANDROID_BLUETOOTH_HCIDUMP 10
#define INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER 11
#define INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET 12