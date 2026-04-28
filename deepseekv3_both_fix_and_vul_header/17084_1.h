#include <stdlib.h>
#include <string.h>

typedef struct str {
    char* s;
    int len;
} str;

typedef struct via_param {
    str value;
    struct via_param* next;
    struct via_param* branch;
} via_param;

typedef struct cseq_body {
    int method_id;
    str method;
    str number;
} cseq_body;

typedef struct from_body {
    str tag_value;
} from_body;

typedef struct pretran_t {
    unsigned int hid;
    unsigned int cseqmetid;
    str callid;
    str ftag;
    str cseqnum;
    str cseqmet;
    str vbranch;
    str dbuf;
    int pid;
    struct pretran_t* next;
} pretran_t;

typedef struct pretran_slot {
    void* lock;
    pretran_t* plist;
} pretran_slot;

typedef struct sip_msg_t {
    struct {
        int type;
    } first_line;
    struct hdr_field {
        str body;
        cseq_body* parsed;
        struct hdr_field* next;
    } *callid, *cseq;
    via_param* via1;
} sip_msg_t;

extern pretran_t* _tmx_proc_ptran;
extern pretran_slot* _tmx_ptran_table;
extern unsigned int _tmx_ptran_size;

int parse_headers(sip_msg_t* msg, int flags, int mode);
int parse_from_header(sip_msg_t* msg);
int get_route_type(void);
int my_pid(void);
void tmx_pretran_unlink(void);
void tmx_pretran_link_safe(unsigned int slotid);
unsigned int get_hash1_raw(char* s, int len);
void trim(str* s);
void* shm_malloc(size_t size);
void shm_free(void* p);
void lock_get(void* lock);
void lock_release(void* lock);
cseq_body* get_cseq(sip_msg_t* msg);
from_body* get_from(sip_msg_t* msg);

#define METHOD_ACK 0
#define METHOD_CANCEL 1
#define METHOD_OTHER 2
#define METHOD_UNDEF 3
#define REQUEST_ROUTE 0
#define SIP_REQUEST 0
#define HDR_FROM_F 0
#define HDR_VIA1_F 0
#define HDR_CALLID_F 0
#define HDR_CSEQ_F 0
#define LM_ERR(fmt, ...)
#define LM_DBG(fmt, ...)
#define unlikely(x) (x)
#define likely(x) (x)