#include <string.h>
#include <sys/types.h>

#define E_SSID 0
#define E_CHALLENGE 1
#define E_RATES 2
#define E_DS 3
#define E_CF 4
#define E_TIM 5

typedef struct netdissect_options netdissect_options;
typedef unsigned char u_char;
typedef unsigned int u_int;

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
    char rate[8];
};

struct ds_t {
    u_int length;
    char channel;
};

struct cf_t {
    u_int length;
    char count[6];
};

struct tim_t {
    u_int length;
    char count[3];
    char bitmap[251];
};

struct mgmt_body_t {
    int challenge_present;
    int ssid_present;
    int rates_present;
    int ds_present;
    int cf_present;
    int tim_present;
    struct ssid_t ssid;
    struct challenge_t challenge;
    struct rates_t rates;
    struct ds_t ds;
    struct cf_t cf;
    struct tim_t tim;
};

#define ND_TTEST2(a, b) 1
#define ND_PRINT(a, b)