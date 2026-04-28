#include <stddef.h>
#include <stdint.h>

typedef int (*asn1_action_t)(void *context, unsigned char hdr, unsigned char tag, const unsigned char *value, size_t len);

struct asn1_decoder {
    const unsigned char *machine;
    const asn1_action_t *actions;
    size_t machlen;
};

enum asn1_opcode {
    ASN1_OP_MATCH,
    ASN1_OP_MATCH_OR_SKIP,
    ASN1_OP_MATCH_ACT,
    ASN1_OP_MATCH_ACT_OR_SKIP,
    ASN1_OP_MATCH_ANY,
    ASN1_OP_MATCH_ANY_ACT,
    ASN1_OP_COND_MATCH_OR_SKIP,
    ASN1_OP_COND_MATCH_ACT_OR_SKIP,
    ASN1_OP_COND_MATCH_ANY,
    ASN1_OP_COND_MATCH_ANY_ACT,
    ASN1_OP_MATCH_JUMP,
    ASN1_OP_MATCH_JUMP_OR_SKIP,
    ASN1_OP_COND_MATCH_JUMP_OR_SKIP,
    ASN1_OP_COND_FAIL,
    ASN1_OP_COMPLETE,
    ASN1_OP_ACT,
    ASN1_OP_MAYBE_ACT,
    ASN1_OP_RETURN,
    ASN1_OP_END_SEQ,
    ASN1_OP_END_SET,
    ASN1_OP_END_SEQ_OF,
    ASN1_OP_END_SET_OF,
    ASN1_OP_END_SEQ_ACT,
    ASN1_OP_END_SET_ACT,
    ASN1_OP_END_SEQ_OF_ACT,
    ASN1_OP_END_SET_OF_ACT,
    ASN1_OP__MATCHES_TAG = ASN1_OP_MATCH,
};

#define ASN1_LONG_TAG 0x1f
#define ASN1_CONS_BIT 0x20
#define ASN1_INDEFINITE_LENGTH 0x80
#define EMSGSIZE 90
#define EBADMSG 74

#define ASN1_OP_MATCH__COND 0x01
#define ASN1_OP_MATCH__ANY 0x02
#define ASN1_OP_MATCH__SKIP 0x04

#define ASN1_OP_END__OF 0x01
#define ASN1_OP_END__ACT 0x02

static const unsigned char asn1_op_lengths[] = {
    [ASN1_OP_MATCH] = 2,
    [ASN1_OP_MATCH_OR_SKIP] = 2,
    [ASN1_OP_MATCH_ACT] = 3,
    [ASN1_OP_MATCH_ACT_OR_SKIP] = 3,
    [ASN1_OP_MATCH_ANY] = 1,
    [ASN1_OP_MATCH_ANY_ACT] = 2,
    [ASN1_OP_COND_MATCH_OR_SKIP] = 2,
    [ASN1_OP_COND_MATCH_ACT_OR_SKIP] = 3,
    [ASN1_OP_COND_MATCH_ANY] = 1,
    [ASN1_OP_COND_MATCH_ANY_ACT] = 2,
    [ASN1_OP_MATCH_JUMP] = 3,
    [ASN1_OP_MATCH_JUMP_OR_SKIP] = 3,
    [ASN1_OP_COND_MATCH_JUMP_OR_SKIP] = 3,
    [ASN1_OP_COND_FAIL] = 1,
    [ASN1_OP_COMPLETE] = 1,
    [ASN1_OP_ACT] = 2,
    [ASN1_OP_MAYBE_ACT] = 2,
    [ASN1_OP_RETURN] = 1,
    [ASN1_OP_END_SEQ] = 1,
    [ASN1_OP_END_SET] = 1,
    [ASN1_OP_END_SEQ_OF] = 1,
    [ASN1_OP_END_SET_OF] = 1,
    [ASN1_OP_END_SEQ_ACT] = 1,
    [ASN1_OP_END_SET_ACT] = 1,
    [ASN1_OP_END_SEQ_OF_ACT] = 1,
    [ASN1_OP_END_SET_OF_ACT] = 1,
};

static inline int asn1_find_indefinite_length(const unsigned char *data, size_t datalen,
                        size_t *_dp, size_t *_len, const char **_errmsg)
{
    return 0;
}

#define pr_debug(fmt, ...) 
#define pr_err(fmt, ...) 
#define unlikely(x) (x)