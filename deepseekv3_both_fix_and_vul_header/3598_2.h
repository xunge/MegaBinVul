#include <string>
#include <exception>

class String {
public:
    String();
    String(const char*);
    unsigned length() const;
    void remove(unsigned offset, unsigned count);
    void insert(const String& data, unsigned offset);
    static String number(unsigned);
    friend String operator+(const char*, const String&);
    friend String operator+(const String&, const String&);
};

class ExceptionState {
public:
    void throwDOMException(int, const String&);
};

class Document {
public:
    void didRemoveText(void*, unsigned, unsigned);
    void didInsertText(void*, unsigned, unsigned);
};

enum DOMExceptionType {
    IndexSizeError
};

class CharacterData {
public:
    void replaceData(unsigned offset, unsigned count, const String& data, ExceptionState& exceptionState);
protected:
    String m_data;
    Document& document();
    unsigned length() const;
    bool validateOffsetCount(unsigned, unsigned, unsigned, unsigned&, ExceptionState&);
    void setDataAndUpdate(const String&, unsigned, unsigned, unsigned);
};