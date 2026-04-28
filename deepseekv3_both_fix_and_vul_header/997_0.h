#include <cstdbool>

class Thread {
public:
    static void sleep(int milliseconds);
};

class File {
public:
    bool isDirectory() const;
    bool deleteRecursively() const;
    bool deleteFile() const;
};

class TemporaryFile {
private:
    File temporaryFile;
public:
    bool deleteTemporaryFile() const;
};