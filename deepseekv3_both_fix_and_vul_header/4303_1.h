#include <stddef.h>

typedef struct ImageResource ImageResource;
typedef struct ImageElement ImageElement;

struct ImageDocument {
    ImageElement* m_imageElement;
    void createDocumentStructure();
    bool isStopped();
    ImageResource* cachedImage();
};

struct ImageElement {
    ImageResource* cachedImage();
};