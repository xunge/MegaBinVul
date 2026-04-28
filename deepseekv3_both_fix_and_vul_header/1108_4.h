#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <cstdio>
#include <stdexcept>

using namespace std;

class Timer {
public:
    void start();
    long getTime();
};

enum SampleType { FIXEDPOINT, FLOATINGPOINT };
enum CompressionType { UNCOMPRESSED, JPEG, JPEG2000, PNG };

struct RawTile {
    void* data;
    unsigned int width;
    unsigned int height;
    unsigned int bpc;
    SampleType sampleType;
};

class Image {
public:
    unsigned int getTileWidth();
    unsigned int getTileHeight();
    list<int> getHorizontalViewsList();
    string getMetadata(const string&);
    string getTimestamp();
};

class TileCache;
class Watermark;
class JPEGCompressor;

class TileManager {
public:
    TileManager(TileCache*, Image*, Watermark*, JPEGCompressor*, ostream*, int);
    RawTile getTile(int, int, int, int, int, CompressionType);
};

class Response {
public:
    string createHTTPHeader(const string&, const string&);
    void setImageSent();
};

class Output {
public:
    int putStr(const char*, streampos);
    int flush();
    void putS(const char*);
};

class View {
public:
    int yangle;
    int getLayers();
};

class Session {
public:
    int loglevel;
    ostream* logfile;
    Image** image;
    TileCache* tileCache;
    Watermark* watermark;
    JPEGCompressor* jpeg;
    Response* response;
    Output* out;
    View* view;
};

class SPECTRA {
private:
    Session* session;
    Timer command_timer;
    void checkImage();
public:
    void run(Session* session, const std::string& argument);
};