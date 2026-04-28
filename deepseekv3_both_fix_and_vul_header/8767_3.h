#include <stdio.h>
#include <limits.h>
#include <string.h>

enum parser_return {
    Continue,
    End,
    Error
};

struct reply_buffer {
    unsigned char *buf;
    int ref_count;
};

typedef struct _XExtDisplayInfo XExtDisplayInfo;
typedef struct _XRecordInterceptData XRecordInterceptData;
typedef void (*XRecordInterceptProc)(void*, XRecordInterceptData*);
typedef void* XPointer;

struct _Display {
    unsigned long last_request_read;
};

struct _xRecordEnableContextReply {
    int idBase;
    int category;
    int clientSwapped;
    unsigned long serverTime;
    unsigned long recordedSequenceNumber;
    int elementHeader;
    int length;
};

struct _XRecordInterceptData {
    int id_base;
    int category;
    int client_swapped;
    unsigned long server_time;
    unsigned long client_seq;
    unsigned char *data;
    int data_len;
};

#define XRecordFromServer 0
#define XRecordFromClient 1
#define XRecordClientStarted 2
#define XRecordClientDied 3
#define XRecordStartOfData 4
#define XRecordEndOfData 5
#define XRecordFromServerTime 0x01
#define XRecordFromClientTime 0x01
#define XRecordFromClientSequence 0x02
#define X_Reply 1

#define EXTRACT_CARD16(swap, src, dst) \
    memcpy(&(dst), (src), 2); \
    if (swap) { \
        dst = ((dst << 8) & 0xff00) | ((dst >> 8) & 0x00ff); \
    }

#define EXTRACT_CARD32(swap, src, dst) \
    memcpy(&(dst), (src), 4); \
    if (swap) { \
        dst = ((dst << 24) & 0xff000000) | \
              ((dst << 8)  & 0x00ff0000) | \
              ((dst >> 8)  & 0x0000ff00) | \
              ((dst >> 24) & 0x000000ff); \
    }

typedef struct _Display Display;
typedef struct _xRecordEnableContextReply xRecordEnableContextReply;

XRecordInterceptData *alloc_inter_data(XExtDisplayInfo *info);