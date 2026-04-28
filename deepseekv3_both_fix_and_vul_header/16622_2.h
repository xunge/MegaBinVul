#include <stdint.h>
#include <assert.h>

#define assertx assert

struct StringData {
    int64_t m_lenAndHash;
    int m_hash;
    
    bool isImmutable() const;
    bool hasMultipleRefs() const;
    int64_t capacity() const;
    char* mutableData();
    bool checkSane() const;
    
    void setSize(int64_t len);
    void setSize(int len);
};