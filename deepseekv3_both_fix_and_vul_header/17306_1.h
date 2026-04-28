#include <cstddef>
#include <string>

#define LARGE_BUFFER_SIZE 1024
#define INFLATE_LESS_THAN_ROUGHLY 1048576
#define Z_BUF_ERROR (-5)
#define Z_OK 0
#define Z_FINISH 4

typedef unsigned char Bytef;

struct z_stream {
    Bytef *next_in;
    unsigned int avail_in;
    Bytef *next_out;
    unsigned int avail_out;
};

extern "C" {
    int inflate(z_stream *strm, int flush);
    int inflateReset(z_stream *strm);
}

class Hub {
private:
    z_stream inflationStream;
    char inflationBuffer[LARGE_BUFFER_SIZE];
    std::string dynamicInflationBuffer;
public:
    char *inflate(char *data, size_t &length);
};