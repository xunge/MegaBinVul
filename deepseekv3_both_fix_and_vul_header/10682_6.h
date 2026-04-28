#include <stdint.h>
#include <cstddef>

typedef void *PMDL;
typedef unsigned int *PUINT;
typedef unsigned long ULONG;
typedef uint8_t UINT8;

struct NET_BUFFER_LIST {
    void* SourceHandle;
    void* MiniportReserved[1];
    int Status;
    void* TcpIpChecksumNetBufferListInfo;
};

typedef NET_BUFFER_LIST *PNET_BUFFER_LIST;

struct _NET_PACKET_INFO {
    int hasVlanHeader;
    ULONG dataLength;
    void *headersBuffer;
};

typedef struct _NET_PACKET_INFO NET_PACKET_INFO, *PNET_PACKET_INFO;

typedef struct _PARANDIS_ADAPTER {
    ULONG ulPriorityVlanSetting;
    void *MiniportHandle;
    void *BufferListsPool;
    struct {
        ULONG nMaxDataSize;
    } MaxPacketSize;
} PARANDIS_ADAPTER;

typedef struct _RxNetDescriptor {
    PMDL Holder;
    NET_PACKET_INFO PacketInfo;
    struct {
        void *Virtual;
    } PhysicalPages[1];
} *pRxNetDescriptor;

typedef struct _virtio_net_hdr_basic {
    UINT8 flags;
    UINT8 gso_type;
} virtio_net_hdr_basic;

typedef struct _tChecksumCheckResult {
    ULONG value;
    struct {
        int IpFailed;
        int IpOK;
        int TcpFailed;
        int TcpOK;
        int UdpFailed;
        int UdpOK;
    } flags;
} tChecksumCheckResult;

typedef struct _tTcpIpPacketParsingResult {
    ULONG value;
} tTcpIpPacketParsingResult;

typedef PNET_BUFFER_LIST tPacketIndicationType;

struct NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO {
    union {
        void* Value;
        struct {
            int IpChecksumFailed;
            int IpChecksumSucceeded;
            int TcpChecksumFailed;
            int TcpChecksumSucceeded;
            int UdpChecksumFailed;
            int UdpChecksumSucceeded;
        } Receive;
    };
};

enum {
    NDIS_STATUS_SUCCESS
};

#define PARANDIS_FIRST_RX_DATA_PAGE 0
#define PARANDIS_SUPPORT_RSC 0
#define ETH_HEADER_SIZE 14
#define pcrIpChecksum 0x01
#define pcrTcpChecksum 0x02
#define pcrUdpChecksum 0x04

#define DPrintf(level, fmt)
#define NBLSetRSSInfo(ctx, nbl, pkt)
#define NBLSet8021QInfo(ctx, nbl, pkt)
#define NBLSetRSCInfo(ctx, nbl, pkt, cnt)
#define PktGetTCPCoalescedSegmentsCount(pkt, sz) 1
#define ParaNdis_StripVlanHeaderMoveHead(pkt) 0
#define ParaNdis_PadPacketToMinimalLength(pkt)
#define ParaNdis_AdjustRxBufferHolderLength(desc, len)
#define ParaNdis_CheckRxChecksum(ctx, flags, pages, len, stripped, ...) {0}
#define ParaNdis_CheckSumVerify(buf, len, flags, func) {0}
#define ParaNdis_DebugHistory(ctx, op, nbl, len, val, rev)
#define NET_BUFFER_LIST_INFO(nbl, type) ((nbl)->TcpIpChecksumNetBufferListInfo)
#define VIRTIO_NET_HDR_GSO_NONE 0
#define RtlOffsetToPointer(base, offset) ((void*)((char*)(base) + (offset)))
#define NdisAllocateNetBufferAndNetBufferList(pool, size, offset, mdl, start, len) ((PNET_BUFFER_LIST)NULL)