#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t __u8;

struct timer_list {
    void (*function)(struct timer_list *);
    unsigned long data;
};

struct work_struct {
    void (*func)(struct work_struct *);
};

struct wait_queue_head {
    int dummy;
};

struct mutex {
    int dummy;
};

struct device {
    char bus_info[64];
};

struct usb_interface_descriptor {
    __u8 bInterfaceNumber;
};

struct usb_host_interface {
    struct usb_interface_descriptor desc;
};

struct usb_interface {
    struct usb_host_interface *cur_altsetting;
    struct device dev;
};

struct usb_device {
    int dummy;
};

struct usb_device_id {
    const void *driver_info;
};

struct v4l2_queryctrl {
    int id;
    unsigned int type;
    unsigned int flags;
    int minimum;
    int maximum;
    int default_value;
    char name[32];
};

struct pvr2_ctrl;

struct pvr2_ctl_info {
    const char *desc;
    const char *name;
    int v4l_id;
    int skip_init;
    int (*get_value)(struct pvr2_ctrl*, int*);
    unsigned int (*get_v4lflags)(struct pvr2_ctrl*);
    int (*is_dirty)(struct pvr2_ctrl*);
    void (*clear_dirty)(struct pvr2_ctrl*);
    int (*set_value)(struct pvr2_ctrl*, int);
    int default_value;
    int type;
    union {
        struct {
            int min_value;
            int max_value;
        } type_int;
        struct {
            const char **value_names;
            unsigned int count;
        } type_enum;
        struct {
            const char **bit_names;
            unsigned int valid_bits;
        } type_bitmask;
    } def;
};

struct pvr2_ctrl {
    struct pvr2_hdw *hdw;
    struct pvr2_ctl_info *info;
};

struct pvr2_device_desc {
    const char *description;
    int flag_is_experimental;
    int flag_has_analogtuner;
    int digital_control_scheme;
    int flag_has_svideo;
    int flag_has_composite;
    int flag_has_fmradio;
    int ir_scheme;
};

struct pvr2_hdw {
    struct timer_list quiescent_timer;
    struct timer_list decoder_stabilization_timer;
    struct timer_list encoder_wait_timer;
    struct timer_list encoder_run_timer;
    int master_state;
    struct wait_queue_head state_wait_data;
    int tuner_signal_stale;
    void *enc_ctl_state;
    unsigned int input_avail_mask;
    unsigned int input_allowed_mask;
    int pathway_state;
    unsigned int control_cnt;
    struct pvr2_ctrl *controls;
    const struct pvr2_device_desc *hdw_desc;
    int ir_scheme_active;
    char std_mask_names[32][32];
    const char *std_mask_ptrs[32];
    int input_val;
    struct {
        struct pvr2_ctl_info info;
        char desc[32];
    } *mpeg_ctrl_info;
    int cropcap_stale;
    int eeprom_addr;
    int unit_number;
    int v4l_minor_number_video;
    int v4l_minor_number_vbi;
    int v4l_minor_number_radio;
    void *ctl_write_buffer;
    void *ctl_read_buffer;
    void *ctl_write_urb;
    void *ctl_read_urb;
    void *v4l2_dev;
    struct work_struct workpoll;
    char name[32];
    int tuner_type;
    int flag_ok;
    struct usb_interface *usb_intf;
    struct usb_device *usb_dev;
    char bus_info[64];
    struct mutex ctl_lock_mutex;
    struct mutex big_lock_mutex;
    struct pvr2_ctl_info std_info_avail;
    struct pvr2_ctl_info std_info_cur;
    struct pvr2_ctl_info std_info_detect;
};

struct mpeg_ids {
    const char *strid;
    int id;
};

#define CTRLDEF_COUNT 32
struct pvr2_ctl_info control_defs[CTRLDEF_COUNT];

#define GFP_KERNEL 0
#define PVR2_TRACE_INIT 0
#define PVR2_TRACE_INFO 0
#define PVR2_TRACE_ERROR_LEGS 0
#define PVR2_CTL_BUFFSIZE 1024
#define PVR_NUM 8
#define MPEGDEF_COUNT 16
#define PVR2_CID_STDAVAIL 0
#define PVR2_CID_STDCUR 1
#define PVR2_CID_STDDETECT 2
#define PVR2_STATE_DEAD 0
#define PVR2_PATHWAY_ANALOG 0
#define PVR2_PATHWAY_DIGITAL 1
#define PVR2_DIGITAL_SCHEME_NONE 0
#define PVR2_CVAL_INPUT_TV 0
#define PVR2_CVAL_INPUT_DTV 1
#define PVR2_CVAL_INPUT_SVIDEO 2
#define PVR2_CVAL_INPUT_COMPOSITE 3
#define PVR2_CVAL_INPUT_RADIO 4
#define V4L2_CTRL_FLAG_READ_ONLY (1 << 0)
#define V4L2_CTRL_TYPE_INTEGER 1
#define V4L2_CTRL_TYPE_BOOLEAN 2
#define V4L2_CTRL_TYPE_MENU 3

enum pvr2_ctl_type {
    pvr2_ctl_int,
    pvr2_ctl_bool,
    pvr2_ctl_enum
};

extern struct mpeg_ids mpeg_ids[];
extern void pvr2_trace(int, const char*, ...);
extern void* kzalloc(size_t, int);
extern void* kcalloc(size_t, size_t, int);
extern void* kmalloc(size_t, int);
extern void kfree(void*);
extern void timer_setup(struct timer_list*, void (*)(struct timer_list*), int);
extern void del_timer_sync(struct timer_list*);
extern void INIT_WORK(struct work_struct*, void (*)(struct work_struct*));
extern void flush_work(struct work_struct*);
extern void mutex_init(struct mutex*);
extern void mutex_lock(struct mutex*);
extern void mutex_unlock(struct mutex*);
extern size_t scnprintf(char*, size_t, const char*, ...);
extern struct usb_device *interface_to_usbdev(struct usb_interface*);
extern void *usb_alloc_urb(int, int);
extern void usb_free_urb(void*);
extern int usb_set_interface(struct usb_device*, __u8, int);
extern void usb_make_path(struct usb_device*, char*, size_t);
extern int v4l2_device_register(void*, void*);
extern void init_waitqueue_head(struct wait_queue_head*);
extern void cx2341x_fill_defaults(void*);
extern int cx2341x_ctrl_query(void*, struct v4l2_queryctrl*);
extern const char **cx2341x_ctrl_get_menu(void*, int);
extern int ctrl_cx2341x_get(struct pvr2_ctrl*, int*);
extern unsigned int ctrl_cx2341x_getv4lflags(struct pvr2_ctrl*);
extern int ctrl_cx2341x_is_dirty(struct pvr2_ctrl*);
extern void ctrl_cx2341x_clear_dirty(struct pvr2_ctrl*);
extern int ctrl_cx2341x_set(struct pvr2_ctrl*, int);
extern int pvr2_std_get_usable(void);
extern int pvr2_std_id_to_str(char*, int, unsigned long);
extern struct pvr2_ctrl* pvr2_hdw_get_ctrl_by_id(struct pvr2_hdw*, int);
extern void pvr2_hdw_quiescent_timeout(struct timer_list*);
extern void pvr2_hdw_decoder_stabilization_timeout(struct timer_list*);
extern void pvr2_hdw_encoder_wait_timeout(struct timer_list*);
extern void pvr2_hdw_encoder_run_timeout(struct timer_list*);
extern void pvr2_hdw_worker_poll(struct work_struct*);

static struct mutex pvr2_unit_mtx;
static struct pvr2_hdw *unit_pointers[PVR_NUM];