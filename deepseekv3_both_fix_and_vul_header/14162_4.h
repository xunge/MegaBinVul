#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iterator>

namespace {
const int LOGINFO = 0;
const int LOGERROR = 1;
const int TIXML_DEFAULT_ENCODING = 0;
}

class TiXmlNode;
class TiXmlElement;
class TiXmlAttribute;

class CLog {
public:
    static void Log(int level, const char* format, ...);
};

class CXBMCTinyXML {
public:
    bool Parse(const std::string& data, int encoding);
    bool Error() const;
    const char* ErrorDesc() const;
    TiXmlElement* RootElement();
    friend std::istream& operator>>(std::istream& stream, CXBMCTinyXML& doc);
};

class TiXmlNode {
public:
    enum NodeType { TINYXML_ELEMENT };
    TiXmlNode* IterateChildren(TiXmlNode* previous);
    TiXmlNode* Parent();
    const char* Value() const;
    void SetValue(const std::string& value);
    int Type() const;
    TiXmlElement* ToElement();
    TiXmlNode* FirstChild();
    std::string ValueStr() const;
};

class TiXmlElement : public TiXmlNode {
public:
    TiXmlElement* FirstChildElement(const char* value = nullptr);
    TiXmlElement* NextSiblingElement(const char* value = nullptr);
    TiXmlAttribute* FirstAttribute();
    bool NoChildren() const;
};

class TiXmlAttribute {
public:
    const char* Name() const;
    void SetName(const std::string& name);
    TiXmlAttribute* Next();
};

class StringUtils {
public:
    static void ToLower(std::string& str);
};

class XMLUtils {
public:
    static std::string GetAttribute(TiXmlElement* element, const char* attribute);
};

class CFileItem {
public:
    CFileItem(const std::string& title);
    void SetPath(const std::string& path);
};

class CFileItemPtr {
public:
    CFileItemPtr(CFileItem* item);
    CFileItem* operator->();
};

class CPlayList {
public:
    virtual bool Load(const std::string& path) = 0;
};

class CPlayListFactory {
public:
    static CPlayList* Create(const std::string& path);
};

class CPlayListASX {
public:
    bool LoadData(std::istream& stream);
    void Add(const CFileItemPtr& item);
    void Add(const CPlayList& playlist);
    bool LoadAsxIniInfo(std::istream& stream);
};