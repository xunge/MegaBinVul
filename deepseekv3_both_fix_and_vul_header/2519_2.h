#include <string.h>
#include <stdint.h>

#define E_SSID 0
#define E_CHALLENGE 1
#define E_RATES 2
#define E_DS 3
#define E_CF 4
#define E_TIM 5

typedef struct netdissect_options netdissect_options;
typedef uint8_t u_char;
typedef uint32_t u_int;

struct ssid_t {
    u_int length;
    char ssid[256];
};

struct challenge_t {
    u_int length;
    char text[256];
};

struct rates_t {
    u_int length;
    u_char rate[8];
};

struct ds_t {
    u_int length;
    u_char channel;
};

struct cf_t {
    u_int length;
    u_char count[6];
};

struct tim_t {
    u_int length;
    u_char count[3];
    u_char bitmap[251];
};

struct mgmt_body_t {
    struct ssid_t ssid;
    int ssid_present;
    struct challenge_t challenge;
    int challenge_present;
    struct rates_t rates;
    int rates_present;
    struct ds_t ds;
    int ds_present;
    struct cf_t cf;
    int cf_present;
    struct tim_t tim;
    int tim_present;
};

#define ND_TTEST2(p, l) 1