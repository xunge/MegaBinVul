#include <stdio.h>
#include <string.h>

#define CHAP_CHALLENGE_LENGTH 16
#define unlikely(x) __builtin_expect(!!(x), 0)

struct iscsi_conn;
struct iscsi_chap;

extern int get_random_bytes_wait(unsigned char *buf, int len);
extern void chap_binaryhex_to_asciihex(char *asciihex, unsigned char *binaryhex, int len);
extern int pr_debug(const char *fmt, ...);

struct iscsi_conn {
    struct iscsi_chap *auth_protocol;
};

struct iscsi_chap {
    unsigned char challenge[CHAP_CHALLENGE_LENGTH];
};