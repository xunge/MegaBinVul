#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct nano_work nano_work;
typedef struct topic_node topic_node;
typedef struct dbtree_retain_msg {
    void *message;
} dbtree_retain_msg;
typedef struct nng_msg nng_msg;

#define NMQ_AUTH_SUB_ERROR 0
#define ACL_SUB 0
#define ACL_DISCONNECT 0

struct topic_node {
    struct {
        int len;
        char *body;
    } topic;
    int reason_code;
    uint8_t qos;
    uint8_t retain_handling;
    topic_node *next;
};

struct nano_work {
    struct {
        int id;
    } pid;
    struct {
        int enable;
        struct {
            int enable;
            int acl_deny_action;
        } acl;
        struct {
            int enable;
        } sqlite;
    } *config;
    struct {
        int packet_id;
        topic_node *node;
    } *sub_pkt;
    void *db;
    void *db_ret;
    void *sqlite_db;
    void *cparam;
    void **msg_ret;
};

size_t cvector_size(void **vec);
void cvector_push_back(void **vec, void *item);
void cvector_free(void *vec);

void log_debug(const char *fmt, ...);
void log_warn(const char *fmt, ...);
void log_info(const char *fmt, ...);
bool auth_acl(void *config, int type, void *cparam, char *topic);
int dbhash_check_topic(int id, char *topic);
void dbtree_insert_client(void *db, char *topic, int id);
void dbhash_insert_topic(int id, char *topic, uint8_t qos);
dbtree_retain_msg **dbtree_find_retain(void *db_ret, char *topic);
void dbtree_print(void *db);
nng_msg **nng_mqtt_qos_db_find_retain(void *sqlite_db, char *topic);