#include <stdint.h>
#include <algorithm>

using std::min;

class IOContextDemuxer {
public:
    void skip_bytes(const int64_t size);
private:
    uint8_t* m_curPos;
    uint8_t* m_bufEnd;
    int64_t m_processedBytes;
    int64_t m_fileBlockSize;
    int m_readerID;
    class BufferedReader {
    public:
        void seek(int readerID, int64_t size);
        uint8_t* readBlock(int readerID, uint32_t& readedBytes, int& readRez);
        void notify(int readerID, uint32_t readedBytes);
    };
    BufferedReader* m_bufferedReader;
};

inline int64_t min(uint32_t a, int64_t b) {
    return a < b ? a : b;
}