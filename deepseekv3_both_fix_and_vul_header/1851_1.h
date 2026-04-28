#include <vector>
#include <stdexcept>

using namespace std;

class BitStreamException : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class VodCoreException : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class VvcUnit {
public:
    int deserialize();
};

class BitStreamReader {
public:
    unsigned getBits(int numBits);
    bool getBit();
    void skipBits(int numBits);
    int getBitsLeft();
};

class VvcVpsUnit : public VvcUnit {
protected:
    BitStreamReader m_reader;
    int vps_id;
    int vps_max_layers;
    int vps_max_sublayers;
    int m_vps_hrd;

    int profile_tier_level(bool presentFlag, int maxTid);
    int dpb_parameters(int maxTid, bool sublayerFlag);
    int general_timing_hrd_parameters(int hrd);
    int ols_timing_hrd_parameters(int hrd, int firstSubLayer, int maxTid);
    unsigned extractUEGolombCode();
public:
    int deserialize();
};

const int NOT_ENOUGH_BUFFER = 1;