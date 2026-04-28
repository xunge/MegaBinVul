#include <stdbool.h>
#include <linux/types.h>
#include <linux/errno.h>

#define TLS_TX 1
#define TLS_RX 2
#define TLS_TX_ZEROCOPY_RO 3
#define TLS_RX_EXPECT_NO_PAD 4

struct sock;

#define __user

int do_tls_getsockopt_conf(struct sock *sk, char __user *optval, int __user *optlen, bool tx);
int do_tls_getsockopt_tx_zc(struct sock *sk, char __user *optval, int __user *optlen);
int do_tls_getsockopt_no_pad(struct sock *sk, char __user *optval, int __user *optlen);