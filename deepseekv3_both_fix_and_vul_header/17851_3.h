#include <vector>
#include <string>
#include <stdexcept>

using std::string;

namespace IEX_NAMESPACE {
    class ArgExc : public std::runtime_error {
    public:
        ArgExc(const std::string& what) : std::runtime_error(what) {}
    };
}

struct Header {
    bool hasTileDescription() const;
    void sanityCheck(bool hasTileDesc, bool isMultiPart);
    bool hasType() const;
    std::string type() const;
    void setChunkCount(size_t count);
    std::string name() const;
};

class MultiPartOutputFile {
public:
    class Data {
    public:
        std::vector<Header> _headers;
        void do_header_sanity_checks(bool overrideSharedAttributes);
        size_t getChunkOffsetTableSize(const Header& header, bool withTile = false);
        bool isImage(const std::string& type);
        void overrideSharedAttributesValues(const Header& src, Header& dst);
        bool checkSharedAttributesValues(const Header& src, const Header& dst, std::vector<std::string>& conflicts);
        void headerNameUniquenessCheck(const std::vector<Header>& headers);
    };
};

#define THROW(type, msg) throw type(msg)