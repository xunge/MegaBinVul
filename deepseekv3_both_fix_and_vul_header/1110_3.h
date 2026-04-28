#include <cstdlib>
#include <cstring>
#include <iostream>

using std::endl;

struct RawTile {
    int width;
    int height;
    int channels;
    int bpc;
    unsigned char* data;
    int dataLength;
    bool padded;
};

class TileManager {
public:
    void crop(RawTile* ttt);
private:
    int loglevel;
    std::ostream* logfile;
    class Image {
    public:
        int getTileWidth();
        int getTileHeight();
    } *image;
};