#include <string>
#include <cstdint>
#include <cstring>

class StringBuilder {
public:
    void append(char);
    void appendLiteral(const char*);
};

class Element {
public:
    bool hasTagName(const char*);
};

class HTMLNames {
public:
    static const char htmlTag[];
    static const char baseTag[];
};

class String {
public:
    static String format(const char*, int, const char*);
    bool isEmpty() const;
    std::string utf8() const;
    const char* data() const;
};

class MarkupFormatter {
public:
    static void appendComment(StringBuilder&, const String&);
    static void appendAttributeValue(StringBuilder&, const String&, bool);
};

class Document {
public:
    class URL {
    public:
        String string() const;
    };
    
    URL url() const;
    String baseTarget() const;
    bool isHTMLDocument() const;
    bool isXHTMLDocument() const;
};

class Namespaces {};

class SerializerMarkupAccumulator {
public:
    void appendElement(StringBuilder&, Element&, Namespaces*);
};

class LinkChangeSerializerMarkupAccumulator : public SerializerMarkupAccumulator {
public:
    Document& document() const;
    void appendElement(StringBuilder&, Element&, Namespaces*);
};

class PageSerializer {
public:
    static String markOfTheWebDeclaration(const Document::URL&);
};

const char HTMLNames::htmlTag[] = "html";
const char HTMLNames::baseTag[] = "base";