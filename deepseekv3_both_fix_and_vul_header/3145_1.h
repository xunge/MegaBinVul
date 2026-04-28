#include <stdlib.h>

struct HTMLTemplateElement {
    struct Content* m_content;
    ~HTMLTemplateElement();
};

struct Content {
    void clearHost();
};