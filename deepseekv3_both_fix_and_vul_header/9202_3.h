#include <stddef.h>
#include <stdint.h>

#define _U_ __attribute__((unused))
#define FALSE 0
#define TRUE 1
#define AT_NONE 0
#define PT_UDP 0
#define NO_ADDR_B 0

extern int maxNrOfMACdFlows;
extern int hrnti;
extern int proto_fp;

typedef struct {
    void* crnc_address;
    uint32_t crnc_port;
} nbap_hsdsch_channel_info_t;

extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];

typedef struct {
    int hrnti;
} umts_fp_conversation_info_t;

typedef struct {
    struct {
        struct {
            int visited;
        } flags;
        int num;
    } *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {} tvbuff_t;
typedef struct {} proto_tree;
typedef struct {} address;
typedef struct {} conversation_t;