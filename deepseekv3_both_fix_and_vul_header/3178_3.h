#include <stdbool.h>

struct ConstructionType {
    int value;
};

class QualifiedName {
};

class Document {
};

class ScriptWrappable {
public:
    static void init(void*);
};

class Element {
public:
    Element(const QualifiedName&, Document*, ConstructionType);
};

class SVGElement : public Element {
public:
    SVGElement(const QualifiedName&, Document&, ConstructionType);
    void registerAnimatedPropertiesForSVGElement();
    void setHasCustomStyleCallbacks();
#if !ASSERT_DISABLED
    bool m_inRelativeLengthClientsInvalidation;
#endif
};

#define ASSERT_DISABLED 0