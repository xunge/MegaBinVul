#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

struct mosquitto_db {
    char *config_file;
    bool verbose;
};

struct mosquitto__security_options {
    char *acl_file;
    char *password_file;
    char *psk_file;
    void *auth_plugin_configs;
    int auth_plugin_config_count;
    int allow_anonymous;
};

struct mosquitto__listener {
    int port;
    char *host;
    char *mount_point;
    int max_connections;
    int protocol;
    int socket_domain;
    int client_count;
    void *socks;
    int sock_count;
    bool use_username_as_clientid;
#ifdef WITH_TLS
    char *tls_version;
    char *cafile;
    char *capath;
    char *certfile;
    char *keyfile;
    char *ciphers;
    char *psk_hint;
    bool require_certificate;
    void *ssl_ctx;
    char *crlfile;
    bool use_identity_as_username;
    bool use_subject_as_username;
#endif
    struct mosquitto__security_options security_options;
};

struct mosquitto__config {
    bool daemon;
    char *user;
    int log_type;
    int listener_count;
    struct mosquitto__listener *listeners;
    struct mosquitto__listener default_listener;
};

enum mosquitto__protocol {
    mp_mqtt
};

enum MOSQ_LOG_TYPE {
    MOSQ_LOG_ERR,
    MOSQ_LOG_WARNING
};

#define MOSQ_ERR_INVAL 1
#define MOSQ_ERR_NOMEM 2

void *mosquitto__realloc(void *ptr, size_t size);
int config__read(struct mosquitto_db *db, struct mosquitto__config *config, bool flag);
void log__printf(void *ptr, int level, const char *fmt, ...);
void print_usage(void);
int config__check(struct mosquitto__config *config);