#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_HMAC_KEY_LENGTH 64
#define OPENVPN_MAX_IV_LENGTH 32
#define D_PACKET_CONTENT 0
#define D_REPLAY_ERRORS 0
#define D_REPLAY_WARNINGS 0

#define BOOL_CAST(x) (x)
#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define CRYPT_ERROR(msg) do { goto error_exit; } while (0)
#define ASSERT(x) do { if (!(x)) CRYPT_ERROR("assertion failed"); } while (0)

struct buffer {
    uint8_t *data;
    int len;
};

struct gc_arena {
    void *ptr;
};

struct key_ctx {
    void *hmac;
    void *cipher;
};

struct key_ctx_bi {
    struct key_ctx encrypt;
    struct key_ctx decrypt;
};

struct packet_id_rec {
    uint32_t id;
    uint32_t time;
};

struct packet_id {
    struct packet_id_rec rec;
};

struct packet_id_net {
    uint32_t id;
    uint32_t time;
};

struct pid_persist {
    void *data;
};

struct crypto_options {
    struct key_ctx_bi *key_ctx_bi;
    struct packet_id *packet_id;
    struct pid_persist *pid_persist;
    unsigned int flags;
};

struct frame {
    int size;
};

#define FRAME_HEADROOM 0
#define FRAME_HEADROOM_MARKER_DECRYPT 0
#define FRAME_HEADROOM_ADJ(frame, marker) (0)

#define CO_USE_IV (1 << 0)
#define CO_PACKET_ID_LONG_FORM (1 << 1)
#define CO_IGNORE_PACKET_ID (1 << 2)
#define CO_MUTE_REPLAY_WARNINGS (1 << 3)

#define OPENVPN_MODE_CBC 0
#define OPENVPN_MODE_CFB 1
#define OPENVPN_MODE_OFB 2

static inline void gc_init(struct gc_arena *gc) {}
static inline void gc_free(struct gc_arena *gc) {}
static inline void crypto_clear_error(void) {}
static inline void msg(int level, const char *format, ...) {}
static inline void dmsg(int level, const char *format, ...) {}
static inline char *format_hex(const uint8_t *data, int len, int max, struct gc_arena *gc) { return NULL; }
static inline char *packet_id_net_print(const struct packet_id_net *pin, bool print, struct gc_arena *gc) { return NULL; }
static inline void hmac_ctx_reset(void *ctx) {}
static inline int hmac_ctx_size(void *ctx) { return 0; }
static inline void hmac_ctx_update(void *ctx, const uint8_t *data, int len) {}
static inline void hmac_ctx_final(void *ctx, uint8_t *out) {}
static inline bool buf_advance(struct buffer *buf, int len) { return true; }
static inline bool buf_init(struct buffer *buf, int size) { return true; }
static inline bool buf_safe(const struct buffer *buf, int len) { return true; }
static inline void buf_set_read(struct buffer *buf, const uint8_t *data, int len) {}
static inline unsigned int cipher_ctx_mode(void *ctx) { return 0; }
static inline int cipher_ctx_iv_length(void *ctx) { return 0; }
static inline bool cipher_ctx_reset(void *ctx, const uint8_t *iv) { return true; }
static inline bool cipher_ctx_update(void *ctx, uint8_t *out, int *outlen, const uint8_t *in, int inlen) { return true; }
static inline bool cipher_ctx_final(void *ctx, uint8_t *out, int *outlen) { return true; }
static inline bool packet_id_read(struct packet_id_net *pin, struct buffer *buf, bool long_form) { return true; }
static inline void packet_id_reap_test(struct packet_id_rec *rec) {}
static inline bool packet_id_test(struct packet_id_rec *rec, const struct packet_id_net *pin) { return true; }
static inline void packet_id_add(struct packet_id_rec *rec, const struct packet_id_net *pin) {}
static inline void packet_id_persist_save_obj(struct pid_persist *pid_persist, struct packet_id *pid) {}

#define BPTR(buf) ((buf)->data)
#define BLEN(buf) ((buf)->len)