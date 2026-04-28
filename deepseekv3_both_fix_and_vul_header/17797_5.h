#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct connection {
    int (*conn_read)(struct connection *);
    int (*conn_write)(struct connection *);
    int (*conn_close)(struct connection *);
    int (*conn_poll)(struct connection *);
} CONNECTION;

int mutt_socket_has_buffered_input(CONNECTION *conn);
void mutt_error(const char *msg);
void mutt_sleep(int sec);
void mutt_socket_clear_buffered_input(CONNECTION *conn);
int tls_init(void);
int tls_negotiate(CONNECTION *conn);
int tls_socket_read(CONNECTION *conn);
int tls_socket_write(CONNECTION *conn);
int tls_starttls_close(CONNECTION *conn);
int tls_socket_poll(CONNECTION *conn);

#define _(x) (x)