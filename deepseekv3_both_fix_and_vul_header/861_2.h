#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MQTTSN_CLI_ID_MINLEN 1
#define MQTTSN_CLI_ID_MAXLEN 23
#define EMCUTE_KEEPALIVE 60
#define US_PER_SEC 1000000
#define ETIMEDOUT 110
#define SOCK_IPV6_EP_ANY { .port = 0 }

typedef struct {
    void (*callback)(void *);
    void *arg;
} emcute_timer_t;

typedef struct {
    uint16_t port;
} sock_udp_ep_t;

typedef struct {
    int dummy;
} sock_udp_t;

typedef struct {
    int dummy;
} mutex_t;

enum {
    CONNACK,
    WILLTOPICREQ,
    WILLMSGREQ,
    REGACK,
    PUBLISH,
    PUBACK,
    SUBACK,
    UNSUBACK,
    PINGREQ,
    PINGRESP,
    DISCONNECT,
    WILLTOPICRESP,
    WILLMSGRESP
};

extern const char *cli_id;
extern emcute_timer_t timer;
extern mutex_t txlock;
extern sock_udp_t sock;
extern char rbuf[256];

#define LOG_ERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

void time_evt(void *arg);
void mutex_init(mutex_t *mutex);
int sock_udp_create(sock_udp_t *sock, sock_udp_ep_t *local, sock_udp_ep_t *remote, int flags);
ssize_t sock_udp_recv(sock_udp_t *sock, void *buf, size_t len, uint32_t timeout, sock_udp_ep_t *remote);
uint32_t xtimer_now_usec();
size_t get_len(const char *buf, uint16_t *len);
void on_ack(uint8_t type, size_t min, size_t max, size_t off);
void on_publish(size_t pkt_len, size_t pos);
void on_pingreq(sock_udp_ep_t *remote);
void on_pingresp(void);
void on_disconnect(void);
const char *emcute_type_str(uint8_t type);
void send_ping(void);