#include <set>
#include <string>
#include <stdexcept>
#include <vector>
#include <map>

struct QPDFObjGen {
    int obj;
    int gen;
    int getObj() const { return obj; }
    int getGen() const { return gen; }
    bool operator<(const QPDFObjGen& other) const {
        return (obj < other.obj) || (obj == other.obj && gen < other.gen);
    }
};

class QPDF;

class QPDFObjectHandle {
public:
    bool isIndirect() const;
    QPDF* getOwningQPDF() const;
    QPDFObjGen getObjGen() const;
    bool isArray() const;
    int getArrayNItems() const;
    QPDFObjectHandle getArrayItem(int) const;
    bool isDictionary() const;
    std::set<std::string> getKeys() const;
    QPDFObjectHandle getKey(const std::string&) const;
    bool isStream() const;
};

class QPDF {
public:
    QPDFObjectHandle getObjectByID(int, int);
};

class QPDFWriter {
public:
    void enqueueObject(QPDFObjectHandle object);
private:
    QPDF pdf;
    std::map<QPDFObjGen, int> obj_renumber;
    std::map<QPDFObjGen, int> object_to_object_stream;
    std::map<int, std::vector<QPDFObjGen>> object_stream_to_objects;
    std::vector<QPDFObjectHandle> object_queue;
    int next_objid;
    bool linearized;
    bool direct_stream_lengths;
    void assignCompressedObjectNumbers(QPDFObjGen);
};

namespace QTC {
    void TC(const char*, const char*);
};