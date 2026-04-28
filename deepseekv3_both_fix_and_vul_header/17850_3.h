#include <istream>
#include <vector>
#include <memory>

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {
    struct IStream {
        bool isMemoryMapped();
    };
}

struct Header {};
struct InputStreamMutex { OPENEXR_IMF_INTERNAL_NAMESPACE::IStream* is; };
struct Data {
    int version;
    bool memoryMapped;
    bool fileIsComplete;
    int lineOrder;
    std::vector<long> lineOffsets;
    InputStreamMutex* _streamData;
    bool _deleteStream;
    Data(int) {}
};

class DeepScanLineInputFile {
    Data* _data;
public:
    DeepScanLineInputFile(const Header&, OPENEXR_IMF_INTERNAL_NAMESPACE::IStream*, int, int);
    void initialize(const Header&);
    void readLineOffsets(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream&, int&, std::vector<long>&, bool&);
};