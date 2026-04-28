#include <stdint.h>
#include <string.h>

#define _PASSWORD_EFMT1 '*'

typedef unsigned char u_char;

struct php_crypt_extended_data {
    int initialized;
    char output[25];
};

extern int des_init_local(struct php_crypt_extended_data *);
extern int des_setkey(u_char *, struct php_crypt_extended_data *);
extern int des_cipher(u_char *, u_char *, int, int, struct php_crypt_extended_data *);
extern int ascii_to_bin(int);
extern int ascii_is_unsafe(int);
extern void setup_salt(uint32_t, struct php_crypt_extended_data *);
extern int do_des(int, int, uint32_t *, uint32_t *, uint32_t, struct php_crypt_extended_data *);

static const char ascii64[] =
    "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";