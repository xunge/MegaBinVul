#include <stdint.h>
#include <string.h>
#include <limits.h>

typedef struct amqp_bytes_t_ {
  void *bytes;
  size_t len;
} amqp_bytes_t;

typedef struct amqp_pool_t_ amqp_pool_t;
typedef struct amqp_connection_state_t_ {
  int state;
  size_t inbound_offset;
  size_t target_size;
  int32_t frame_max;
  amqp_bytes_t inbound_buffer;
  char header_buffer[8];
} *amqp_connection_state_t;

typedef struct amqp_frame_t_ {
  int frame_type;
  uint16_t channel;
  union {
    struct {
      uint32_t id;
      void *decoded;
    } method;
    struct {
      uint16_t class_id;
      uint64_t body_size;
      amqp_bytes_t raw;
      void *decoded;
    } properties;
    amqp_bytes_t body_fragment;
    struct {
      uint8_t transport_high;
      uint8_t transport_low;
      uint8_t protocol_version_major;
      uint8_t protocol_version_minor;
    } protocol_header;
  } payload;
} amqp_frame_t;

typedef uint16_t amqp_channel_t;

#define CONNECTION_STATE_IDLE 0
#define CONNECTION_STATE_HEADER 1
#define CONNECTION_STATE_INITIAL 2
#define CONNECTION_STATE_BODY 3

#define AMQP_STATUS_OK 0
#define AMQP_STATUS_BAD_AMQP_DATA 1
#define AMQP_STATUS_NO_MEMORY 2

#define AMQP_PSEUDOFRAME_PROTOCOL_HEADER -1
#define AMQP_FRAME_METHOD 1
#define AMQP_FRAME_HEADER 2
#define AMQP_FRAME_BODY 3
#define AMQP_FRAME_HEARTBEAT 8
#define AMQP_FRAME_END 0xCE

#define HEADER_SIZE 7
#define FOOTER_SIZE 1

static size_t consume_data(amqp_connection_state_t state, amqp_bytes_t *received_data);
static void return_to_idle(amqp_connection_state_t state);
static amqp_pool_t *amqp_get_or_create_channel_pool(amqp_connection_state_t state, amqp_channel_t channel);
static int amqp_pool_alloc_bytes(amqp_pool_t *pool, size_t amount, amqp_bytes_t *out);
static int amqp_decode_method(uint32_t id, amqp_pool_t *pool, amqp_bytes_t encoded, void **decoded);
static int amqp_decode_properties(uint16_t class_id, amqp_pool_t *pool, amqp_bytes_t encoded, void **decoded);
static void *amqp_offset(void *data, size_t offset);
static uint8_t amqp_d8(void *data);
static uint16_t amqp_d16(void *data);
static uint32_t amqp_d32(void *data);
static uint64_t amqp_d64(void *data);
static void amqp_abort(const char *fmt, ...);