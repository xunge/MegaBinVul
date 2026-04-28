#include <assert.h>
#include <stdbool.h>

#define ASSERT assert

typedef void* xsltStylesheetPtr;
typedef void* xmlDocPtr;

struct XSLStyleSheet {
    bool m_embedded;
    bool m_compilationFailed;
    bool m_stylesheetDocTaken;
    xmlDocPtr m_stylesheetDoc;
    
    xsltStylesheetPtr compileStyleSheet();
};

extern xmlDocPtr document();
extern xsltStylesheetPtr xsltLoadStylesheetPI(xmlDocPtr doc);
extern xsltStylesheetPtr xsltParseStylesheetDoc(xmlDocPtr doc);