#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t guint32;
typedef char gchar;

#define GENERIC_DESKTOP_CONTROLS_PAGE 0x01
#define SIMULATION_CONTROLS_PAGE 0x02
#define VR_CONTROLS_PAGE 0x03
#define SPORT_CONTROLS_PAGE 0x04
#define GAME_CONTROLS_PAGE 0x05
#define GENERIC_DEVICE_CONTROLS_PAGE 0x06
#define KEYBOARD_KEYPAD_PAGE 0x07
#define LED_PAGE 0x08
#define BUTTON_PAGE 0x09
#define ORDINAL_PAGE 0x0A
#define TELEPHONY_PAGE 0x0B
#define CONSUMER_PAGE 0x0C
#define DIGITIZER_PAGE 0x0D
#define HAPTICS_PAGE 0x0E
#define PID_PAGE 0x0F
#define UNICODE_PAGE 0x10
#define EYE_AND_HEAD_TRACKER_PAGE 0x12
#define ALPHANUMERIC_DISPLAY_PAGE 0x14
#define SENSOR_PAGE 0x20
#define MEDICAL_INSTRUMENTS_PAGE 0x40
#define BRAILLE_DISPLAY_PAGE 0x41
#define LIGHTING_AND_ILLUMINATION_PAGE 0x59
#define USB_MONITOR_PAGE 0x80
#define USB_ENUMERATED_VALUES_PAGE 0x81
#define VESA_VIRTUAL_CONTROLS_PAGE 0x82
#define POWER_DEVICE_PAGE 0x84
#define BATTERY_SYSTEM_PAGE 0x85
#define BARCODE_SCANNER_PAGE 0x8C
#define WEIGHING_PAGE 0x8D
#define MSR_PAGE 0x8E
#define ARCADE_PAGE 0x91
#define FIDO_ALLIANCE_PAGE 0xF1D0
#define VENDOR_PAGE_HBYTE 0xFF00

typedef struct {
    guint32 value;
    const gchar *str;
} value_string;

typedef struct {
    guint32 value_min;
    guint32 value_max;
    const gchar *str;
} range_string;

extern const value_string usb_hid_generic_desktop_controls_usage_page_vals[];
extern const value_string usb_hid_simulation_control_usage_page_vals[];
extern const value_string usb_hid_vr_controls_usage_page_vals[];
extern const value_string usb_hid_sport_controls_usage_page_vals[];
extern const value_string usb_hid_game_controls_usage_page_vals[];
extern const value_string usb_hid_generic_device_controls_usage_page_vals[];
extern const value_string usb_hid_keyboard_keypad_usage_page_vals[];
extern const value_string usb_hid_led_usage_page_vals[];
extern const value_string usb_hid_button_usage_page_vals[];
extern const value_string usb_hid_ordinal_usage_page_vals[];
extern const value_string usb_hid_telephony_device_usage_page_vals[];
extern const value_string usb_hid_consumer_usage_page_vals[];
extern const value_string usb_hid_digitizers_usage_page_vals[];
extern const value_string usb_hid_haptic_usage_page_vals[];
extern const value_string usb_hid_physical_input_device_usage_page_vals[];
extern const value_string usb_hid_eye_and_head_tracker_usage_page_vals[];
extern const value_string usb_hid_alphanumeric_display_usage_page_vals[];
extern const value_string usb_hid_sensor_usage_page_vals[];
extern const range_string usb_hid_sensor_usage_page_ranges[];
extern const value_string usb_hid_medical_instrument_usage_page_vals[];
extern const value_string usb_hid_braille_dispaly_usage_page_vals[];
extern const value_string usb_hid_lighting_and_illumination_usage_page_vals[];
extern const value_string usb_hid_monitor_usage_page_vals[];
extern const value_string usb_hid_vesa_virtual_control_usage_page_vals[];
extern const value_string usb_hid_power_device_usage_page_vals[];
extern const value_string usb_hid_battery_system_usage_page_vals[];
extern const value_string usb_hid_barcode_scanner_usage_page_vals[];
extern const value_string usb_hid_weighing_devices_usage_page_vals[];
extern const value_string usb_hid_magnetic_stripe_reader_usage_page_vals[];
extern const value_string usb_hid_arcade_usage_page_vals[];
extern const value_string usb_hid_fido_alliance_usage_page_vals[];

const gchar *try_val_to_str(guint32 val, const value_string *vs);
const gchar *try_rval_to_str(guint32 val, const range_string *rs);
gchar *g_strdup_printf(const char *format, ...);