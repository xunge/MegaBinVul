#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <limits.h>

struct pb_ostream_t {
    bool (*callback)(pb_ostream_t *stream, const uint8_t *buf, size_t count);
    void *state;
    size_t max_size;
    size_t bytes_written;
};

struct pb_bytes_array_t {
    size_t size;
    uint8_t bytes[1];
};

enum MsgType {
    MsgType_REQUEST,
    MsgType_RESPONSE,
    MsgType_UNSOL_RESPONSE
};

enum MsgId {
    MsgId_RIL_SIM_SAP_DISCONNECT
};

enum Error {
    Error_RIL_E_SUCCESS
};

struct MsgHeader {
    pb_bytes_array_t *payload;
    MsgType type;
    MsgId id;
    Error error;
};

struct RIL_SIM_SAP_DISCONNECT_REQ {
    // Add actual fields here
};

extern const void* RIL_SIM_SAP_DISCONNECT_REQ_fields;
extern bool pb_get_encoded_size(size_t *size, const void *fields, const void *src);
extern pb_ostream_t pb_ostream_from_buffer(uint8_t *buf, size_t bufsize);
extern bool pb_encode(pb_ostream_t *stream, const void *fields, const void *src);
extern bool pb_write(pb_ostream_t *stream, const uint8_t *buf, size_t count);
extern void RLOGE(const char *msg);
extern void dispatchDisconnect(MsgHeader *hdr);

class RilSapSocket {
public:
    void sendDisconnect();
};