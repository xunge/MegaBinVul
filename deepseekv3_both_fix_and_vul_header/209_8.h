#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define SUNXI_DIVS_MAX_QTY 32
#define SUNXI_DIVISOR_WIDTH 4
#define GFP_KERNEL 0
#define CLK_SET_RATE_PARENT (1 << 0)
#define CLK_IS_CRITICAL (1 << 1)
#define CLK_DIVIDER_POWER_OF_TWO (1 << 0)

typedef uint8_t u8;
typedef void* volatile iomem_ptr;
#define __iomem 

struct device_node;
struct clk;
struct clk_hw {
    struct clk *clk;
};
struct clk_ops {};
struct clk_gate {
    void *reg;
    u8 bit_idx;
    void *lock;
    struct clk_hw hw;
};
struct clk_fixed_factor {
    unsigned int mult;
    unsigned int div;
    struct clk_hw hw;
};
struct clk_divider {
    void *reg;
    u8 shift;
    u8 width;
    unsigned long flags;
    void *lock;
    const void *table;
    struct clk_hw hw;
};
struct clk_div_table {
    unsigned int val;
    unsigned int div;
};
struct clk_onecell_data {
    struct clk **clks;
    int clk_num;
};
struct of_phandle_args {
    int args_count;
    uint32_t args[1];
};

struct divs_data {
    const struct factors_data *factors;
    int ndivs;
    struct {
        bool self;
        bool gate;
        u8 shift;
        u8 pow;
        bool critical;
        u8 fixed;
        const struct clk_div_table *table;
    } div[SUNXI_DIVS_MAX_QTY];
};

struct factors_data {
    const char *name;
};

static void *clk_lock;

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static char *kstrndup(const char *s, size_t max, int flags) { return strndup(s, max); }
static void kfree(void *p) { free(p); }
static void iounmap(void *addr) {}
static void *of_iomap(struct device_node *node, int index) { return NULL; }
static int of_property_read_string_index(struct device_node *node, const char *propname, int index, const char **out_string) { return 0; }
static int of_clk_add_provider(struct device_node *node, void *(*get)(struct of_phandle_args *clkspec, void *data), void *data) { return 0; }
static const char *__clk_get_name(struct clk *clk) { return NULL; }
static struct clk *sunxi_factors_clk_setup(struct device_node *node, struct factors_data *data) { return NULL; }
static struct clk *clk_register_composite(const char *name, const char *parent_name, const void *parent_hw, int num_parents, void *mux_hw, const struct clk_ops *mux_ops, void *rate_hw, const struct clk_ops *rate_ops, void *gate_hw, const struct clk_ops *gate_ops, unsigned long flags) { return NULL; }
static void *of_clk_src_onecell_get(struct of_phandle_args *clkspec, void *data) { return NULL; }

static const struct clk_ops clk_fixed_factor_ops = {};
static const struct clk_ops clk_divider_ops = {};
static const struct clk_ops clk_gate_ops = {};

#define __init
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define WARN_ON(condition) ((condition) ? fprintf(stderr, "Warning at %s:%d\n", __FILE__, __LINE__) : 0)
#define IS_ERR(ptr) (ptr == NULL)