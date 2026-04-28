#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <cassert>

#define ASSERT(x) assert(x)
const int DataCloneError = 1;

class StateBase {};
class File {
public:
    bool hasBeenClosed() const;
    std::string uuid() const;
    std::shared_ptr<void> blobDataHandle() const;
};
class FileList {
public:
    unsigned length() const;
    const File* item(unsigned) const;
};
class V8FileList {
public:
    static FileList* toNative(void*);
};

template<typename T>
class Vector {
public:
    void append(const T&);
    bool isEmpty() const;
};

template<typename K, typename V>
class HashMap {
public:
    void set(const K& key, const V& value) { data[key] = value; }
    void add(const K& key, const V& value) { data[key] = value; }
    std::unordered_map<K,V> data;
};

HashMap<std::string, std::shared_ptr<void>> m_blobDataHandles;
Vector<int> blobIndices;

class Writer {
public:
    void writeFileListIndex(const Vector<int>&);
    void writeFileList(const FileList&);
} m_writer;

StateBase* handleError(int, const char*, StateBase*);
bool appendFileInfo(const File*, int*);

namespace v8 {
    template<typename T>
    class Handle {
    public:
        T* As();
        template<typename U> U* As();
    };
    class Value {};
    class Object : public Value {};
}