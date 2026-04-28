#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define MOSQ_DB_VERSION 0
#define MOSQ_ERR_INVAL 1
#define MOSQ_ERR_NOMEM 2
#define DB_CHUNK_CFG 0
#define MOSQ_LOG_INFO 1
#define MOSQ_LOG_ERR 2

typedef uint64_t dbid_t;

struct mosquitto_db {
    struct {
        char *persistence_filepath;
    } *config;
    dbid_t last_db_id;
};

extern void _mosquitto_log_printf(void *, int, const char *, ...);
extern void *_mosquitto_malloc(size_t);
extern void _mosquitto_free(void *);
extern FILE *_mosquitto_fopen(const char *, const char *);
extern int mqtt3_db_message_store_write(struct mosquitto_db *, FILE *);
extern int mqtt3_db_client_write(struct mosquitto_db *, FILE *);
extern int mqtt3_db_subs_retain_write(struct mosquitto_db *, FILE *);
extern int write_e(FILE *, const void *, size_t);

static const char magic[15] = {0};