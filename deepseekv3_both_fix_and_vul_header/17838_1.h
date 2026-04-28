#include <stdlib.h>
#include <string.h>

typedef unsigned int oid;

struct snmp_secmod_def {
    int (*pdu_clone)(void *, void *);
};

struct usmStateReference;

typedef struct netsnmp_pdu {
    void *variables;
    oid *enterprise;
    int enterprise_length;
    char *community;
    size_t community_len;
    unsigned char *securityEngineID;
    size_t securityEngineIDLen;
    char *securityName;
    size_t securityNameLen;
    unsigned char *contextEngineID;
    size_t contextEngineIDLen;
    char *contextName;
    size_t contextNameLen;
    void *transport_data;
    size_t transport_data_length;
    int securityModel;
    void *securityStateRef;
    int command;
} netsnmp_pdu;

#define SNMP_MSG_TRAP2 1
#define SNMP_DEFAULT_SECMODEL 1

extern int snmp_clone_mem(void **, const void *, size_t);
extern void snmp_free_pdu(netsnmp_pdu *);
extern struct snmp_secmod_def *find_sec_mod(int);
extern int usm_clone_usmStateReference(struct usmStateReference *, struct usmStateReference **);
extern void netsnmp_assert(int);