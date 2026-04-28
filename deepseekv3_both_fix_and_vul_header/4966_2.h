#include <stdint.h>
#include <stdbool.h>

#define TRACKPAD_REPORT_ID 0x28
#define MOUSE_REPORT_ID 0x29
#define DOUBLE_REPORT_ID 0x2D
#define USB_DEVICE_ID_APPLE_MAGICMOUSE 0x030D
#define USB_DEVICE_ID_APPLE_MAGICTRACKPAD 0x030E
#define BTN_MOUSE 0x110
#define REL_X 0x00
#define REL_Y 0x01

typedef uint8_t u8;

struct hid_device;
struct hid_report;
struct input_dev {
    struct {
        int product;
    } id;
};

struct magicmouse_sc {
    struct input_dev *input;
    int ntouches;
};

static void magicmouse_emit_touch(struct magicmouse_sc *msc, int ii, u8 *data);
static void magicmouse_emit_buttons(struct magicmouse_sc *msc, int clicks);
static void input_report_rel(struct input_dev *dev, int code, int value);
static void input_report_key(struct input_dev *dev, int code, int value);
static void input_mt_report_pointer_emulation(struct input_dev *dev, bool enable);
static void input_sync(struct input_dev *dev);
struct magicmouse_sc *hid_get_drvdata(struct hid_device *hdev);