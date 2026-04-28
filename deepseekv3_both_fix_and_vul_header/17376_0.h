#include <stdint.h>

typedef struct IDCTDSPContext {
    void (*idct_put)(uint8_t *dest, int line_size, int16_t *block);
    void (*idct_add)(uint8_t *dest, int line_size, int16_t *block);
    void (*idct)(int16_t *block);
    int perm_type;
    void (*put_pixels_clamped)(const int16_t *block, uint8_t *pixels, int line_size);
    void (*put_signed_pixels_clamped)(const int16_t *block, uint8_t *pixels, int line_size);
    void (*add_pixels_clamped)(const int16_t *block, uint8_t *pixels, int line_size);
    uint8_t idct_permutation[64];
    int mpeg4_studio_profile;
} IDCTDSPContext;

typedef struct AVCodecContext {
    int bits_per_raw_sample;
    int lowres;
    int idct_algo;
    int codec_id;
    int profile;
} AVCodecContext;

#define FF_IDCT_PERM_NONE 0
#define FF_IDCT_PERM_LIBMPEG2 1
#define FF_IDCT_INT 0
#define FF_IDCT_FAAN 1
#define FF_IDCT_XVID 2
#define FF_PROFILE_MPEG4_SIMPLE_STUDIO 0
#define AV_CODEC_ID_MPEG4 0
#define CONFIG_MPEG4_DECODER 1
#define CONFIG_FAANIDCT 1
#define ARCH_AARCH64 0
#define ARCH_ALPHA 0
#define ARCH_ARM 0
#define ARCH_PPC 0
#define ARCH_X86 0
#define ARCH_MIPS 0

#define av_cold

extern void ff_jref_idct4_put(uint8_t *dest, int line_size, int16_t *block);
extern void ff_jref_idct4_add(uint8_t *dest, int line_size, int16_t *block);
extern void ff_j_rev_dct4(int16_t *block);
extern void ff_jref_idct2_put(uint8_t *dest, int line_size, int16_t *block);
extern void ff_jref_idct2_add(uint8_t *dest, int line_size, int16_t *block);
extern void ff_j_rev_dct2(int16_t *block);
extern void ff_jref_idct1_put(uint8_t *dest, int line_size, int16_t *block);
extern void ff_jref_idct1_add(uint8_t *dest, int line_size, int16_t *block);
extern void ff_j_rev_dct1(int16_t *block);
extern void ff_simple_idct_put_int32_10bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_put_int16_10bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_add_int16_10bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_int16_10bit(int16_t *block);
extern void ff_simple_idct_put_int16_12bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_add_int16_12bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_int16_12bit(int16_t *block);
extern void ff_jref_idct_put(uint8_t *dest, int line_size, int16_t *block);
extern void ff_jref_idct_add(uint8_t *dest, int line_size, int16_t *block);
extern void ff_j_rev_dct(int16_t *block);
extern void ff_faanidct_put(uint8_t *dest, int line_size, int16_t *block);
extern void ff_faanidct_add(uint8_t *dest, int line_size, int16_t *block);
extern void ff_faanidct(int16_t *block);
extern void ff_simple_idct_put_int16_8bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_add_int16_8bit(uint8_t *dest, int line_size, int16_t *block);
extern void ff_simple_idct_int16_8bit(int16_t *block);
extern void ff_put_pixels_clamped_c(const int16_t *block, uint8_t *pixels, int line_size);
extern void put_signed_pixels_clamped_c(const int16_t *block, uint8_t *pixels, int line_size);
extern void ff_add_pixels_clamped_c(const int16_t *block, uint8_t *pixels, int line_size);
extern void ff_xvid_idct_init(IDCTDSPContext *c, AVCodecContext *avctx);
extern void ff_idctdsp_init_aarch64(IDCTDSPContext *c, AVCodecContext *avctx, unsigned high_bit_depth);
extern void ff_idctdsp_init_alpha(IDCTDSPContext *c, AVCodecContext *avctx, unsigned high_bit_depth);
extern void ff_idctdsp_init_arm(IDCTDSPContext *c, AVCodecContext *avctx, unsigned high_bit_depth);
extern void ff_idctdsp_init_ppc(IDCTDSPContext *c, AVCodecContext *avctx, unsigned high_bit_depth);
extern void ff_idctdsp_init_x86(IDCTDSPContext *c, AVCodecContext *avctx, unsigned high_bit_depth);
extern void ff_idctdsp_init_mips(IDCTDSPContext *c, AVCodecContext *avctx, unsigned high_bit_depth);
extern void ff_init_scantable_permutation(uint8_t *idct_permutation, int perm_type);