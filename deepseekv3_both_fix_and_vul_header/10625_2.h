#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define R_API

typedef struct RCore {
    void *bin;
    void *config;
    void *assembler;
} RCore;

typedef struct RBinFile {
    struct RBinObject *o;
} RBinFile;

typedef struct RBinObject {
    struct RBinInfo *info;
} RBinObject;

typedef struct RBinInfo {
    int has_va;
    const char *arch;
    uint16_t bits;
    const char *cpu;
} RBinInfo;

typedef uint16_t ut16;
typedef uint64_t ut64;

enum {
    R_CORE_BIN_ACC_ALL,
    R_CORE_BIN_SET
};

int r_bin_get_baddr(void *bin);
void r_config_set_i(void *config, const char *key, int value);
void r_config_set(void *config, const char *key, const char *value);
void r_asm_use(void *assembler, const char *arch);
void r_core_bin_info(RCore *r, int acc, int set, int va, void *arg1, void *arg2);
void r_core_bin_set_cur(RCore *r, RBinFile *binfile);