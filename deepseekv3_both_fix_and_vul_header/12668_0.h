#include <stdint.h>

#define LOW_FREQUENCY 0
#define HIGH_FREQUENCY 1
#define NFC_IS_ACTIVE 1
#define BOOT_TO_DFU 0

#define TAG_NFC "NFC"

int _NFC_status;
int isLowFreq;
int IS_BUTTON_PRESSED;

void hw_init(int frequency);
int tsc_sensor_exists(void);
int nfc_init(void);
void printf1(const char* tag, const char* message);
int is_physical_button_pressed(void);
void device_init_button(void);
void usbhid_init(void);
void ctaphid_init(void);
void ctap_init(void);
void device_migrate(void);
void flash_option_bytes_init(int flag);