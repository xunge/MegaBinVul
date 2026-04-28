#include <string>

struct FileNode {
    enum { MAP, SEQ };
    FileNode(void*, int, int) {}
};

struct FileStorage {
    void* getFS() { return nullptr; }
    FileNode addNode(FileNode&, const std::string&, int) { return FileNode(nullptr, 0, 0); }
};

FileStorage* fs;

char* skipSpaces(char* ptr) { return ptr; }
void parseMap(char*& ptr, FileNode node) {}
void parseSeq(char*& ptr, FileNode node) {}
#define CV_PARSE_ERROR_CPP(msg) {}