#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;

#define MAX_EXT_APDU_LENGTH 256
#define SC_SUCCESS 0
#define SC_ERROR_OUT_OF_MEMORY -1
#define SC_ERROR_DATA_OBJECT_NOT_FOUND -2
#define SC_ERROR_INCORRECT_PARAMETERS -3
#define SC_PATH_TYPE_DF_NAME 1
#define SC_PKCS15_PIN_AUTH_TYPE_PIN 1
#define SC_PKCS15_PIN_FLAG_LOCAL 1
#define SC_PKCS15_PIN_FLAG_INITIALIZED 2
#define SC_PKCS15_PIN_FLAG_EXCHANGE_REF_DATA 4
#define SC_PKCS15_PIN_FLAG_UNBLOCK_DISABLED 8
#define SC_PKCS15_PIN_FLAG_SO_PIN 16
#define SC_PKCS15_PIN_TYPE_ASCII_NUMERIC 1
#define SC_PKCS15_PIN_TYPE_BCD 2
#define SC_PKCS15_CO_FLAG_PRIVATE 1
#define SC_PKCS15_CO_FLAG_MODIFIABLE 2
#define SC_AC_CHV 1
#define SC_PIN_CMD_GET_INFO 1
#define SC_CARD_CAP_PROTECTED_AUTHENTICATION_PATH 1
#define KEY_PREFIX 0
#define DCOD_PREFIX 1
#define CD_PREFIX 2
#define SC_CARD_TYPE_SC_HSM_GOID 1
#define SC_CARD_TYPE_SC_HSM_SOC 2

typedef struct {
    unsigned char *value;
    size_t len;
} sc_aid_t;

typedef struct sc_app_info {
    sc_aid_t aid;
    struct {
        sc_aid_t aid;
    } ddo;
    char *label;
} sc_app_info_t;

typedef struct sc_pkcs15_auth_info {
    struct {
        size_t len;
        unsigned char value[1];
    } auth_id;
    struct {
        sc_aid_t aid;
    } path;
    int auth_type;
    struct {
        struct {
            int reference;
            int flags;
            int type;
            int min_length;
            int stored_length;
            int max_length;
            char pad_char;
        } pin;
    } attrs;
    int tries_left;
    int max_tries;
} sc_pkcs15_auth_info_t;

typedef struct sc_pkcs15_object {
    struct {
        size_t len;
        unsigned char value[1];
    } auth_id;
    char label[8];
    int flags;
} sc_pkcs15_object_t;

typedef struct sc_pin_cmd_data {
    int cmd;
    int pin_type;
    int pin_reference;
} sc_pin_cmd_data_t;

typedef struct {
    char chr[256];
} sc_cvc_t;

typedef struct {
    struct {
        int hw_major;
        int hw_minor;
        int fw_major;
        int fw_minor;
    } version;
    int type;
    int caps;
    void *drv_data;
    void *ctx;
} sc_card_t;

typedef struct {
    char *label;
    char *manufacturer_id;
    char *serial_number;
} sc_tokeninfo_t;

typedef struct {
    sc_card_t *card;
    sc_tokeninfo_t *tokeninfo;
    sc_app_info_t *app;
} sc_pkcs15_card_t;

typedef struct {
    u8 *EF_C_DevAut;
    size_t EF_C_DevAut_len;
} sc_hsm_private_data_t;

typedef struct {
    int type;
    unsigned char *value;
    size_t len;
    int unknown1;
    int unknown2;
} sc_path_t;

typedef struct {
    unsigned char *prop_attr;
    size_t prop_attr_len;
} sc_file_t;

static sc_aid_t sc_hsm_aid;

static size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t src_len = strlen(src);
    size_t copy_len = src_len < size ? src_len : size - 1;
    if (size > 0) {
        memcpy(dst, src, copy_len);
        dst[copy_len] = '\0';
    }
    return src_len;
}

static void LOG_FUNC_CALLED(void *ctx) {}
static void LOG_FUNC_RETURN(void *ctx, int ret) {}
static void LOG_TEST_RET(void *ctx, int ret, const char *msg) {}