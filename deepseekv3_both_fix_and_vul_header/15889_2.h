#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define VLC_EGENERIC (-1)
#define VLC_SUCCESS (0)
#define XIPH_IDENT (0x4F676753)
#define __MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct sout_stream_id_sys_t sout_stream_id_sys_t;

struct block_t {
    uint8_t *p_buffer;
    int64_t i_dts;
};

typedef struct block_t block_t;

int rtp_mtu(sout_stream_id_sys_t *id);
int vlc_b64_decode_binary(uint8_t **pp, const char *psz_b64);
block_t *block_Alloc(size_t);
void rtp_packetize_common(sout_stream_id_sys_t *id, block_t *out, int zero, int64_t i_pts);
void rtp_packetize_send(sout_stream_id_sys_t *id, block_t *out);
void SetDWBE(uint8_t *p, uint32_t val);
void SetWBE(uint8_t *p, uint16_t val);