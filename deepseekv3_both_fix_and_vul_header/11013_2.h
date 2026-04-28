#define __init
#define KERN_INFO ""

#define LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ABOUT "cpia2"
#define CPIA_VERSION "1.0"

static void check_parameters(void);
static int cpia2_usb_init(void);