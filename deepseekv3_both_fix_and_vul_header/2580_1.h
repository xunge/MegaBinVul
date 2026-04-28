#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

typedef unsigned char u_char;

typedef struct netdissect_options {
    int ndo_eflag;
} netdissect_options;

#define ND_PRINT(args) printf args
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

static const char *ppp_ml_flag_values[] = {
    NULL
};

static const char *bittok2str(const char *strings[], const char *default_str, int value) {
    return default_str;
}