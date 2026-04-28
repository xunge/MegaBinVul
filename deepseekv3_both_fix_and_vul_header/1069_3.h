#include <string>

using std::string;

struct ResourceHandleProto {
    bool ParseFromString(const string& s);
};

struct ResourceHandle {
    bool ParseFromString(const string& s);
    struct Status {
        bool ok() const;
    };
    Status FromProto(const ResourceHandleProto& proto) const;
};