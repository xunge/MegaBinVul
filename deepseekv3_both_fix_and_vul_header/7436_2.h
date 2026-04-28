#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

namespace IEX_NAMESPACE {
    class InputExc : public exception {
    public:
        InputExc(const string& msg) {}
    };
    class ArgExc : public exception {
    public:
        ArgExc(const string& msg) {}
    };
}

struct Header {
    bool hasType() const { return false; }
    bool hasName() const { return false; }
    string name() const { return ""; }
    string type() const { return ""; }
    void setType(const string& type) {}
    void sanityCheck(bool isTiled, bool isMultipart) {}
    bool readsNothing() const { return false; }
    void readFrom(istream& is, int version) {}
};

class InputPartData {
public:
    InputPartData(void* data, const Header& header, int index, int numThreads, int version) {}
};

struct MultiPartInputFileData {
    istream* is;
    int version;
    vector<Header> _headers;
    vector<InputPartData*> parts;
    int numThreads;
    bool reconstructChunkOffsetTable;
    
    bool checkSharedAttributesValues(const Header& h1, const Header& h2, vector<string>& attrs) { return false; }
    void readChunkOffsetTables(bool reconstruct) {}
};

class MultiPartInputFile {
    MultiPartInputFileData* _data;
public:
    void initialize();
};

const string TILEDIMAGE = "tiledimage";
const string SCANLINEIMAGE = "scanlineimage";
bool strictSharedAttribute = false;

bool isMultiPart(int version) { return false; }
bool isTiled(int version) { return false; }
bool isTiled(const string& type) { return false; }
bool isNonImage(int version) { return false; }
void readMagicNumberAndVersionField(istream& is, int& version) {}