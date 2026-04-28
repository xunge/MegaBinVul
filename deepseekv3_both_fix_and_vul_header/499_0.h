#include <string>

struct CdtmHeader {
    unsigned int numinst;
};

struct CdtmInstrument {
    char name[256]; 
};

class CdtmLoader {
private:
    CdtmHeader header;
    CdtmInstrument* instruments;
public:
    std::string getinstrument(unsigned int n);
};