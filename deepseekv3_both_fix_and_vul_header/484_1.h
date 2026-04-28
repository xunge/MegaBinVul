#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <string>

struct FileNode {
    enum { NONE };
    int type;
    FileNode(void*, int, int) {}
    bool isMap() { return false; }
    bool isSeq() { return false; }
};

struct FileStorage {
    void* getFS() { return nullptr; }
    bool eof() { return false; }
    FileNode addNode(FileNode, std::string, int) { return FileNode(nullptr, 0, 0); }
};

FileStorage* fs;

char* skipSpaces(char*, int, int) { return nullptr; }
char* parseValue(char*, FileNode, int, bool) { return nullptr; }

#define CV_PARSE_ERROR_CPP(msg) 

bool cv_isalnum(char) { return false; }