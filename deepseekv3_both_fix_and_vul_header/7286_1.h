#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct json_object;

struct econn_message {
    int msg_type;
    const char *sessid_sender;
    const char *src_userid;
    const char *src_clientid;
    const char *dest_userid;
    const char *dest_clientid;
    bool resp;
    union {
        struct {
            const char *sdp_msg;
            const void *props;
            const char *url;
        } setup;
        struct {
            const void *props;
        } propsync;
        struct {
            const void *props;
        } groupstart;
        struct {
            const void *turnv;
            size_t turnc;
            bool update;
            const char *tool;
            const char *toolver;
            int status;
            bool selective_audio;
            bool selective_video;
            int vstreams;
        } confconn;
        struct {
            const char *sft_url;
            const void *secret;
            size_t secretlen;
            unsigned long long timestamp;
            unsigned seqno;
            const void *props;
        } confstart;
        struct {
            const char *sft_url;
            const void *secret;
            size_t secretlen;
            unsigned long long timestamp;
            unsigned seqno;
        } confcheck;
        struct {
            bool should_start;
            unsigned long long timestamp;
            unsigned seqno;
            const void *entropy;
            size_t entropylen;
            const void *partl;
        } confpart;
        struct {
            const void *keyl;
        } confkey;
        struct {
            const void *turnv;
            size_t turnc;
            const char *sdp;
            const char *username;
        } devpair_publish;
        struct {
            const char *sdp;
        } devpair_accept;
        struct {
            int level;
            const char *descr;
        } alert;
    } u;
};

extern const char *econn_proto_version;
extern const char *econn_msg_name(int msg_type);

enum econn_msg_type {
    ECONN_SETUP,
    ECONN_GROUP_SETUP,
    ECONN_UPDATE,
    ECONN_CANCEL,
    ECONN_HANGUP,
    ECONN_REJECT,
    ECONN_PROPSYNC,
    ECONN_GROUP_START,
    ECONN_GROUP_LEAVE,
    ECONN_GROUP_CHECK,
    ECONN_CONF_CONN,
    ECONN_CONF_START,
    ECONN_CONF_CHECK,
    ECONN_CONF_END,
    ECONN_CONF_PART,
    ECONN_CONF_KEY,
    ECONN_DEVPAIR_PUBLISH,
    ECONN_DEVPAIR_ACCEPT,
    ECONN_ALERT,
    ECONN_PING
};

int jzon_creatf(struct json_object **jobj, const char *fmt, ...);
int jzon_add_str(struct json_object *jobj, const char *name, const char *fmt, ...);
int jzon_add_bool(struct json_object *jobj, const char *name, bool value);
int jzon_add_int(struct json_object *jobj, const char *name, int value);
int jzon_add_base64(struct json_object *jobj, const char *name, const void *data, size_t len);
int jzon_encode(char **strp, struct json_object *jobj);
int econn_props_encode(struct json_object *jobj, const void *props);
int zapi_iceservers_encode(struct json_object *jobj, const void *turnv, size_t turnc);
int econn_parts_encode(struct json_object *jobj, const void *partl);
int econn_keys_encode(struct json_object *jobj, const void *keyl);
void warning(const char *fmt, ...);
void *mem_deref(void *ptr);
bool str_isset(const char *str);