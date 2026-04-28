#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdint>

#define HAVE_MAGICKWAND 0
#define MAXSLIDESIZE 8192
#define MAXSEGLEN 1024
#define SLS_PARAMS_SUFFIX ""
#define JPEGInterlace 0

typedef std::vector<uint8_t> uint8_vector_t;

struct DATA_GROUP {
    std::vector<unsigned char> data;
};

struct MSCDG {
    int type;
    int* cindex;
    int segment_number;
    int last_segment;
    int file_index;
    unsigned char* data;
    size_t data_size;
};

class PADPacketizer {
public:
    static DATA_GROUP* CreateDataGroupLengthIndicator(size_t size);
    void AddDG(DATA_GROUP* dg, bool flag);
};

class SLSManager {
public:
    bool encodeFile(const std::string& fname, int fidx, bool raw_slides);
};

extern bool verbose;
extern int cindex_header;
extern int cindex_body;
extern int ret;
extern PADPacketizer* pad_packetizer;

uint8_vector_t createMotHeader(size_t blobsize, int fidx, bool jfif_not_png, const std::string& params);
void createMscDG(MSCDG* msc, int type, int* cindex, int seg_num, int last, int fidx, unsigned char* data, size_t data_size);
DATA_GROUP* packMscDG(MSCDG* msc);
size_t resizeImage(void* m_wand, unsigned char** blob, const std::string& fname, bool* jfif_not_png);
void warnOnSmallerImage(size_t height, size_t width, const std::string& fname);