#include <string>

class IDeletable {
public:
    virtual void DeleteMe() = 0;
    virtual ~IDeletable() {}
};

class PDFObject {
public:
    virtual IDeletable* DetachMetadata(const std::string& inKey);
    virtual void DeleteMetadata(const std::string& inKey);
};