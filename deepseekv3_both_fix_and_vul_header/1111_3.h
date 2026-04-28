#include <iostream>
#include <cmath>
#include <cstring>

using std::endl;

enum SampleType { FIXEDPOINT, FLOATINGPOINT };
const int UNCOMPRESSED = 0;

class RawTile {
public:
    RawTile(int, unsigned int, int, int, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned int width;
    unsigned int height;
    unsigned int channels;
    unsigned int bpc;
    unsigned int dataLength;
    SampleType sampleType;
    void* data;
};

class Image {
public:
    bool regionDecoding();
    RawTile getRegion(int, int, unsigned int, int, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned int getTileWidth();
    unsigned int getTileHeight();
    unsigned int getNumResolutions();
    unsigned int getNumChannels();
    unsigned int getNumBitsPerPixel();
    SampleType getSampleType();
    unsigned int* image_widths;
    unsigned int* image_heights;
};

class Timer {
public:
    void start();
    unsigned long getTime();
};

class TileManager {
public:
    RawTile getTile(unsigned int, unsigned int, int, int, int, int);
    RawTile getRegion(unsigned int, int, int, int, unsigned int, unsigned int, unsigned int, unsigned int);
    Image* image;
    std::ostream* logfile;
    int loglevel;
    Timer tile_timer;
};