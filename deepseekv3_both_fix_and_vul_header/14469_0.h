#include <memory>
#include <cstdint>
#include <vector>

enum de265_error {
  DE265_OK
};

const int LogHeaders = 0;

class bitreader {
public:
};

class decoder_context;

class seq_parameter_set {
public:
  int seq_parameter_set_id;
  de265_error read(decoder_context*, bitreader*);
  void dump(int);
};

class pic_parameter_set {
public:
  int seq_parameter_set_id;
};

class decoder_context {
public:
  int param_sps_headers_fd;
  std::shared_ptr<seq_parameter_set> sps[256];
  std::vector<std::shared_ptr<pic_parameter_set>> pps;
  void logdebug(int, const char*);
  de265_error read_sps_NAL(bitreader&);
};