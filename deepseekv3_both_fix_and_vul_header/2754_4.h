#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

struct device {
    // minimal device structure
    int dummy;
};

struct sock {
    // minimal sock structure
    int dummy;
    struct {
        char src[6];  // Bluetooth address (6 bytes)
        char dst[6];  // Bluetooth address (6 bytes)
    };
};

struct hid_ll_driver {
    // minimal required fields
    int dummy;
};

struct hid_device {
    void *driver_data;
    int bus;
    unsigned short vendor;
    unsigned short product;
    unsigned short version;
    unsigned char country;
    char name[128];
    char phys[64];
    char uniq[64];
    struct {
        struct device *parent;
    } dev;
    struct hid_ll_driver *ll_driver;
    int (*hid_get_raw_report)(struct hid_device *, unsigned char, unsigned char *, size_t, unsigned char);
    int (*hid_output_raw_report)(struct hid_device *, unsigned char *, size_t, unsigned char);
};

struct hidp_session {
    void *rd_data;
    size_t rd_size;
    struct hid_device *hid;
    struct {
        struct sock *sk;
    } *ctrl_sock;
    struct {
        struct device dev;
    } *conn;
};

struct hidp_connadd_req {
    size_t rd_size;
    void *rd_data;
    unsigned short vendor;
    unsigned short product;
    unsigned short version;
    unsigned char country;
    char name[128];
};

struct hid_ll_driver hidp_hid_driver;

#define GFP_KERNEL 0
#define BUS_BLUETOOTH 0x05

static inline int IS_ERR(const void *ptr) { return 0; }
static inline int PTR_ERR(const void *ptr) { return 0; }

void *kzalloc(size_t size, int flags);
void kfree(const void *objp);
int copy_from_user(void *to, const void *from, unsigned long n);
struct hid_device *hid_allocate_device(void);
int hid_ignore(struct hid_device *hid);
void hid_destroy_device(struct hid_device *hid);
struct sock *bt_sk(struct sock *sk);
int hidp_get_raw_report(struct hid_device *hid, unsigned char report_number, unsigned char *buffer, size_t size, unsigned char report_type);
int hidp_output_raw_report(struct hid_device *hid, unsigned char *data, size_t count, unsigned char report_type);