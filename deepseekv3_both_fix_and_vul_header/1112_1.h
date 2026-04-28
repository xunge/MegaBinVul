#include <stdexcept>
#include <string>

struct RawTile {
    int dummy1;
    unsigned int res;
    int ha;
    int va;
    unsigned int w;
    unsigned int h;
    unsigned int channels;
    unsigned int obpc;
    void* data;
    unsigned int dataLength;
    std::string filename;
    unsigned long timestamp;

    RawTile(int, unsigned int, int, int, unsigned int, unsigned int, unsigned int, unsigned int);
};

class OpenJPEGImage {
public:
    RawTile getRegion(int ha, int va, unsigned int res, int layers, int x, int y, unsigned int w, unsigned int h);
private:
    unsigned int bpc;
    unsigned int channels;
    unsigned long timestamp;
    std::string getImagePath();
    void process(int res, int layers, int x, int y, unsigned int w, unsigned int h, void* data);
};

class file_error : public std::runtime_error {
public:
    explicit file_error(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#ifdef DEBUG
#include <iostream>
#include <chrono>

class Timer {
public:
    void start();
    long getTime();
};

extern std::ostream logfile;
extern std::ostream endl;
#endif