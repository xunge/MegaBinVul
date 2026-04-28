#include <stdio.h>
#include <vector>
#include <string>

typedef struct _xmlNode xmlNode;
typedef xmlNode* xmlNodePtr;
typedef unsigned char xmlChar;

class GString {
public:
    GString(const char* str);
    ~GString();
    const char* getCString();
};

class IWord {
public:
    int idWord;
    double xMax;
    double yMax;
};

struct ImageInline {
    int idWordBefore;
    int getXPositionImage();
    int getYPositionImage();
    int getWidthImage();
    int getHeightImage();
    GString* getHrefImage();
    int getIdx();
    int getIdImageCurrent();
};

class TextPage {
public:
    void addImageInlineNode(xmlNodePtr nodeline, xmlNodePtr nodeImageInline, char* tmp, IWord* word);
private:
    std::vector<ImageInline*> listeImageInline;
    int indiceImage;
    int idWORDBefore;
    int num;
    int numToken;
    int idImageInline;
};

#define TAG_TOKEN "token"
#define ATTR_ID "id"
#define ATTR_SID "sid"
#define ATTR_NUMFORMAT "%d"
#define ATTR_X "x"
#define ATTR_Y "y"
#define ATTR_WIDTH "width"
#define ATTR_HEIGHT "height"
#define ATTR_HREF "href"

enum XML_Element_Type {
    XML_ELEMENT_NODE = 1
};

struct _xmlNode {
    XML_Element_Type type;
};

xmlNodePtr xmlNewNode(void*, const xmlChar*);
void xmlNewProp(xmlNodePtr, const xmlChar*, const xmlChar*);
void xmlAddChild(xmlNodePtr, xmlNodePtr);

GString* buildIdToken(int num, int numToken, GString* id);
GString* buildSID(int num, int idx, GString* id);

typedef int GBool;
#define gTrue 1
#define gFalse 0