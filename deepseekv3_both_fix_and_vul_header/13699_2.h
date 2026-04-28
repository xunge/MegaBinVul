#include <stdlib.h>
#include <stdbool.h>

enum clock_source_id {
    CLOCK_SOURCE_ID_PLL0,
    CLOCK_SOURCE_ID_PLL1,
    CLOCK_SOURCE_ID_PLL2,
    CLOCK_SOURCE_ID_DCPLL,
    CLOCK_SOURCE_ID_DSICLK,
    CLOCK_SOURCE_ID_COUNT
};

struct dc_context;
struct dc_bios;

struct dce110_clk_src_regs {
    unsigned int reg1;
    unsigned int reg2;
};

struct clock_source {
    bool dp_clk_src;
};

struct dce110_clk_src {
    struct clock_source base;
    unsigned int reg_offset;
};

extern const struct cs_mask_shift {
    unsigned int cs_shift;
    unsigned int cs_mask;
} cs_shift, cs_mask;

void *kzalloc(size_t size, int flags);
int dce110_clk_src_construct(struct dce110_clk_src *clk_src,
                            struct dc_context *ctx,
                            struct dc_bios *bios,
                            enum clock_source_id id,
                            const struct dce110_clk_src_regs *regs,
                            const struct cs_mask_shift *shift,
                            const struct cs_mask_shift *mask);

#define GFP_KERNEL 0
#define BREAK_TO_DEBUGGER()