#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CCN_DTAG_INTEREST 1
#define CCN_TT_DTAG 2
#define CCN_DTAG_NAME 3
#define CCN_DTAG_COMPONENT 4
#define CCN_DTAG_CONTENTOBJ 5
#define CCNL_DTAG_SUITE 6
#define CCNL_DTAG_CHUNKNUM 7
#define CCNL_DTAG_CHUNKFLAG 8

#define DEBUGMSG(level, ...)
#define ERROR 1
#define DEBUG 2

struct ccnl_prefix_s {
    int *chunknum;
};

void *ccnl_malloc(size_t size);
void ccnl_free(void *ptr);
struct ccnl_prefix_s *getPrefix(unsigned char *data, int datalen, int *suite);
char *ccnl_prefix_to_path(struct ccnl_prefix_s *prefix);
char *ccnl_prefix_to_path_detailed(struct ccnl_prefix_s *prefix, int a, int b, int c);
int ccnl_ccnb_mkHeader(unsigned char *out, int tag, int type);
int ccnl_ccnb_mkStrBlob(unsigned char *out, int tag, int type, const char *str);
int ccnl_ccnb_mkBlob(unsigned char *out, int tag, int type, const char *data, int len);