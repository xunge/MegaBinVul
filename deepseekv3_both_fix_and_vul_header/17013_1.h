#include <stdbool.h>
#include <stddef.h>

extern unsigned int imx_enabled_uart_clocks;
extern bool imx_keep_uart_clocks;
extern void *of_stdout;
extern void **imx_uart_clocks;

#define CONFIG_OF
#define GFP_KERNEL 0
#define IS_ERR(x) (0)

struct clk;
void *kcalloc(size_t n, size_t size, int flags);
void *of_clk_get(void *node, int index);
int clk_prepare_enable(void *clk);