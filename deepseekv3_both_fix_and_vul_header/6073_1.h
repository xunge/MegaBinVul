#include <assert.h>
#include <string.h>

class Next {
public:
    void write(unsigned char* data, unsigned int size);
};

class Key {
public:
    unsigned char* get();
};

class Crypto {
public:
    void rijndael_init(bool encrypt, unsigned char* key, unsigned int key_bytes, bool cbc_mode, unsigned char* cbc_block);
    void rijndael_process(unsigned char* inbuf, unsigned char* outbuf);
};

class Pl_AES_PDF {
private:
    unsigned int offset;
    unsigned int buf_size;
    bool first;
    bool cbc_mode;
    bool encrypt;
    bool use_zero_iv;
    bool use_specified_iv;
    unsigned char* cbc_block;
    unsigned char* inbuf;
    unsigned char* outbuf;
    Key key;
    unsigned int key_bytes;
    Crypto* crypto;
    Next* getNext();
    void initializeVector();
public:
    void flush(bool strip_padding);
};