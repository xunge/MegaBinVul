#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef bool boolean;
#define FALSE false
#define TRUE true

typedef uint32_t uint;

struct translate_ctx {
    const char *cur;
    uint *tokens_cur;
    uint *tokens_end;
    void *header;
};

struct tgsi_opcode_info {
    uint num_dst;
    uint num_src;
    bool is_tex;
    bool is_branch;
};

struct tgsi_full_instruction {
    struct {
        uint Opcode;
        uint Saturate;
        uint NumDstRegs;
        uint NumSrcRegs;
        uint Predicate;
        uint Texture;
        uint Label;
    } Instruction;
    struct {
        uint Negate;
        uint SwizzleX;
        uint SwizzleY;
        uint SwizzleZ;
        uint SwizzleW;
    } Predicate;
    struct {
        uint Texture;
        uint NumOffsets;
    } Texture;
    struct {
        uint Label;
    } Label;
    uint Dst[4];
    uint Src[4];
    uint TexOffsets[4];
};

#define TGSI_OPCODE_LAST 0
#define TGSI_OPCODE_SAMPLE 0
#define TGSI_OPCODE_GATHER4 0
#define TGSI_TEXTURE_UNKNOWN 0
#define TGSI_TEXTURE_COUNT 0
#define TGSI_FULL_MAX_TEX_OFFSETS 0

static void eat_opt_white(const char **cur) {}
static bool parse_register_1d(struct translate_ctx *ctx, uint *file, int *index) { return false; }
static bool parse_optional_swizzle(struct translate_ctx *ctx, uint swizzle[4], bool *parsed_swizzle, uint count) { return false; }
static void report_error(struct translate_ctx *ctx, const char *msg) {}
static bool eat_white(const char **cur) { return false; }
static bool match_inst(const char **cur, uint *saturate, const struct tgsi_opcode_info *info) { return false; }
static bool str_match_nocase_whole(const char **cur, const char *name) { return false; }
static bool parse_dst_operand(struct translate_ctx *ctx, uint *dst) { return false; }
static bool parse_src_operand(struct translate_ctx *ctx, uint *src) { return false; }
static bool parse_texoffset_operand(struct translate_ctx *ctx, uint *texoffset) { return false; }
static bool parse_uint(const char **cur, uint *target) { return false; }
static uint tgsi_build_full_instruction(struct tgsi_full_instruction *inst, uint *tokens_cur, void *header, uint remaining) { return 0; }
static struct tgsi_full_instruction tgsi_default_full_instruction(void) { struct tgsi_full_instruction inst = {0}; return inst; }
static const struct tgsi_opcode_info *tgsi_get_opcode_info(uint i) { return NULL; }
static const char *tgsi_texture_names[TGSI_TEXTURE_COUNT];