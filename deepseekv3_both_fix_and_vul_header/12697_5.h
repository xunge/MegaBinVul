#include <stdint.h>

struct Elf32_Ehdr {
    uint16_t e_type;
    static const uint16_t ET_DYN;
};

const uint16_t Elf32_Ehdr::ET_DYN = 3;

class PackLinuxElf32_super {
public:
    virtual int canUnpack() = 0;
};

class PackLinuxElf32 : public PackLinuxElf32_super {
protected:
    Elf32_Ehdr ehdri;
    int fi;
    
    virtual bool checkEhdr(Elf32_Ehdr *ehdr);
    virtual uint16_t get_te16(const void *p);
    virtual void PackLinuxElf32help1(int f);
    virtual int canUnpack() override;
    
    using super = PackLinuxElf32_super;
};