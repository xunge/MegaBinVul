#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#define LOG_LEVEL_VERBOSE 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_INFO 2

#define KEX_FLAG_KEXDONE 1
#define KEX_FLAG_REKEYING 2
#define SSH2_COOKIE_LENGTH 16
#define PROPOSAL_KEX_ALGS 0
#define PROPOSAL_SERVER_HOST_KEY_ALGS 1
#define PROPOSAL_ENC_ALGS_CTOS 2
#define PROPOSAL_ENC_ALGS_STOC 3
#define PROPOSAL_MAC_ALGS_CTOS 4
#define PROPOSAL_MAC_ALGS_STOC 5
#define PROPOSAL_COMP_ALGS_CTOS 6
#define PROPOSAL_COMP_ALGS_STOC 7

#define MODE_OUT 0
#define MODE_IN 1

#define KEX_DH_UNKNOWN 0
#define KEX_DH_GRP1_SHA1 1
#define KEX_DH_GRP14_SHA1 2
#define KEX_DH_GRP14_SHA256 3
#define KEX_DH_GRP16_SHA512 4
#define KEX_DH_GRP18_SHA512 5
#define KEX_DH_GEX_SHA1 6
#define KEX_DH_GEX_SHA256 7
#define KEX_ECDH_SHA2_256 8
#define KEX_ECDH_SHA2_384 9
#define KEX_ECDH_SHA2_521 10

#define KEY_ALGO_UNSPEC 0
#define COMP_UNKNOWN 0
#define HMAC_IMPLICIT 0

#define GetPayloadError 1
#define GetPayloadTruncate 2

#define _TRUNCATE ((size_t)-1)

typedef struct TInstVar {
    int kex_status;
    void *peer_kex;
    int kex_type;
    int hostkey_type;
    void *ciphers[2];
    void *macs[2];
    int ctos_compression;
    int stoc_compression;
    int server_strict_kex;
} TInstVar, *PTInstVar;

extern char *myproposal[];
extern void logputs(int level, const char *msg);
extern void logprintf(int level, const char *format, ...);
extern void push_memdump(const char *tag, const char *desc, const char *data, int len);
extern void notify_fatal_error(PTInstVar pvar, const char *msg, BOOL flag);
extern void SSH2_update_kex_myproposal(PTInstVar pvar);
extern void SSH2_send_kexinit(PTInstVar pvar);
extern char *remained_payload(PTInstVar pvar);
extern int remained_payloadlen(PTInstVar pvar);
extern void *buffer_init();
extern void buffer_clear(void *buffer);
extern void buffer_append(void *buffer, const char *data, int len);
extern void buffer_free(void *buffer);
extern BOOL get_bytearray_from_payload(PTInstVar pvar, char *buf, int len);
extern void CRYPT_set_server_cookie(PTInstVar pvar, const char *buf);
extern int get_namelist_from_payload(PTInstVar pvar, char *buf, int size, int *len);
extern int choose_SSH2_kex_algorithm(const char *buf, const char *proposal);
extern void choose_SSH2_proposal(const char *buf, const char *proposal, char *tmp, int size);
extern int choose_SSH2_host_key_algorithm(const char *buf, const char *proposal);
extern void *choose_SSH2_cipher_algorithm(const char *buf, const char *proposal);
extern int get_cipher_auth_len(void *cipher);
extern void *get_ssh2_mac(int type);
extern void *choose_SSH2_mac_algorithm(const char *buf, const char *proposal);
extern int choose_SSH2_compression_algorithm(const char *buf, const char *proposal);
extern BOOL get_boolean_from_payload(PTInstVar pvar, char *buf);
extern BOOL get_uint32_from_payload(PTInstVar pvar, int *size);
extern const char *get_kex_algorithm_name(int type);
extern const char *get_ssh2_hostkey_algorithm_name(int type);
extern const char *get_cipher_string(void *cipher);
extern const char *get_ssh2_mac_name(void *mac);
extern const char *get_ssh2_comp_name(int type);
extern void choose_SSH2_key_maxlength(PTInstVar pvar);
extern void SSH2_dh_kex_init(PTInstVar pvar);
extern void SSH2_dh_gex_kex_init(PTInstVar pvar);
extern void SSH2_ecdh_kex_init(PTInstVar pvar);

int _snprintf_s(char *buffer, size_t sizeOfBuffer, size_t count, const char *format, ...);
int strncpy_s(char *dest, size_t destsz, const char *src, size_t count);
int strncat_s(char *dest, size_t destsz, const char *src, size_t count);