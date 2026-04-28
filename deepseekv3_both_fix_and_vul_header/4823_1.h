#include <stdint.h>

typedef struct USBConfigurationDescriptor {
    uint8_t bConfigurationValue;
} USBConfigurationDescriptor;

typedef struct USBDevice {
    USBConfigurationDescriptor *config;
} USBDevice;

typedef struct USBNetState {
    USBDevice dev;
} USBNetState;

#define DEV_RNDIS_CONFIG_VALUE 0