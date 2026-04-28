#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FRAGROUTE_ERRBUF_LEN 256
#define TCPEDIT_ERROR -1
#define OUTFILE 1

typedef void pcap_t;
typedef void pcap_dumper_t;

struct tcpedit_s {
    unsigned int fuzz_seed;
    unsigned int fuzz_factor;
    /* other members as needed */
};

typedef struct tcpedit_s tcpedit_t;
typedef struct tcpdump_s tcpdump_t;
typedef struct fragroute_ctx_s fragroute_ctx_t;

struct options_s {
    pcap_t *pin;
    pcap_dumper_t *pout;
    char *outfile;
    char *fragroute_args;
    fragroute_ctx_t *frag_ctx;
    int verbose;
} options;

extern tcpedit_t *tcpedit;
extern tcpdump_t tcpdump;
extern struct options_s tcprewriteOptions;

extern int tcprewrite_init(void);
extern int optionProcess(void *options, int argc, char *argv[]);
extern void post_args(int argc, char *argv[]);
extern int tcpedit_init(tcpedit_t **tcpedit, int datalink);
extern char *tcpedit_geterr(tcpedit_t *tcpedit);
extern int tcpedit_post_args(tcpedit_t *tcpedit);
extern void tcpedit_close(tcpedit_t **tcpedit);
extern int tcpedit_validate(tcpedit_t *tcpedit);
extern int tcpedit_get_output_dlt(tcpedit_t *tcpedit);
extern void fuzzing_init(unsigned int seed, unsigned int factor);
extern char *safe_strdup(const char *s);
extern char *OPT_ARG(int opt);
extern void dbgx(int level, const char *fmt, ...);
extern int rewrite_packets(tcpedit_t *tcpedit, pcap_t *pin, pcap_dumper_t *pout);
extern void restore_stdin(void);
extern int pcap_datalink(pcap_t *p);
extern pcap_t *pcap_open_dead(int dlt, int snaplen);
extern const char *pcap_datalink_val_to_name(int dlt);
extern pcap_dumper_t *pcap_dump_open(pcap_t *p, const char *fname);
extern void pcap_close(pcap_t *p);
extern void pcap_dump_close(pcap_dumper_t *p);
extern const char *pcap_geterr(pcap_t *p);
extern void err(int status, const char *fmt, ...);
extern void errx(int status, const char *fmt, ...);
extern void warnx(const char *fmt, ...);
extern void tcpdump_open(tcpdump_t *t, pcap_t *p);
extern void tcpdump_close(tcpdump_t *t);
extern fragroute_ctx_t *fragroute_init(int mtu, int dlt, const char *args, char *ebuf);
extern void fragroute_close(fragroute_ctx_t *ctx);