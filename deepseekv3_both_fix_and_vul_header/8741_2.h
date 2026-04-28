#include <stdint.h>
#include <string>
#include <map>

typedef int32_t status_t;
#define OK 0
#define UNKNOWN_ERROR (-1)

typedef int64_t off64_t;

class String8 {
public:
    String8();
    String8(const char* str);
    String8(const char* str, size_t len);
    const char* c_str() const;
    static String8 format(const char* format, ...);
};

template<typename KEY, typename VALUE>
class KeyedVector {
public:
    KeyedVector();
    ssize_t indexOfKey(const KEY& key) const;
    void add(const KEY& key, const VALUE& value);
};

class AString {
public:
    AString();
    const char* c_str() const;
};

class MediaHTTP {
private:
    status_t mInitCheck;
    String8 mLastURI;
    KeyedVector<String8, String8> mLastHeaders;
    bool mCachedSizeValid;
    String8 mName;
    class HTTPConnection* mHTTPConnection;
public:
    status_t connect(const char* uri, const KeyedVector<String8, String8>* headers, off64_t offset);
};

class HTTPConnection {
public:
    bool connect(const char* uri, const KeyedVector<String8, String8>* headers);
};

String8 MakeUserAgent();
AString uriDebugString(const String8& uri);