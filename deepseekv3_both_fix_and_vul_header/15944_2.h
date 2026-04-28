#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* s;
    int len;
} str;

typedef struct ucontact {
    str c;
    str received;
    str path;
    str instance;
    str callid;
    str attr;
    float q;
    unsigned int cflags;
    void* sock;
    time_t last_modified;
    struct ucontact* next;
} ucontact_t;

typedef struct urecord {
    ucontact_t* contacts;
} urecord_t;

typedef struct udomain {
    // udomain structure members
} udomain_t;

typedef struct sip_msg {
    str new_uri;
    struct {
        struct {
            struct {
                str uri;
            } request;
        } u;
    } first_line;
    void* force_send_socket;
} sip_msg_t;

typedef struct {
    int flags;
    str rs;
} pv_value_t;

typedef void* pv_spec_p;
typedef void* gparam_p;

typedef union {
    int n;
    str s;
} int_str;

#define REG_LOOKUP_METHODFILTER_FLAG 0x01
#define REG_LOOKUP_NOBRANCH_FLAG 0x02
#define PV_VAL_STR 0x01
#define AVP_VAL_STR 0x01

#define LM_ERR(fmt, ...)
#define LM_WARN(fmt, ...)
#define LM_DBG(fmt, ...)

extern struct {
    void (*lock_udomain)(udomain_t*, str*);
    void (*unlock_udomain)(udomain_t*, str*);
    int (*get_urecord)(udomain_t*, str*, urecord_t**);
    void (*release_urecord)(urecord_t*);
} ul;

extern time_t act_time;
extern int attr_avp_name;

#define VALID_CONTACT(ptr, time) 1
#define ZSW(s) (s?s:"")

int fixup_get_svalue(sip_msg_t* _m, gparam_p _f, str* flags_s);
int pv_get_spec_value(sip_msg_t* _m, pv_spec_p _s, pv_value_t* val);
int extract_aor(str* uri, str* aor, str* sip_instance, str* call_id);
void get_act_time(void);
int allowed_method(sip_msg_t* _m, ucontact_t* ptr, unsigned int flags);
int set_ruri(sip_msg_t* _m, str* c);
int get_path_dst_uri(str* path, str* path_dst);
int set_path_vector(sip_msg_t* _m, str* path);
int set_dst_uri(sip_msg_t* _m, str* dst_uri);
void set_ruri_q(float q);
void setbflag(int flag, unsigned int cflags);
int add_avp_last(int type, int name, int_str istr);
int append_branch(sip_msg_t* _m, str* c, str* dst_uri, str* path, float q, unsigned int cflags, void* sock);