#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

struct pcap_pkthdr {
    struct timeval ts;
    unsigned int caplen;
    unsigned int len;
};

struct state {
    struct pcap_pkthdr hdr;
    u_char *pkt;
    void *p;
    struct timeval file_start_time;
    struct timeval file_stop_time;
    int done;
    long start_pos;
    long stop_pos;
};

extern int snaplen;
extern int sessions_count;
extern int track_sessions;
extern int bonus_time;
extern void *global_dumper;

void error(const char *fmt, ...);
void sf_find_packet(void *p, struct timeval *min_time, long start_pos, struct timeval *max_time, long stop_pos, struct timeval *target_time);
void get_next_packet(struct state *s);
int sf_timestamp_less_than(const struct timeval *t1, const struct timeval *t2);
void sessions_exit(void);
void pcap_close(void *p);
void *pcap_dump_open(void *p, const char *fname);
const char *pcap_geterr(void *p);
void pcap_dump(void *dumper, struct pcap_pkthdr *hdr, u_char *pkt);