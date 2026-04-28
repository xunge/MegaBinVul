#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define ETH_ALEN 6
#define MAC_TABLE_ENTRIES 64
#define MAX_VLAN 4096
#define VIRTIO_NET_VM_VERSION 11
#define VIRTIO_NET_F_CTRL_GUEST_OFFLOADS (1 << 0)
#define VIRTIO_NET_S_LINK_UP 1

typedef struct QEMUFile QEMUFile;

typedef struct VirtIODevice {
    uint64_t guest_features;
} VirtIODevice;

typedef struct VirtIONet {
    uint8_t mac[ETH_ALEN];
    struct {
        uint32_t in_use;
        uint8_t macs[MAC_TABLE_ENTRIES * ETH_ALEN];
        uint8_t multi_overflow;
        uint8_t uni_overflow;
        int first_multi;
    } mac_table;
    uint16_t status;
    uint8_t promisc;
    uint8_t allmulti;
    uint8_t alluni;
    uint8_t nomulti;
    uint8_t nouni;
    uint8_t nobcast;
    uint16_t max_queues;
    uint16_t curr_queues;
    uint64_t curr_guest_offloads;
    struct {
        uint32_t tx_waiting;
    } *vqs;
    struct {
        struct {
            int link_down;
        } *queues;
    } *nic;
    uint8_t vlans[MAX_VLAN >> 3];
} VirtIONet;

#define VIRTIO_DEVICE(obj) ((VirtIODevice *)(obj))

static inline void *g_malloc0(size_t size) { return calloc(1, size); }
static inline void g_free(void *ptr) { free(ptr); }

static inline int virtio_load(VirtIODevice *vdev, QEMUFile *f) { return 0; }
static inline void virtio_net_set_mrg_rx_bufs(VirtIONet *n, uint32_t val) {}
static inline int peer_has_vnet_hdr(VirtIONet *n) { return 0; }
static inline int peer_has_ufo(VirtIONet *n) { return 0; }
static inline uint64_t virtio_net_supported_guest_offloads(VirtIONet *n) { return 0; }
static inline void virtio_net_apply_guest_offloads(VirtIONet *n) {}
static inline void virtio_net_set_queues(VirtIONet *n) {}
static inline void qemu_get_buffer(QEMUFile *f, void *buf, int size) {}
static inline uint32_t qemu_get_be32(QEMUFile *f) { return 0; }
static inline uint16_t qemu_get_be16(QEMUFile *f) { return 0; }
static inline uint64_t qemu_get_be64(QEMUFile *f) { return 0; }
static inline uint8_t qemu_get_byte(QEMUFile *f) { return 0; }
static inline void error_report(const char *fmt, ...) {}

static inline struct {
    int link_down;
} *qemu_get_subqueue(void *nic, int i) {
    return ((VirtIONet *)nic)->nic->queues + i;
}