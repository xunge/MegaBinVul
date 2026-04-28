#include <stdint.h>
#include <string.h>

#define SISFB_ID 0x53495346
#define VER_MAJOR 1
#define VER_MINOR 0
#define VER_LEVEL 0
#define CAP_SYS_RAWIO 0
#define EPERM 1
#define EFAULT 14
#define ENOIOCTLCMD 515
#define EINVAL 22
#define KERN_INFO ""
#define __user

#define FBIO_ALLOC 0x4610
#define FBIO_FREE 0x4611
#define FBIOGET_VBLANK 0x4612
#define SISFB_GET_INFO_SIZE 0x8004f300
#define SISFB_GET_INFO_OLD 0x8004f301
#define SISFB_GET_INFO 0x8004f302
#define SISFB_GET_VBRSTATUS_OLD 0x8004f303
#define SISFB_GET_VBRSTATUS 0x8004f304
#define SISFB_GET_AUTOMAXIMIZE_OLD 0x8004f305
#define SISFB_GET_AUTOMAXIMIZE 0x8004f306
#define SISFB_SET_AUTOMAXIMIZE_OLD 0x8004f307
#define SISFB_SET_AUTOMAXIMIZE 0x8004f308
#define SISFB_SET_TVPOSOFFSET 0x8004f309
#define SISFB_GET_TVPOSOFFSET 0x8004f30A
#define SISFB_COMMAND 0x8004f30B
#define SISFB_SET_LOCK 0x8004f30C

typedef uint32_t u32;
typedef uint16_t u16;

struct fb_info {
    void *par;
};

struct fb_vblank {
    u32 count;
    u32 flags;
    u32 vcount;
    u32 hcount;
};

struct sisfb_info {
    u32 sisfb_id;
    u32 sisfb_version;
    u32 sisfb_revision;
    u32 sisfb_patchlevel;
    u32 chip_id;
    u32 sisfb_pci_vendor;
    u32 memory;
    u32 heapstart;
    u32 fbvidmode;
    u32 sisfb_caps;
    u32 sisfb_tqlen;
    u32 sisfb_pcibus;
    u32 sisfb_pcislot;
    u32 sisfb_pcifunc;
    u32 sisfb_lcdpdc;
    u32 sisfb_lcdpdca;
    u32 sisfb_lcda;
    u32 sisfb_vbflags;
    u32 sisfb_currentvbflags;
    u32 sisfb_scalelcd;
    u32 sisfb_specialtiming;
    u32 sisfb_haveemi;
    u32 sisfb_haveemilcd;
    u32 sisfb_emi30;
    u32 sisfb_emi31;
    u32 sisfb_emi32;
    u32 sisfb_emi33;
    u16 sisfb_tvxpos;
    u16 sisfb_tvypos;
    u32 sisfb_heapsize;
    u32 sisfb_videooffset;
    u32 sisfb_curfstn;
    u32 sisfb_curdstn;
    u32 sisfb_vbflags2;
    u32 sisfb_can_post;
    u32 sisfb_card_posted;
    u32 sisfb_was_boot_device;
};

struct sisfb_cmd {
    u32 cmd;
    u32 data;
};

struct sis_memreq {
    u32 offset;
    u32 size;
};

struct sis_video_info {
    void *par;
    struct sisfb_info sisfb_infoblock;
    struct sisfb_cmd sisfb_command;
    u32 chip_id;
    u32 chip_vendor;
    u32 video_size;
    u32 heapstart;
    int modechanged;
    int mode_no;
    int modeprechange;
    u32 caps;
    u32 cmdQueueSize;
    u32 pcibus;
    u32 pcislot;
    u32 pcifunc;
    u32 detectedpdc;
    u32 detectedpdca;
    u32 detectedlcda;
    u32 vbflags;
    u32 currentvbflags;
    u32 vbflags2;
    int sisfb_max;
    int sisfblocked;
    int sisfb_can_post;
    int sisfb_card_posted;
    int sisfb_was_boot_device;
    u32 sisfb_heap_size;
    u32 video_offset;
    int curFSTN;
    int curDSTN;
    int tvxpos;
    int tvypos;
    int warncount;
    struct {
        int UsePanelScaler;
        int SiS_CustomT;
        int HaveEMI;
        int HaveEMILCD;
        int EMI_30;
        int EMI_31;
        int EMI_32;
        int EMI_33;
    } SiS_Pr;
};

static int capable(int cap) { return 0; }
static int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static int get_user(u32 *val, u32 *addr) { return 0; }
static int put_user(u32 val, u32 *addr) { return 0; }
static void printk(const char *fmt, ...) {}
static void sis_malloc(struct sis_memreq *req) {}
static void sis_free(u32 offset) {}
static int sisfb_setupvbblankflags(struct sis_video_info *ivideo, u32 *vcount, u32 *hcount) { return 0; }
static int sisfb_CheckVBRetrace(struct sis_video_info *ivideo) { return 0; }
static void sisfb_set_TVxposoffset(struct sis_video_info *ivideo, int offset) {}
static void sisfb_set_TVyposoffset(struct sis_video_info *ivideo, int offset) {}
static void sisfb_handle_command(struct sis_video_info *ivideo, struct sisfb_cmd *cmd) {}