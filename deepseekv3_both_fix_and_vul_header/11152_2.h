#include <stdint.h>
#include <exception>
#include <iostream>

#define __le32 uint32_t
#define __le64 uint64_t
#define __u8 uint8_t
#define __attribute__(x)
#define HAVE_FEATURE(x, y) (x & y)
#define AUTH_ENC_MAGIC 0
#define CEPHX_V2 0
#define dendl ""
#define ldout(cct, level) if (1) {} else std::cout
#define lderr(cct) if (1) {} else std::cerr

template<typename T>
T mswab(T x) { return x; }

using ceph_msg_header = struct {
    __le32 crc;
    __le32 front_len;
    __le32 middle_len;
    __le32 data_len;
    __le32 seq;
};

using ceph_msg_footer = struct {
    __le32 front_crc;
    __le32 middle_crc;
    __le32 data_crc;
};

class Message {
public:
    const ceph_msg_header& get_header() { static ceph_msg_header h; return h; }
    const ceph_msg_footer& get_footer() { static ceph_msg_footer f; return f; }
    __le32 get_seq() { return 0; }
};

class CryptoKey {
public:
    struct in_slice_t {
        size_t len;
        const unsigned char* data;
    };
    struct out_slice_t {
        size_t len;
        unsigned char* data;
    };
    static size_t get_max_outbuf_size(size_t) { return 0; }
    void encrypt(void*, in_slice_t, out_slice_t) {}
};

class CephxSessionHandler {
    CryptoKey key;
    void* cct;
    int features;
public:
    int _calc_signature(Message *m, uint64_t *psig);
};