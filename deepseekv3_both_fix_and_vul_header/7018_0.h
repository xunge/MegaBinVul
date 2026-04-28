#include <stdio.h>
#include <sys/types.h>

typedef struct netio_desc netio_desc_t;
typedef struct netio_filter netio_filter_t;

struct netio_desc {
   ssize_t (*recv)(void *, void *, size_t);
   void *dptr;
   int debug;
   char *name;
   netio_filter_t *rx_filter;
   void *rx_filter_data;
   netio_filter_t *both_filter;
   void *both_filter_data;
   unsigned long stats_pkts_in;
   unsigned long stats_bytes_in;
};

struct netio_filter {
   int (*pkt_handler)(netio_desc_t *, void *, ssize_t, void *);
};

#define NETIO_FILTER_ACTION_DROP 1

void mem_dump(FILE *fp, void *data, size_t len);