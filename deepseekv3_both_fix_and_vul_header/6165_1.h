#include <string>
#include <vector>

enum CmdId { invalidCmdId, reg, del };
enum MetadataId { invalidMetadataId, iptc, exif, xmp };

struct ModifyCmd {
    CmdId cmdId_;
    std::string key_;
    MetadataId metadataId_;
    int typeId_;
    bool explicitType_;
    std::string value_;
};

namespace Exiv2 {
    enum ErrorCode { kerErrorMessage };
    enum TypeId { invalidTypeId };
    
    class Error {
    public:
        Error(ErrorCode, const std::string&);
    };
    
    class AnyError {};
    
    class IptcKey {
    public:
        IptcKey(const std::string&);
        int tag() const;
        int record() const;
    };
    
    class ExifKey {
    public:
        ExifKey(const std::string&);
        TypeId defaultTypeId() const;
    };
    
    class XmpKey {
    public:
        XmpKey(const std::string&);
    };
    
    namespace IptcDataSets {
        TypeId dataSetType(int, int);
    };
    
    namespace XmpProperties {
        TypeId propertyType(const XmpKey&);
        void registerNs(const std::string&, const std::string&);
    };
    
    namespace TypeInfo {
        TypeId typeId(const std::string&);
    };
    
    std::string toString(int);
    std::string formatArg(const char*);
}

extern int __argc;
extern char** __argv;

const char* _(const char*);
CmdId commandId(const std::string&);
std::string parseEscapes(const std::string&);