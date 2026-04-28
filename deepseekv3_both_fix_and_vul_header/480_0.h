#include <string>
#include <cctype>

#define CV_PARSE_ERROR_CPP(msg) 
#define CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP() 
#define cv_isprint(c) std::isprint(c)

struct FileNode {
    enum { NONE };
    FileNode addNode(FileNode&, const std::string&, int);
};

FileNode* fs;

char* skipSpaces(char* ptr);