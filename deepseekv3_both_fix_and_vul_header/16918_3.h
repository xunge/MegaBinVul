#include <vector>
#include <climits>
#include <cstdint>
#include <utility>

typedef int64_t Goffset;

enum XRefEntryType {
    xrefEntryUncompressed,
    xrefEntryFree
};

enum ErrorCode {
    errSyntaxError,
    errSyntaxWarning
};

struct Dict;

struct Object {
    bool isCmd(const char* cmd) const;
    bool isInt() const;
    bool isInt64() const;
    bool isDict() const;
    bool isNone() const;
    bool isRef() const;
    int getInt() const;
    int64_t getInt64() const;
    unsigned int getRefNum() const;
    Dict* getDict() const;
    Object copy() const;
    void setToNull();
};

struct Dict {
    Object lookupNF(const char* key) const;
    Object lookup(const char* key) const;
};

struct Parser {
    Object getObj(bool recursive = false);
};

struct XRefEntry {
    Goffset offset;
    int gen;
    XRefEntryType type;
    int flags;
    Object obj;
};

class XRef {
public:
    bool readXRefTable(Parser *parser, Goffset *pos, std::vector<Goffset> *followedXRefStm, std::vector<int> *xrefStreamObjsNum);
private:
    XRefEntry* entries;
    int size;
    bool ok;
    Object trailerDict;
    bool resize(int newSize);
    void error(ErrorCode errCode, int pos, const char* msg);
    bool readXRef(Goffset* pos, std::vector<Goffset>* followedXRefStm, std::vector<int>* xrefStreamObjsNum);
};