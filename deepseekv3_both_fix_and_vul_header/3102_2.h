#include <stdio.h>
#include <stdlib.h>

struct Document {
    void decrementLoadEventDelayCount();
    void incrementLoadEventDelayCount();
};

struct HTMLElement {
    void didMoveToNewDocument(Document*);
};

struct HTMLMediaElement : public HTMLElement {
    bool m_shouldDelayLoadEvent;
    void userCancelledLoad();
    Document* document();
    void LOG(const char*, const char*);
    void didMoveToNewDocument(Document*);
};

const char* Media = "Media";

void removeElementFromDocumentMap(HTMLMediaElement*, Document*);
void addElementToDocumentMap(HTMLMediaElement*, Document*);