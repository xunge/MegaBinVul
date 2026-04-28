#include <stddef.h>
#include <stdint.h>

#define MAX_UCODE_COUNT 128
#define __init

typedef uint8_t u8;

enum ucode_state {
    UCODE_OK,
    UCODE_NFOUND,
    UCODE_ERROR
};

struct microcode_header_intel {
    unsigned int hdrver;
    unsigned int rev;
    unsigned int date;
    unsigned int sig;
    unsigned int cksum;
    unsigned int ldrver;
    unsigned int pf;
    unsigned int datasize;
    unsigned int totalsize;
    unsigned int reserved[3];
};

struct microcode_intel {
    struct microcode_header_intel hdr;
    unsigned int bits[0];
};

struct mc_saved_data {
    unsigned int mc_saved_count;
    struct microcode_intel *mc_saved[MAX_UCODE_COUNT];
};

struct cpu_signature {
    unsigned int sig;
    unsigned int pf;
    unsigned int rev;
};

struct ucode_cpu_info {
    struct cpu_signature cpu_sig;
    unsigned int valid;
    void *mc;
};

static int matching_model_microcode(struct microcode_header_intel *mc_header, unsigned int sig);
static int microcode_sanity_check(void *ucode_ptr, int print_err);
static unsigned int get_totalsize(struct microcode_header_intel *hdr);
static void _save_mc(struct microcode_intel **mc_saved_tmp, void *ucode_ptr, unsigned int *mc_saved_count);