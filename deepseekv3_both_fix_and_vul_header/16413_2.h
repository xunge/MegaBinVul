#include <stdint.h>
#include <stddef.h>

#define QUIC_MAX_CID_LENGTH 20
#define TRUE 1
#define FALSE 0
typedef int gboolean;
typedef unsigned int guint;
typedef uint8_t guint8;

typedef struct {
    uint8_t cid[QUIC_MAX_CID_LENGTH];
    uint8_t len;
} quic_cid_t;

typedef struct {
    quic_cid_t data;
} quic_cids_t;

typedef struct {
    quic_cids_t client_cids;
    quic_cids_t server_cids;
} quic_info_data_t;

typedef struct {
    quic_info_data_t *conn;
    gboolean from_server;
} quic_datagram;

typedef struct tvbuff tvbuff_t;

uint8_t tvb_get_guint8(const tvbuff_t *tvb, int offset);
void tvb_memcpy(const tvbuff_t *tvb, void *dest, int offset, size_t length);
gboolean quic_connection_equal(const quic_cid_t *cid1, const quic_cid_t *cid2);