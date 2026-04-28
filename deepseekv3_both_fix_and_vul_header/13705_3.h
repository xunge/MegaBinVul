#include <stdlib.h>
#include <stdbool.h>

struct dc_context;
struct dc_bios;

enum clock_source_id {
    CLOCK_SOURCE_ID_PLL0,
    CLOCK_SOURCE_ID_PLL1,
    CLOCK_SOURCE_ID_PLL2,
    CLOCK_SOURCE_ID_EXTERNAL,
    CLOCK_SOURCE_ID_UNDEFINED
};

struct clock_source {
    bool dp_clk_src;
};

struct dce110_clk_src_regs {
    unsigned int reg1;
    unsigned int reg2;
};

struct dce110_clk_src {
    struct clock_source base;
    unsigned int dummy_member;
};

struct cs_mask_shift {
    unsigned int cs_mask;
    unsigned int cs_shift;
};

extern const struct cs_mask_shift cs_mask;
extern const struct cs_mask_shift cs_shift;

bool dce112_clk_src_construct(struct dce110_clk_src *clk_src,
                            struct dc_context *ctx,
                            struct dc_bios *bios,
                            enum clock_source_id id,
                            const struct dce110_clk_src_regs *regs,
                            const struct cs_mask_shift *shift,
                            const struct cs_mask_shift *mask);

#define GFP_KERNEL 0
#define BREAK_TO_DEBUGGER()