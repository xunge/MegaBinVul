#include <vector>
#include <cstdint>
#include <string>
#include <memory>
#include <iostream>

#define INFO 0
#define LOG(level) std::cout

using IdTxPowerStatusCallback = void (*)(uint8_t, int8_t, uint8_t);
using IdStatusCallback = void (*)(uint8_t, uint8_t);
using ScanCallback = void (*)(uint8_t, uint8_t, uint16_t, int8_t);
using SetTerminatedCallback = void (*)(uint8_t, uint8_t, uint8_t, uint8_t);

struct AdvertiseParameters {
    uint16_t advertising_event_properties;
    uint32_t min_interval;
    uint32_t max_interval;
    uint8_t channel_map;
    int8_t tx_power;
    uint8_t primary_advertising_phy;
    uint8_t secondary_advertising_phy;
    uint8_t scan_request_notification_enable;
};

struct PeriodicAdvertisingParameters {
    uint8_t periodic_advertising_properties;
    uint16_t min_interval;
    uint16_t max_interval;
};

struct GapData {
    static void Parse(GapData* gap_data, std::vector<uint8_t>::const_iterator it);
};

namespace bluetooth {
namespace packet {
    enum Endianness { kLittleEndian };
    template <Endianness> class PacketView {
    public:
        PacketView(std::shared_ptr<std::vector<uint8_t>> data);
        std::vector<uint8_t>::const_iterator begin() const;
    };
}
namespace hci {
    struct PeriodicAdvertisingParameters {
        uint16_t min_interval;
        uint16_t max_interval;
        uint8_t properties;
    };
    struct ExtendedAdvertisingConfig {
        std::vector<GapData> advertisement;
        std::vector<GapData> scan_response;
        std::vector<GapData> periodic_data;
        PeriodicAdvertisingParameters periodic_advertising_parameters;
    };
    using AdvertiserId = uint8_t;
}
namespace shim {
    class Advertising {
    public:
        bluetooth::hci::AdvertiserId ExtendedCreateAdvertiser(
            int reg_id,
            bluetooth::hci::ExtendedAdvertisingConfig& config,
            ScanCallback scan_cb,
            SetTerminatedCallback set_terminated_cb,
            uint16_t duration,
            uint8_t maxExtAdvEvents,
            void* handler);
    };
    Advertising* GetAdvertising();
    void* GetGdShimHandler();
}
}

namespace base {
    std::string StringPrintf(const char* format, ...);
}

constexpr const char* kBtmLogTag = "BTM";
class RawAddress {
public:
    static const RawAddress kEmpty;
};
void BTM_LogHistory(const char* tag, const RawAddress& addr, const std::string& history, const std::string& extra);

void parse_parameter(bluetooth::hci::ExtendedAdvertisingConfig& config, AdvertiseParameters params);
void parse_gap_data(std::vector<uint8_t> data, std::vector<GapData>& gap_data);

void scan_callback(uint8_t, uint8_t, uint16_t, int8_t);
void set_terminated_callback(uint8_t, uint8_t, uint8_t, uint8_t);