#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef unsigned int oid;

typedef struct {
    oid *oid;
    size_t oid_len;
} oid_t;

typedef struct {
    char *name;
    void *sess_handle;
    void *complaint;
} host_definition_t;

typedef struct {
    char *name;
    char *type;
    oid_t *values;
    size_t values_len;
    struct {
        oid_t oid;
    } instance;
    double scale;
    double shift;
} data_definition_t;

typedef struct {
    int ds_num;
    struct {
        int type;
    } *ds;
} data_set_t;

typedef struct csnmp_list_instances_t {
    struct csnmp_list_instances_t *next;
} csnmp_list_instances_t;

typedef struct csnmp_table_values_t {
    double value;
    oid_t suffix;
    struct csnmp_table_values_t *next;
} csnmp_table_values_t;

typedef struct snmp_pdu {
    struct variable_list *variables;
} snmp_pdu;

typedef struct variable_list {
    oid *name;
    size_t name_length;
    int type;
    struct variable_list *next_variable;
} variable_list;

#define DEBUG(fmt, ...)
#define ERROR(fmt, ...)
#define LOG_ERR 0
#define LOG_INFO 1
#define STAT_SUCCESS 0
#define SNMP_ENDOFMIBVIEW 0
#define SNMP_MSG_GETNEXT 0

void *plugin_get_ds(const char *type);
void c_complain(int level, void *complaint, const char *fmt, ...);
void c_release(int level, void *complaint, const char *fmt, ...);
void csnmp_host_close_session(host_definition_t *host);
int csnmp_instance_list_add(csnmp_list_instances_t **head, csnmp_list_instances_t **tail, void *res, host_definition_t *host, data_definition_t *data);
void csnmp_dispatch_table(host_definition_t *host, data_definition_t *data, csnmp_list_instances_t *instance_head, csnmp_table_values_t **value_head);
double csnmp_value_list_to_value(void *vb, int type, double scale, double shift, const char *host, const char *data);
int csnmp_oid_suffix(oid_t *suffix, oid_t *vb_name, oid_t *value);
int csnmp_oid_compare(oid_t *a, oid_t *b);
void csnmp_oid_init(oid_t *dst, oid *src, size_t len);
void *snmp_pdu_create(int type);
void snmp_add_null_var(void *pdu, oid *name, size_t len);
int snmp_sess_synch_response(void *sess, void *req, void **res);
void snmp_sess_error(void *sess, void *a, void *b, char **errstr);
void snmp_free_pdu(void *pdu);
void sfree(void *ptr);
int snmp_oid_ncompare(oid *oid1, size_t len1, oid *oid2, size_t len2, size_t n);