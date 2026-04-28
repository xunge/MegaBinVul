#include <stdint.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#define LOG_LEVEL_VERBOSE 1
#define LOG_LEVEL_SSHDUMP 2
#define LOGDUMP 0

#define MODE_IN 0
#define CHANNEL_MAX 32
#define SSH2_MSG_NEWKEYS 21
#define SSH2_MSG_EXT_INFO 7

#define KEX_FLAG_NEWKEYS_RECEIVED (1 << 0)
#define KEX_FLAG_NEWKEYS_SENT (1 << 1)
#define KEX_FLAG_REKEYING (1 << 2)
#define KEX_FLAG_KEXDONE (1 << 3)

typedef struct {
    int enabled;
} MacComp_t;

typedef struct {
    MacComp_t mac;
    MacComp_t comp;
} SSH2Keys_t;

typedef struct {
    uint32_t receiver_sequence_number;
} SSHState_t;

typedef struct {
    int used;
} Channel_t;

typedef struct {
    int kex_status;
    SSH2Keys_t ssh2_keys[2];
    int server_strict_kex;
    SSHState_t ssh_state;
} TInstVar;

typedef TInstVar* PTInstVar;

extern Channel_t channels[CHANNEL_MAX];

void logputs(int level, const char* msg);
int LogLevel(PTInstVar pvar, int level);
void save_memdump(int type);
void finish_memdump();
void ssh2_set_newkeys(PTInstVar pvar, int mode);
int CRYPT_start_encryption(PTInstVar pvar, int a, int b);
void enable_recv_compression(PTInstVar pvar);
void SSH2_dispatch_add_message(int msg);
void do_SSH2_dispatch_setup_for_transfer(PTInstVar pvar);
void ssh2_channel_retry_send_bufchain(PTInstVar pvar, Channel_t* c);
void ssh2_finish_encryption_setup(PTInstVar pvar);
void ssh2_prep_userauth(PTInstVar pvar);