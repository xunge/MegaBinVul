#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <stdexcept>

enum InputType {
    IT_Vertex
};

enum PrimitiveType {
    Prim_Polylist,
    Prim_Lines,
    Prim_Triangles,
    Prim_TriStrips,
    Prim_LineStrip,
    Prim_TriFans,
    Prim_Polygon
};

struct Data {
    std::vector<float> mValues;
};

struct Accessor {
    mutable Data* mData;
    size_t mOffset;
    size_t mCount;
    size_t mStride;
    std::string mSource;
};

struct InputChannel {
    InputType mType;
    size_t mOffset;
    std::string mAccessor;
    Accessor* mResolved;
};

struct Mesh {
    std::vector<InputChannel> mPerVertexData;
    std::string mVertexID;
    std::vector<size_t> mFaceSize;
    std::vector<size_t> mFacePosIndices;
};

class XmlNode {};
class XmlParser {
public:
    static void getValueAsString(XmlNode&, std::string&);
};

class DeadlyImportError : public std::runtime_error {
public:
    DeadlyImportError(const char* msg) : std::runtime_error(msg) {}
};

class ColladaParser {
public:
    size_t ReadPrimitives(XmlNode&, Mesh&, std::vector<InputChannel>&, size_t, const std::vector<size_t>&, PrimitiveType);
    std::vector<Accessor> mAccessorLibrary;
    std::vector<Data> mDataLibrary;
};

void SkipSpacesAndLineEnd(const char**, const char*);
int strtol10(const char*, const char**);
void ReportWarning(const char*, ...);
void CopyVertex(size_t, size_t, size_t, size_t, Mesh&, std::vector<InputChannel>&, size_t, std::vector<size_t>&);
void ReadPrimTriStrips(size_t, size_t, Mesh&, std::vector<InputChannel>&, size_t, std::vector<size_t>&);
Accessor& ResolveLibraryReference(std::vector<Accessor>&, const std::string&);
Data& ResolveLibraryReference(std::vector<Data>&, const std::string&);