#include <stddef.h>

typedef struct X509_st {
    struct X509_POLICY_CACHE_st *policy_cache;
    void *lock;
    unsigned long ex_flags;
} X509;

typedef struct POLICY_MAPPING_st {
    struct asn1_object_st *subjectDomainPolicy;
    struct asn1_object_st *issuerDomainPolicy;
} POLICY_MAPPING;

typedef struct stack_st_POLICY_MAPPING {
    POLICY_MAPPING *data;
    int num;
} STACK_OF_POLICY_MAPPING;
typedef STACK_OF_POLICY_MAPPING POLICY_MAPPINGS;

typedef struct X509_POLICY_DATA_st {
    unsigned long flags;
    struct stack_st_ASN1_OBJECT *expected_policy_set;
    void *qualifier_set;
} X509_POLICY_DATA;

typedef struct X509_POLICY_CACHE_st {
    struct X509_POLICY_DATA_st *anyPolicy;
    struct stack_st_X509_POLICY_DATA *data;
} X509_POLICY_CACHE;

typedef struct asn1_object_st ASN1_OBJECT;
typedef struct stack_st_ASN1_OBJECT STACK_OF_ASN1_OBJECT;
typedef struct stack_st_X509_POLICY_DATA STACK_OF_X509_POLICY_DATA;

#define NID_any_policy 0
#define POLICY_DATA_FLAG_CRITICAL 1
#define POLICY_DATA_FLAG_MAPPED_ANY 2
#define POLICY_DATA_FLAG_SHARED_QUALIFIERS 4
#define POLICY_DATA_FLAG_MAPPED 8
#define EXFLAG_INVALID_POLICY 16

int sk_POLICY_MAPPING_num(const STACK_OF_POLICY_MAPPING *sk);
POLICY_MAPPING *sk_POLICY_MAPPING_value(const STACK_OF_POLICY_MAPPING *sk, int idx);
int sk_X509_POLICY_DATA_push(STACK_OF_X509_POLICY_DATA *sk, X509_POLICY_DATA *ptr);
int sk_ASN1_OBJECT_push(STACK_OF_ASN1_OBJECT *sk, ASN1_OBJECT *ptr);
void sk_POLICY_MAPPING_pop_free(STACK_OF_POLICY_MAPPING *sk, void (*freefunc)(POLICY_MAPPING*));

int OBJ_obj2nid(const ASN1_OBJECT *o);
int CRYPTO_THREAD_write_lock(void *lock);
void CRYPTO_THREAD_unlock(void *lock);

X509_POLICY_DATA *ossl_policy_cache_find_data(X509_POLICY_CACHE *cache, ASN1_OBJECT *id);
X509_POLICY_DATA *ossl_policy_data_new(void *qual, ASN1_OBJECT *id, int crit);
void ossl_policy_data_free(X509_POLICY_DATA *data);
void POLICY_MAPPING_free(POLICY_MAPPING *map);