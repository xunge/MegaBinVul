#include <set>

struct Ref {
    int num;
    int gen;
};

enum ObjectType {
    objArray,
    objDict,
    objStream,
    objRef
};

enum XRefEntryType {
    xrefEntryFree,
    xrefEntryCompressed
};

struct XRefEntry {
    XRefEntryType type;
    int gen;
};

class Dict;
class Array;
class Stream;
class XRef;

class Object {
public:
    ObjectType getType();
    Array* getArray();
    Dict* getDict();
    Stream* getStream();
    Ref getRef();
    Object copy();
};

class Array {
public:
    int getLength();
    Object getNF(int i);
};

class Stream {
public:
    Dict* getDict();
};

class XRef {
public:
    int getNumObjects();
    XRefEntry* getEntry(int num);
    void add(int num, int gen, int offset, bool used);
    Object fetch(Ref ref);
};

class PDFDoc {
public:
    XRef* getXRef();
    void markObject(Object* obj, XRef* xRef, XRef* countRef, unsigned int numOffset, int oldRefNum, int newRefNum, std::set<Dict*>* alreadyMarkedDicts = nullptr);
    void markDictionnary(Dict* dict, XRef* xRef, XRef* countRef, unsigned int numOffset, int oldRefNum, int newRefNum, std::set<Dict*>* alreadyMarkedDicts);
};