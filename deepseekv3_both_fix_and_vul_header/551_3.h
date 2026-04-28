#include <string>

struct binistream {
    void readString(char*, int);
    void seek(int);
};

struct CFileProvider {
    binistream* open(const std::string&) const;
    unsigned long filesize(binistream*) const;
    void close(binistream*) const;
};

struct data_block {
    unsigned long size;
    unsigned char* data;
};

class Cu6mPlayer {
public:
    bool load(const std::string &filename, const CFileProvider &fp);
    unsigned char* song_data = nullptr;
    void rewind(int);
};

bool lzw_decompress(const data_block& source, const data_block& destination);