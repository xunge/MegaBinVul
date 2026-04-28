#include <stdint.h>

#define _U_ __attribute__((unused))

typedef int gboolean;
typedef uint8_t guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx_t {
    struct packet_info *pinfo;
} asn1_ctx_t;
typedef struct packet_info packet_info;

typedef struct {
    int keytype;
    int keylength;
    guint8 *keyvalue;
} kerberos_key_t;

typedef struct {
    kerberos_key_t key;
} kerberos_private_data_t;

extern const void *EncryptionKey_sequence;
extern int ett_kerberos_EncryptionKey;

extern kerberos_private_data_t *kerberos_get_private_data(asn1_ctx_t *actx);
extern int dissect_ber_sequence(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, const void *seq, int hf_index, int ett);
extern void add_encryption_key(packet_info *pinfo, int keytype, int keylength, guint8 *keyvalue, const char *label);