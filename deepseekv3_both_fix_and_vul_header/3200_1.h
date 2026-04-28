#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int firstPage;
extern int lastPage;

class GooString {
public:
    GooString(const char *str);
    ~GooString();
};

class PDFDoc {
public:
    PDFDoc(GooString *fileName, void *a, void *b, void *c);
    ~PDFDoc();
    bool isOk();
    int getNumPages();
    int savePageAs(GooString *fileName, int page);
};

enum ErrorCode {
    errNone,
    errSyntaxError
};

void error(ErrorCode code, int num, const char *msg, const char *arg);