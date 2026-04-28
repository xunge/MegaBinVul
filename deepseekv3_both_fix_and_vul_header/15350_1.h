#include <vector>
#include <cstdint>
#include <memory>

namespace hci {
    struct GapData {
        static void Parse(GapData* gap_data, std::vector<uint8_t>::const_iterator begin);
    };
}

namespace bluetooth {
    namespace packet {
        enum Endianness {
            kLittleEndian
        };

        template <Endianness endian>
        class PacketView {
        public:
            using const_iterator = std::vector<uint8_t>::const_iterator;
            PacketView(std::shared_ptr<std::vector<uint8_t>> data);
            const_iterator begin() const;
        };
    }
}