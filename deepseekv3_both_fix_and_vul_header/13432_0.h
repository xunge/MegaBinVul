#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

#define NCRX_LINE_MAX 1024

struct ncrx_msg {
    uint8_t facility;
    uint8_t level;
    uint64_t seq;
    uint64_t ts_usec;
    unsigned int cont_start : 1;
    unsigned int cont : 1;
    unsigned int emg : 1;
    unsigned int ncfrag_off;
    unsigned int ncfrag_len;
    unsigned int ncfrag_left;
    const char *text;
    size_t text_len;
};