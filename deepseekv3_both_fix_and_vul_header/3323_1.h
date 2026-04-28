typedef struct {
    int is_ccs;
    struct {
        void *enc_write_ctx;
        void *write_hash;
    } saved_retransmit_state;
} msg_header_t;

typedef struct hm_fragment_st {
    msg_header_t msg_header;
    unsigned char *fragment;
    unsigned char *reassembly;
} hm_fragment;

void OPENSSL_free(void *ptr);
void EVP_CIPHER_CTX_free(void *ctx);
void EVP_MD_CTX_destroy(void *ctx);