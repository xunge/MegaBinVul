#include <stdbool.h>
#include <assert.h>
#include <unordered_set>

struct ContainerNode;
struct SVGElement;

struct ContainerNode {
    virtual ContainerNode* parentNode() = 0;
    virtual bool isSVGElement() = 0;
};

struct SVGElement : public ContainerNode {
    bool m_inRelativeLengthClientsInvalidation;
    std::unordered_set<SVGElement*> m_elementsWithRelativeLengths;
    
    bool hasRelativeLengths();
    bool inDocument();
    void updateRelativeLengthsInformation(bool clientHasRelativeLengths, SVGElement* clientElement);
};

SVGElement* toSVGElement(ContainerNode* node);
#define ASSERT assert
#define add insert
#define remove erase