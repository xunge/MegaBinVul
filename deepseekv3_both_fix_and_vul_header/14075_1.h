#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef uint8_t OPJ_BYTE;
typedef int32_t OPJ_INT32;

#define OPJ_FALSE 0
#define OPJ_TRUE 1

typedef enum {
    FINAL_PASS
} J2K_T2_MODE;

typedef struct {
    unsigned int csty;
} opj_tcp_t;

typedef struct {
    OPJ_UINT32 packno;
    struct opj_tcd_tilecomp_t *comps;
} opj_tcd_tile_t;

typedef struct {
    OPJ_UINT32 compno;
    OPJ_UINT32 resno;
    OPJ_UINT32 precno;
    OPJ_UINT32 layno;
} opj_pi_iterator_t;

typedef struct {
    int index_write;
    struct opj_tile_info_t *tile;
    OPJ_UINT32 packno;
    double D_max;
} opj_codestream_info_t;

typedef struct {
    void *data;
    OPJ_UINT32 len;
    double disto;
    OPJ_UINT32 numpasses;
} opj_tcd_layer_t;

typedef struct opj_tcd_pass_t {
    OPJ_UINT32 len;
    OPJ_BOOL term;
} opj_tcd_pass_t;

typedef struct opj_tcd_cblk_enc_t {
    OPJ_UINT32 numpasses;
    OPJ_UINT32 numlenbits;
    OPJ_UINT32 numbps;
    opj_tcd_pass_t *passes;
    opj_tcd_layer_t *layers;
} opj_tcd_cblk_enc_t;

typedef struct {
    opj_tcd_cblk_enc_t *enc;
} opj_tcd_cblks_t;

typedef struct {
    OPJ_UINT32 cw;
    OPJ_UINT32 ch;
    opj_tcd_cblks_t cblks;
    void *incltree;
    void *imsbtree;
} opj_tcd_precinct_t;

typedef struct {
    OPJ_UINT32 numbps;
    OPJ_UINT32 numbands;
    opj_tcd_precinct_t *precincts;
    struct opj_tcd_band_t *bands;
} opj_tcd_resolution_t;

typedef struct opj_tcd_tilecomp_t {
    opj_tcd_resolution_t *resolutions;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_band_t {
    OPJ_UINT32 numbps;
    OPJ_BOOL empty;
    opj_tcd_precinct_t *precincts;
} opj_tcd_band_t;

typedef struct opj_packet_info_t {
    OPJ_INT32 end_ph_pos;
    double disto;
} opj_packet_info_t;

typedef struct opj_tile_info_t {
    opj_packet_info_t *packet;
} opj_tile_info_t;

typedef struct {
    void (*event_msg)(void*, int, const char*, ...);
} opj_event_mgr_t;

typedef struct {
    int dummy;
} opj_bio_t;

#define J2K_CP_CSTY_SOP 0x01
#define J2K_CP_CSTY_EPH 0x02
#define EVT_ERROR 1

static OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b) { return a > b ? a : b; }
static OPJ_INT32 opj_int_floorlog2(OPJ_INT32 a) { return 31 - __builtin_clz(a); }
static OPJ_BOOL opj_tcd_is_band_empty(opj_tcd_band_t *band) { return band->empty; }
static void opj_tgt_reset(void *tree) {}
static void opj_tgt_setvalue(void *tree, OPJ_UINT32 cblkno, OPJ_INT32 value) {}
static opj_bio_t* opj_bio_create(void) { return (opj_bio_t*)malloc(sizeof(opj_bio_t)); }
static void opj_bio_init_enc(opj_bio_t *bio, OPJ_BYTE *c, OPJ_UINT32 length) {}
static void opj_bio_write(opj_bio_t *bio, OPJ_UINT32 v, OPJ_UINT32 n) {}
static OPJ_BOOL opj_bio_flush(opj_bio_t *bio) { return OPJ_TRUE; }
static OPJ_INT32 opj_bio_numbytes(opj_bio_t *bio) { return 0; }
static void opj_bio_destroy(opj_bio_t *bio) { free(bio); }
static void opj_tgt_encode(opj_bio_t *bio, void *tree, OPJ_UINT32 cblkno, OPJ_INT32 value) {}
static void opj_t2_putnumpasses(opj_bio_t *bio, OPJ_UINT32 numpasses) {}
static void opj_t2_putcommacode(opj_bio_t *bio, OPJ_INT32 n) {}