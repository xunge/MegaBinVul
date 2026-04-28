#include <stdint.h>
#include <string.h>

#define AV_LOG_ERROR 16

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct QDM2SubPacket {
    int type;
    int size;
    uint8_t *data;
} QDM2SubPacket;

typedef struct QDM2Context {
    uint8_t *compressed_data;
    int compressed_size;
    int checksum_size;
    int has_errors;
    int superblocktype_2_3;
    int sub_packets_B;
    int fft_level_exp[6];
    uint8_t tone_level_idx_hi1[32];
    uint8_t tone_level_idx_mid[32];
    uint8_t tone_level_idx_hi2[32];
    QDM2SubPacket sub_packets[6];
    struct {
        QDM2SubPacket *packet;
        void *next;
    } sub_packet_list_A[6], sub_packet_list_B[6], sub_packet_list_D[6];
    int do_synth_filter;
} QDM2Context;

extern void average_quantized_coeffs(QDM2Context *q);
extern void init_get_bits(GetBitContext *gb, const uint8_t *buf, int bit_size);
extern void qdm2_decode_sub_packet_header(GetBitContext *gb, QDM2SubPacket *header);
extern int get_bits_count(GetBitContext *gb);
extern int get_bits(GetBitContext *gb, int n);
extern int qdm2_packet_checksum(const uint8_t *data, int size, int checksum);
extern void skip_bits(GetBitContext *gb, int n);
extern int qdm2_get_vlc(GetBitContext *gb, void *vlc, int flag, int depth);
extern void process_synthesis_subpackets(QDM2Context *q, void *list);
extern void process_subpacket_10(QDM2Context *q, void *null);
extern void process_subpacket_11(QDM2Context *q, void *null);
extern void process_subpacket_12(QDM2Context *q, void *null);
extern void av_log(void *avcl, int level, const char *fmt, ...);

#define SAMPLES_NEEDED_2(reason) 
#define QDM2_LIST_ADD(list, count, packet) \
    do { \
        int pos = count++; \
        list[pos].packet = packet; \
        list[pos].next = &list[pos+1]; \
    } while (0)

static const int fft_subpackets[32] = {0};
static const void *fft_level_exp_vlc = NULL;