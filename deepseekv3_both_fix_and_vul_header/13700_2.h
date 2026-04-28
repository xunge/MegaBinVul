#include <stdlib.h>
#include <stdbool.h>

struct dc_context;
struct dc_bios;
struct dce110_clk_src_regs;

enum clock_source_id {
    CLOCK_SOURCE_ID_PLL0,
    CLOCK_SOURCE_ID_PLL1,
    CLOCK_SOURCE_ID_PLL2,
    CLOCK_SOURCE_ID_EXTERNAL
};

struct clock_source {
    bool dp_clk_src;
};

struct dce110_clk_src {
    struct clock_source base;
};

struct cs_mask {
    unsigned int mask;
};

struct cs_shift {
    unsigned int shift;
};

extern const struct cs_mask cs_mask;
extern const struct cs_shift cs_shift;

void* kzalloc(size_t size, int flags);
#define GFP_KERNEL 0
#define BREAK_TO_DEBUGGER()

int dce112_clk_src_construct(struct dce110_clk_src *clk_src,
                            struct dc_context *ctx,
                            struct dc_bios *bios,
                            enum clock_source_id id,
                            const struct dce110_clk_src_regs *regs,
                            const struct cs_shift *cs_shift,
                            const struct cs_mask *cs_mask);