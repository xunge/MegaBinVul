#include <stdint.h>
#include <stddef.h>

typedef struct TCP_Server TCP_Server;
typedef struct Mono_Time Mono_Time;
typedef struct TCP_Secure_Connection {
    // Placeholder for TCP_Secure_Connection members
    // (actual implementation would define proper fields here)
    uint8_t dummy;
} TCP_Secure_Connection;

int add_accepted(TCP_Server *tcp_server, const Mono_Time *mono_time, TCP_Secure_Connection *con);
void kill_TCP_secure_connection(TCP_Secure_Connection *con);
void crypto_memzero(void *data, size_t length);
int handle_TCP_packet(TCP_Server *tcp_server, int index, const uint8_t *data, uint16_t length);
void kill_accepted(TCP_Server *tcp_server, int index);