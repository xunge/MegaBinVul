#include <string.h>

struct mbuf {
  char *buf;
  size_t len;
};

struct mg_connection {
  struct mbuf recv_mbuf;
};

struct mg_http_proto_data {
  struct {
    const char *boundary;
    size_t boundary_len;
    int state;
  } mp_stream;
};

enum {
  MPS_FINALIZE,
  MPS_GOT_BOUNDARY
};

const char *c_strnstr(const char *s, const char *find, size_t slen);
void mbuf_remove(struct mbuf *mbuf, size_t n);
struct mg_http_proto_data *mg_http_get_proto_data(struct mg_connection *c);