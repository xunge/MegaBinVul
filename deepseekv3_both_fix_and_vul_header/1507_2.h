#include <assert.h>
#include <errno.h>

typedef struct DnsStream DnsStream;

struct DnsStream {
    int encrypted;
    void (*complete)(struct DnsStream *s, int error);
};

#define _cleanup_(x)
#define _unused_ 
#define ENABLE_DNS_OVER_TLS 1

static struct DnsStream* dns_stream_ref(struct DnsStream *s) { return s; }
static void dns_stream_unref(struct DnsStream *s) {}
static void dns_stream_unrefp(struct DnsStream **s) {}
static void dns_stream_stop(struct DnsStream *s) {}
static int dnstls_stream_shutdown(struct DnsStream *s, int error) { return 0; }