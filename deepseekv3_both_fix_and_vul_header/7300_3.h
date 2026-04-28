#include <vector>

class BitReader {
public:
    int getBits(int numBits);
    bool getBit();
    void skipBits(int numBits);
    void skipBit();
    int getBitsLeft();
};

class VvcUnitWithProfile {
private:
    BitReader m_reader;
    int profile_idc;
    int level_idc;
public:
    void profile_tier_level(bool profileTierPresentFlag, int MaxNumSubLayersMinus1);
};