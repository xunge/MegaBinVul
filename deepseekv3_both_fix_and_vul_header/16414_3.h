typedef void* gpointer;

struct quic_ciphers {
    void* cipher_data;
};

struct quic_hp_cipher {
    void* hp_data;
};

struct quic_pp_cipher {
    void* pp_data;
};

typedef struct {
    struct quic_hp_cipher hp_cipher;
    struct quic_pp_cipher pp_ciphers[2];
} quic_pp_t;

typedef struct quic_info_data {
    struct quic_ciphers client_initial_ciphers;
    struct quic_ciphers server_initial_ciphers;
    struct quic_ciphers client_handshake_ciphers;
    struct quic_ciphers server_handshake_ciphers;
    struct quic_ciphers client_0rtt_ciphers;
    quic_pp_t client_pp;
    quic_pp_t server_pp;
} quic_info_data_t;

void quic_ciphers_reset(struct quic_ciphers *ciphers);
void quic_hp_cipher_reset(struct quic_hp_cipher *hp_cipher);
void quic_pp_cipher_reset(struct quic_pp_cipher *pp_cipher);

#define _U_