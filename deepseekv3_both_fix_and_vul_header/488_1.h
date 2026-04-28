#include <cstring>
#include <string>

#define CV_Assert(expr) ((void)0)
#define CV_PARSE_ERROR_CPP(msg) ((void)0)
#define CV_XML_INSIDE_TAG 0
#define CV_XML_OPENING_TAG 0
#define CV_XML_CLOSING_TAG 0

struct FileStorage;
struct FileNode;

struct FileNode {
    enum { MAP };
    FileNode(FileStorage*, int, int);
};

struct FileStorage {
    bool eof();
    FileNode addNode(FileNode&, std::string, int, int);
    FileStorage* getFS();
};

char* skipSpaces(char*, int);
char* parseTag(char*, std::string&, std::string&, int&);
char* parseValue(char*, FileNode&);

FileStorage* fs = 0;