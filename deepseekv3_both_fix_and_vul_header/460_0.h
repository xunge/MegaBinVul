#include <stdint.h>

#define IWLAGN_STATION_COUNT 32
#define EINVAL 22

#define IWL_STA_DRIVER_ACTIVE (1 << 0)
#define IWL_STA_UCODE_ACTIVE (1 << 1)

struct iwl_sta {
    struct {
        uint8_t addr[6];
    } sta;
};

struct iwl_station {
    struct iwl_sta sta;
    unsigned int used;
};

struct iwl_priv {
    struct iwl_station stations[IWLAGN_STATION_COUNT];
};

#define IWL_ERR(priv, fmt, ...)
#define IWL_DEBUG_ASSOC(priv, fmt, ...)

typedef uint8_t u8;