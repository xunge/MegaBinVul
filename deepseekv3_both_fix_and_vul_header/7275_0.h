#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct ok_jpg_decoder ok_jpg_decoder;
typedef struct ok_jpg_component ok_jpg_component;

void ok_jpg_decode_restart(ok_jpg_decoder *decoder);
bool ok_jpg_decode_restart_if_needed(ok_jpg_decoder *decoder);
void ok_jpg_decode_block_subsequent_scan(ok_jpg_decoder *decoder, ok_jpg_component *c, int16_t *block);
void ok_jpg_decode_block_progressive(ok_jpg_decoder *decoder, ok_jpg_component *c, int16_t *block);
void ok_jpg_decode_block(ok_jpg_decoder *decoder, ok_jpg_component *c, int16_t *block);
void ok_jpg_convert_data_unit(ok_jpg_decoder *decoder, int data_unit_x, int data_unit_y);
void ok_jpg_dump_bits(ok_jpg_decoder *decoder);

struct ok_jpg_component {
    int blocks_v;
    int blocks_h;
    int16_t *blocks;
    size_t next_block;
    int H;
    int V;
    uint8_t *output;
    bool complete;
    void (*idct)(int16_t *block, uint8_t *output);
};

struct ok_jpg_decoder {
    int next_restart;
    int restart_intervals_remaining;
    bool progressive;
    int scan_prev_scale;
    int num_scan_components;
    int *scan_components;
    ok_jpg_component *components;
    int data_units_x;
    int data_units_y;
    bool eof_found;
    bool huffman_error;
    int scan_end;
    int scan_scale;
};

#define C_WIDTH 8