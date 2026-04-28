#include <stdint.h>
#include <stddef.h>

typedef int gboolean;
#define FALSE 0
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *cinfo;
} packet_info;
typedef struct expert_field expert_field;

#define MAX_DECOMPRESSION_SIZE 0
#define KAFKA_MESSAGE_CODEC_SNAPPY 1
#define KAFKA_MESSAGE_CODEC_LZ4 2
#define KAFKA_MESSAGE_CODEC_ZSTD 3
#define KAFKA_MESSAGE_CODEC_GZIP 4
#define KAFKA_MESSAGE_CODEC_NONE 5
#define COL_INFO 0

extern expert_field ei_kafka_bad_decompression_length;

void expert_add_info(packet_info *pinfo, void *null, expert_field *field);
void col_append_str(void *cinfo, int col, const char *str);

gboolean decompress_snappy(tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 length, tvbuff_t **decompressed_tvb, int *decompressed_offset);
gboolean decompress_lz4(tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 length, tvbuff_t **decompressed_tvb, int *decompressed_offset);
gboolean decompress_zstd(tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 length, tvbuff_t **decompressed_tvb, int *decompressed_offset);
gboolean decompress_gzip(tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 length, tvbuff_t **decompressed_tvb, int *decompressed_offset);
gboolean decompress_none(tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 length, tvbuff_t **decompressed_tvb, int *decompressed_offset);