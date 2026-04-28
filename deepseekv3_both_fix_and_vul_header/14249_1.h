#include <exception>

class BitStreamException : public std::exception {};

class BitStreamReader {
public:
    void setBuffer(const unsigned char*, const unsigned char*);
    void skipBit();
    int getBits(int);
};

class HevcUnit {
public:
    int deserialize();
protected:
    BitStreamReader m_reader;
    unsigned char* m_nalBuffer;
    unsigned int m_nalBufferLen;
    int nal_unit_type;
    int nuh_layer_id;
    int nuh_temporal_id_plus1;
    static const int NOT_ENOUGH_BUFFER = -1;
};