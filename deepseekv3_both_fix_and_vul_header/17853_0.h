#include <stdexcept>

namespace IEX_NAMESPACE {
    class ArgExc : public std::runtime_error {
    public:
        ArgExc(const std::string& what_arg) : std::runtime_error(what_arg) {}
    };
}

class Header {
public:
    bool hasChunkCount() const;
    int chunkCount() const;
    bool hasType() const;
    int type() const;
};

bool isSupportedType(int type);
bool isTiled(int type);
int getScanlineChunkOffsetTableSize(const Header& header);
int getTiledChunkOffsetTableSize(const Header& header);