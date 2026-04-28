#include <string.h>
#include <stdlib.h>

struct sc_context;
struct sc_card;
struct sc_path;
struct sc_file;
struct sc_apdu;

#define SC_SUCCESS 0
#define SC_ERROR_NOT_SUPPORTED 1
#define SC_ERROR_FILE_NOT_FOUND 2
#define SC_ERROR_OUT_OF_MEMORY 3
#define SC_ERROR_INCORRECT_PARAMETERS 4
#define SC_ERROR_UNKNOWN_DATA_RECEIVED 5

#define SC_APDU_CASE_2_SHORT 0
#define SC_APDU_CASE_4_SHORT 1

#define SC_PATH_TYPE_DF_NAME 0
#define SC_PATH_TYPE_FROM_CURRENT 1
#define SC_PATH_TYPE_PATH 2
#define SC_PATH_TYPE_FILE_ID 3
#define SC_PATH_TYPE_PARENT 4

#define SC_FILE_TYPE_DF 0
#define SC_FILE_TYPE_EF 1

#define SC_MAX_APDU_BUFFER_SIZE 256

#define SC_CARD_TYPE_IASECC_GEMALTO 0
#define SC_CARD_TYPE_IASECC_OBERTHUR 1
#define SC_CARD_TYPE_IASECC_SAGEM 2
#define SC_CARD_TYPE_IASECC_AMOS 3
#define SC_CARD_TYPE_IASECC_MI 4
#define SC_CARD_TYPE_IASECC_MI2 5

#define SC_FORMAT_LEN_SIZE_T "zu"

struct sc_context {
    // Placeholder for context structure
};

struct sc_path {
    unsigned char value[256];
    size_t len;
    int type;
    struct {
        unsigned char value[256];
        size_t len;
    } aid;
};

struct sc_file {
    int type;
    struct sc_path path;
    struct {
        unsigned char value[256];
        size_t len;
    } aid;
};

struct sc_apdu {
    int cse;
    int p1;
    int p2;
    int lc;
    const unsigned char *data;
    size_t datalen;
    unsigned char *resp;
    size_t resplen;
    int le;
    unsigned char sw1;
    unsigned char sw2;
};

struct sc_card_cache {
    int valid;
    struct sc_file *current_df;
    struct sc_file *current_ef;
};

struct sc_card {
    struct sc_context *ctx;
    struct sc_card_cache cache;
    int type;
    struct sc_file *ef_atr;
};

void LOG_FUNC_CALLED(struct sc_context *ctx);
void LOG_FUNC_RETURN(struct sc_context *ctx, int rv);
void LOG_TEST_RET(struct sc_context *ctx, int rv, const char *msg);
void sc_log(struct sc_context *ctx, const char *fmt, ...);
char *sc_print_path(const struct sc_path *path);
char *sc_dump_hex(const unsigned char *data, size_t len);
void sc_print_cache(struct sc_card *card);
int iasecc_select_mf(struct sc_card *card, struct sc_file **file_out);
void sc_file_free(struct sc_file *file);
void sc_file_dup(struct sc_file **dst, const struct sc_file *src);
int sc_transmit_apdu(struct sc_card *card, struct sc_apdu *apdu);
int sc_check_sw(struct sc_card *card, unsigned char sw1, unsigned char sw2);
int iasecc_emulate_fcp(struct sc_context *ctx, struct sc_apdu *apdu);
void sc_invalidate_cache(struct sc_card *card);
struct sc_file *sc_file_new(void);
int iasecc_process_fci(struct sc_card *card, struct sc_file *file, const unsigned char *data, size_t len);
void sc_format_apdu(struct sc_card *card, struct sc_apdu *apdu, int cse, int ins, int p1, int p2);