#include <memory>
#include <map>

enum de265_error {
    DE265_OK,
    DE265_WARNING_PPS_HEADER_INVALID
};

const int LogHeaders = 0;

class bitreader {
public:
    // dummy implementation
};

class decoder_context;

class pic_parameter_set {
public:
    int pic_parameter_set_id;
    bool read(bitreader* reader, decoder_context* ctx);
    void dump(int fd) {}
};

class decoder_context {
public:
    std::map<int, std::shared_ptr<pic_parameter_set>> pps;
    int param_pps_headers_fd;
    void logdebug(int, const char*) {}
    de265_error read_pps_NAL(bitreader& reader);
};