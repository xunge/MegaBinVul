#include <string>

#define CV_PARSE_ERROR_CPP(msg) 
#define cv_isprint(c) isprint(c)

struct FileNode {
    enum { NONE };
    FileNode addNode(FileNode&, const std::string&, int);
};

extern FileNode* fs;