#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

struct usb_sock_t;
struct tcp_sock_t;
struct service_thread_param {
    struct usb_sock_t *usb_sock;
    struct tcp_sock_t *tcp;
    pthread_t thread_handle;
};

struct options {
    int noprinter_mode;
    uint16_t desired_port;
    int only_desired_port;
    int nofork_mode;
};

extern struct options g_options;
extern void ERR(const char *fmt, ...);

struct usb_sock_t *usb_open(void);
void usb_close(struct usb_sock_t *sock);
int usb_can_callback(struct usb_sock_t *sock);
void usb_register_callback(struct usb_sock_t *sock);

struct tcp_sock_t *tcp_open(uint16_t port);
void tcp_close(struct tcp_sock_t *sock);
uint16_t tcp_port_number_get(struct tcp_sock_t *sock);
struct tcp_sock_t *tcp_conn_accept(struct tcp_sock_t *sock);
void tcp_conn_close(struct tcp_sock_t *conn);

void *service_connection(void *arg);