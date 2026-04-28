#include <stdlib.h>

struct NameValueParserData {
    void *l_head;
    char *portListing;
    int portListingLength;
};

struct xmlparser {
    const char *xmlstart;
    int xmlsize;
    struct NameValueParserData *data;
    void (*starteltfunc)(void *, const char *, int);
    void (*endeltfunc)(void *, const char *, int);
    void (*datafunc)(void *, const char *, int);
    void (*attfunc)(void *, const char *, int, const char *, int);
};

void NameValueParserStartElt(void *, const char *, int);
void NameValueParserEndElt(void *, const char *, int);
void NameValueParserGetData(void *, const char *, int);
void parsexml(struct xmlparser *);