#include <cstdint>
#include <vector>
#include <algorithm>

#define FILETAG_END_OF_COMPRESSED 1
#define FILETAG_END_OF_UNCOMPRESSED 2
#define FILETAG_EMBEDDED_PICTURE 3
#define FILETAG_OLE_OBJECT 4
#define FILETAG_HYPERTEXT 5
#define FILETAG_PRESENTATION 7
#define FILETAG_PREVIEW_IMAGE 8
#define FILETAG_PREVIEW_TEXT 9
#define SAL_MAX_UINT16 65535

class HWPFile;

struct EmPicture {
    EmPicture(int) {}
    bool Read(HWPFile&) { return false; }
};

struct OlePicture {
    OlePicture(int) {}
    void Read(HWPFile&) {}
};

struct HyperText {
    void Read(HWPFile&) {}
};

struct BackInfo {
    char reserved1[8];
    int luminance;
    int contrast;
    char effect;
    char reserved2[7];
    char filename[260];
    char color[3];
    char flag;
    char range;
    char reserved3[27];
    int size;
    std::vector<char> data;
    int type;
    bool isset;
};

struct HWPInfo {
    BackInfo back_info;
};

class HWPFile {
public:
    HWPInfo _hwpInfo;
    std::vector<EmPicture*> emblist;
    std::vector<HyperText*> hyperlist;
    OlePicture* oledata;

    bool Read4b(uint32_t&) { return false; }
    bool Read4b(int&) { return false; }
    bool Read1b(char&) { return false; }
    bool Read2b(uint16_t&) { return false; }
    void ReadBlock(void*, int) {}
    size_t ReadBlock(void*, size_t) { return 0; }
    void SkipBlock(int) {}
    void TagsRead();
};