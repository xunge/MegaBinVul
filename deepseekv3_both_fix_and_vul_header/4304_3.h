#include <string>

struct Response {};
struct Timing {
    double responseEnd();
};

class String {
public:
    bool isEmpty() const;
};

class IntSize {
public:
    int width();
};

class ImageResource {
public:
    void setResponse(const Response&);
    void setLoadFinishTime(double);
    void finish();
    IntSize imageSize(bool, float);
};

class DocumentLoader {
public:
    Response response();
    Timing timing();
};

class LayoutObject {
public:
    static bool shouldRespectImageOrientation(LayoutObject*);
};

class ImageDocumentParser {
public:
    bool isStopped();
    bool isDetached();
    class Document* document();
    void finish();
};

class Document {
public:
    class ImageElement* imageElement();
    ImageResource* cachedImage();
    DocumentLoader* loader();
    class URL url();
    void setTitle(const String&);
    void imageUpdated();
    void finishedParsing();
};

class ImageElement {
public:
    LayoutObject* layoutObject();
};

class URL {
public:
    String lastPathComponent();
    String host();
};

String decodeURLEscapeSequences(const String&);
String imageTitle(const String&, const IntSize&);
IntSize flooredIntSize(const IntSize&);