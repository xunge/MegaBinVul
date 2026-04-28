#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>

typedef struct {
    char *s;
    size_t l;
    size_t m;
} kstring_t;

typedef struct {
    int32_t n_targets;
    int8_t *cigar_tab;
} bam_hdr_t;

typedef struct {
    int32_t l_qname;
    int32_t l_extranul;
    int32_t flag;
    int32_t tid;
    int32_t pos;
    int32_t qual;
    int32_t n_cigar;
    int32_t mtid;
    int32_t mpos;
    int32_t isize;
    int32_t l_qseq;
    uint32_t bin;
} bam1_core_t;

typedef struct {
    uint8_t *data;
    int32_t l_data;
    int32_t m_data;
    bam1_core_t core;
} bam1_t;

#define BAM_CIGAR_STR "MIDNSHP=XB"
#define BAM_CIGAR_SHIFT 4
#define BAM_FUNMAP 4

static const int8_t seq_nt16_table[256] = {0};

static void hts_log_error(const char *msg, ...) {}
static void hts_log_warning(const char *msg, ...) {}
static int bam_name2id(bam_hdr_t *h, const char *name) { return 0; }
static int bam_cigar2rlen(int n_cigar, uint32_t *cigar) { return 0; }
static int bam_cigar2qlen(int n_cigar, uint32_t *cigar) { return 0; }
static int bam_tag2cigar(bam1_t *b, int flag, int flag_mask) { return 0; }
static uint32_t hts_reg2bin(int beg, int end, int min_shift, int n_lvls) { return 0; }
static int aux_type2size(char type) { return 0; }

static inline void kputc_(char c, kstring_t *s) {}
static inline void kputsn_(const char *p, int l, kstring_t *s) {}
static inline int ks_resize(kstring_t *s, size_t size) { return 0; }

static inline void i16_to_le(int16_t val, uint8_t *ptr) {}
static inline void u16_to_le(uint16_t val, uint8_t *ptr) {}
static inline void i32_to_le(int32_t val, uint8_t *ptr) {}
static inline void u32_to_le(uint32_t val, uint8_t *ptr) {}
static inline void float_to_le(double val, uint8_t *ptr) {}
static inline void double_to_le(double val, uint8_t *ptr) {}

static inline int isdigit_c(char c) { return isdigit(c); }