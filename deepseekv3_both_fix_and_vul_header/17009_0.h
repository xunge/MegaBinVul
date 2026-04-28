#include <stdint.h>

struct wm8350;

#define WM8350_IRQ_CHG_BAT_HOT    0
#define WM8350_IRQ_CHG_BAT_COLD   1
#define WM8350_IRQ_CHG_BAT_FAIL   2
#define WM8350_IRQ_CHG_TO         3
#define WM8350_IRQ_CHG_END        4
#define WM8350_IRQ_CHG_START      5
#define WM8350_IRQ_CHG_FAST_RDY   6
#define WM8350_IRQ_CHG_VBATT_LT_3P9 7
#define WM8350_IRQ_CHG_VBATT_LT_3P1 8
#define WM8350_IRQ_CHG_VBATT_LT_2P85 9
#define WM8350_IRQ_EXT_USB_FB     10
#define WM8350_IRQ_EXT_WALL_FB    11
#define WM8350_IRQ_EXT_BAT_FB     12

void wm8350_free_irq(struct wm8350 *wm8350, uint32_t irq, void *data);