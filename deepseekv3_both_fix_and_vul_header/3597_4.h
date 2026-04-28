#include <string>
#include <stdexcept>

class CharacterData;

enum DOMExceptionType {
    IndexSizeError
};

enum RecalcStyleBehavior {};

class ExceptionState {
public:
    void throwDOMException(DOMExceptionType, const std::string&);
};

class String {
public:
    String();
    String(const char*);
    String(const std::string&);
    void remove(unsigned, unsigned);
    static String number(unsigned);
    operator std::string() const;
    String operator+(const String&) const;
    friend String operator+(const char*, const String&);
};

inline String operator+(const char* lhs, const String& rhs) {
    return String(lhs) + rhs;
}

class Document {
public:
    void didRemoveText(CharacterData*, unsigned, unsigned);
};

class CharacterData {
public:
    unsigned length() const;
    void setDataAndUpdate(const String&, unsigned, unsigned, unsigned, RecalcStyleBehavior);
    Document& document();
    bool validateOffsetCount(unsigned, unsigned, unsigned, unsigned&, ExceptionState&);
    void deleteData(unsigned, unsigned, ExceptionState&, RecalcStyleBehavior);
    
private:
    std::string m_data;
};