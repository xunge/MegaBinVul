#include <stddef.h>
#include <stdint.h>
#include <stdexcept>

#define NOT_ENOUGH_BUFFER 1

class VodCoreException : public std::exception {};

class BitReader {
public:
    int getBitsLeft();
    int getBits(int n);
    void skipBits(int n);
    int getBit();
    int getBitsCount();
    void skipBit() { skipBits(1); }
};

class HevcUnit {
public:
    int deserialize();
    BitReader m_reader;
    unsigned extractUEGolombCode();
    void profile_tier_level(int max_sub_layers);
};

class HevcVpsUnit : public HevcUnit {
public:
    int deserialize();
    int vps_id;
    int vps_max_layers;
    int vps_max_sub_layers;
    int num_units_in_tick_bit_pos;
    uint32_t num_units_in_tick;
    uint32_t time_scale;
};