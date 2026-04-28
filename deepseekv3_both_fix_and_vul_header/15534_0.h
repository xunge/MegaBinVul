#include <signal.h>
#include <sys/types.h>

typedef enum {
  FIO_CLUSTER_MSG_FORWARD,
  FIO_CLUSTER_MSG_JSON,
  FIO_CLUSTER_MSG_SHUTDOWN,
  FIO_CLUSTER_MSG_ERROR,
  FIO_CLUSTER_MSG_PING,
  FIO_CLUSTER_MSG_ROOT,
  FIO_CLUSTER_MSG_ROOT_JSON,
  FIO_CLUSTER_MSG_PUBSUB_SUB,
  FIO_CLUSTER_MSG_PUBSUB_UNSUB,
  FIO_CLUSTER_MSG_PATTERN_SUB,
  FIO_CLUSTER_MSG_PATTERN_UNSUB
} fio_cluster_message_type_e;

struct cluster_pr_s {
  fio_cluster_message_type_e type;
  void *msg;
};

extern void fio_publish2process(void *msg);
extern void *fio_msg_internal_dup(void *msg);
extern void fio_stop(void);