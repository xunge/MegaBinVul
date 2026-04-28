#include <map>
#include <string>
#include <utility>
#include <stdexcept>

typedef long long qpdf_offset_t;

class QPDFObject {};
class QPDF_Null : public QPDFObject {};
class QPDFExc {
public:
    QPDFExc(int, std::string, std::string, qpdf_offset_t, std::string);
};
class QPDFXRefEntry;
class QPDFObjGen;
class QPDFObjectHandle {};

namespace QTC {
    void TC(const char*, const char*);
}

namespace QUtil {
    std::string int_to_string(int);
}

template <typename T>
class PointerHolder {
public:
    PointerHolder(T* ptr = nullptr) : ptr(ptr) {}
    T* get() const { return ptr; }
    operator T*() const { return ptr; }
private:
    T* ptr;
};

class ResolveRecorder {
public:
    ResolveRecorder(class QPDF* qpdf, QPDFObjGen const& og);
    ~ResolveRecorder();
};

class File {
public:
    std::string getName() const;
    qpdf_offset_t getLastOffset() const;
};

class QPDF {
public:
    std::map<QPDFObjGen, int> resolving;
    std::map<QPDFObjGen, QPDFXRefEntry> xref_table;
    std::map<QPDFObjGen, struct ObjCacheEntry> obj_cache;
    File* file;

    PointerHolder<QPDFObject> resolve(int objid, int generation);
    QPDFObjectHandle readObjectAtOffset(bool, qpdf_offset_t, std::string, int, int, int&, int&);
    void resolveObjectsInStream(int);
    void warn(QPDFExc const&);
};

struct ObjCacheEntry {
    PointerHolder<QPDFObject> object;
    ObjCacheEntry() : object(nullptr) {}
};

class QPDFObjGen {
public:
    QPDFObjGen(int, int);
    bool operator<(QPDFObjGen const&) const;
};

class QPDFXRefEntry {
public:
    int getType() const;
    qpdf_offset_t getOffset() const;
    int getObjStreamNumber() const;
};

enum {
    qpdf_e_damaged_pdf
};