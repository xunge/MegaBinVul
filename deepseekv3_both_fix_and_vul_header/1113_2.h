#include <stdexcept>
#include <string>
#include <iostream>

struct RawTile {
    RawTile(int, unsigned int, int, int, unsigned int, unsigned int, unsigned int, unsigned int);
    void* data;
    unsigned int dataLength;
    std::string filename;
    unsigned int timestamp;
    unsigned int res;
    int seq;
    int ang;
    unsigned int w;
    unsigned int h;
    unsigned int channels;
    unsigned int bpc;
};

class KakaduImage {
public:
    unsigned int bpc;
    unsigned int channels;
    unsigned int timestamp;
    std::string getImagePath();
    void process(unsigned int, int, int, int, unsigned int, unsigned int, void*);
    RawTile getRegion(int seq, int ang, unsigned int res, int layers, int x, int y, unsigned int w, unsigned int h);
};

class file_error : public std::runtime_error {
public:
    explicit file_error(const std::string& what_arg);
};

struct Timer {
    void start();
    unsigned long getTime();
};

extern std::ostream logfile;