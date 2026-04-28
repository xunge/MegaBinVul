#include <stdint.h>
#include <endian.h>
#include <stdbool.h>
#include <stddef.h>

struct eapol_sm;
struct eapol_key;
struct handshake_state;

struct eapol_key {
    uint64_t key_replay_counter;
};

struct eapol_sm {
    struct handshake_state *handshake;
    uint64_t replay_counter;
    unsigned int mic_len;
    void *timeout;
};

struct handshake_state {
    unsigned int ifindex;
    bool have_snonce;
    bool ptk_complete;
    unsigned int akm_suite;
};

const uint8_t *handshake_state_get_kck(struct handshake_state *hs);
bool eapol_verify_ptk_4_of_4(const struct eapol_key *ek, bool b);
bool eapol_verify_mic(unsigned int akm_suite, const uint8_t *kck, 
                     const struct eapol_key *ek, unsigned int mic_len);
void handshake_state_install_ptk(struct handshake_state *hs);
void l_timeout_remove(void *timeout);
void l_debug(const char *format, ...);

#define L_BE64_TO_CPU(be64) be64toh(be64)