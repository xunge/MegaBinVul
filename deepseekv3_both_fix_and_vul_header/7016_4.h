#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cstdint>

enum InputType {
    IT_Vertex
};

enum PrimitiveType {
    Prim_Polylist,
    Prim_Lines,
    Prim_Triangles,
    Prim_TriFans,
    Prim_Polygon,
    Prim_TriStrips,
    Prim_LineStrip
};

struct Accessor;
struct Data;

struct InputChannel {
    InputType mType;
    size_t mOffset;
    std::string mAccessor;
    const Accessor* mResolved;
};

struct Accessor {
    mutable const Data* mData;
    size_t mOffset;
    size_t mCount;
    size_t mStride;
    std::string mSource;
};

struct Data {
    std::vector<float> mValues;
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

class DeadlyImportError {
public:
    DeadlyImportError(const char*);
};

class ColladaParser {
public:
    size_t ReadPrimitives(XmlNode&, Mesh&, std::vector<InputChannel>&, size_t, const std::vector<size_t>&, PrimitiveType);
    const std::vector<Accessor> mAccessorLibrary;
    const std::vector<Data> mDataLibrary;
    const Accessor& ResolveLibraryReference(const std::vector<Accessor>&, const std::string&);
    const Data& ResolveLibraryReference(const std::vector<Data>&, const std::string&);
};

void SkipSpacesAndLineEnd(const char**, const char*);
int strtol10(const char*, const char**);
void ReportWarning(const char*, ...);
void CopyVertex(size_t, size_t, size_t, size_t, Mesh&, std::vector<InputChannel>&, size_t, std::vector<size_t>&);
void ReadPrimTriStrips(size_t, size_t, Mesh&, std::vector<InputChannel>&, size_t, std::vector<size_t>&);