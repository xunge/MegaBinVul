#include <sys/types.h>
#include <stdio.h>

typedef unsigned char u_char;
typedef unsigned int oid;

#define NETSNMP_NO_WRITE_SUPPORT
#define MODE_SET_RESERVE1 1
#define MODE_SET_COMMIT 2
#define ASN_INTEGER 2
#define LOG_ERR 3
#define SNMP_ERR_WRONGTYPE 1
#define SNMP_ERR_WRONGVALUE 2
#define SNMP_ERR_GENERR 3
#define SNMP_ERR_NOERROR 0

struct extend_fix_entry {
    void *cache;
};

typedef struct netsnmp_old_extend_s {
    struct extend_fix_entry *efix_entry;
} netsnmp_old_extend;

extern netsnmp_old_extend *compatability_entries;

void snmp_log(int priority, const char *message);
void netsnmp_cache_check_and_reload(void *cache);