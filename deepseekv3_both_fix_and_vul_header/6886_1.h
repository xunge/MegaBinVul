#include <sys/stat.h>
#include <unistd.h>
#include <string>

class Resource;

class ResourceHost {
public:
    std::string baseDiskPath;
    Resource* getResource(std::string uri);
    Resource* readDirectory(const std::string& path, const struct stat& sb);
    Resource* readFile(const std::string& path, const struct stat& sb);
};