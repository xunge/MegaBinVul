#include <vector>
#include <cstddef>
#include <istream>

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {
    class StreamIO {
    public:
        StreamIO(std::istream& is) : _is(is) {}
        operator std::istream&() { return _is; }
        std::istream& get() { return _is; }
    private:
        std::istream& _is;
    };
    namespace Xdr {
        template<typename T> void read(T&, long&);
    }
}

class MultiPartInputFile {
public:
    struct Data {
        struct Part {
            struct Header;
            Header* header;
            std::vector<long> chunkOffsets;
            bool completed;
        };
        std::vector<Part*> parts;
        OPENEXR_IMF_INTERNAL_NAMESPACE::StreamIO* is;

        int getChunkOffsetTableSize(Part::Header* header, bool);
        int getChunkOffsetTableSize(Part::Header* header);
        void chunkOffsetReconstruction(OPENEXR_IMF_INTERNAL_NAMESPACE::StreamIO&, std::vector<Part*>&);
        
        void readChunkOffsetTables(bool reconstructChunkOffsetTable);
    };
};