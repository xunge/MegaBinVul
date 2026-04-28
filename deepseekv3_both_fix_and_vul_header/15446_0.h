#include <stdint.h>

#define SSH2_MSG_NEWKEYS 21
#define MODE_OUT 0
#define KEX_FLAG_NEWKEYS_SENT (1 << 0)
#define KEX_FLAG_NEWKEYS_RECEIVED (1 << 1)
#define KEX_FLAG_REKEYING (1 << 2)
#define KEX_FLAG_KEXDONE (1 << 3)
#define LOG_LEVEL_VERBOSE 1

typedef struct {
    int enabled;
} MacComp;

typedef struct {
    MacComp mac;
    MacComp comp;
} SSH2Keys;

typedef struct {
    int sender_sequence_number;
} SSHState;

typedef struct {
    SSH2Keys ssh2_keys[2];
    uint32_t kex_status;
    int server_strict_kex;
    SSHState ssh_state;
} TInstVar;

typedef TInstVar* PTInstVar;

void begin_send_packet(PTInstVar pvar, int msg, int flags);
void finish_send_packet(PTInstVar pvar);
void logprintf(int level, const char* format, ...);
void ssh2_set_newkeys(PTInstVar pvar, int mode);
int CRYPT_start_encryption(PTInstVar pvar, int a, int b);
void enable_send_compression(PTInstVar pvar);
void do_SSH2_dispatch_setup_for_transfer(PTInstVar pvar);
void ssh2_finish_encryption_setup(PTInstVar pvar);
void ssh2_prep_userauth(PTInstVar pvar);