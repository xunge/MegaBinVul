#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define DNP3_CTL_FUNC 0x0F
#define DNP3_CTL_PRM 0x40
#define DNP3_CTL_DIR 0x80
#define DNP3_CTL_FCB 0x20
#define DNP3_CTL_FCV 0x10
#define DNP3_CTL_RES 0x08
#define DNP3_CTL_DFC 0x08

#define DNP3_TR_SEQ 0x3F
#define DNP3_TR_FIR 0x40
#define DNP3_TR_FIN 0x80

#define DL_FUNC_LINK_STAT 0x0B
#define DL_FUNC_STAT_LINK 0x0B
#define DL_FUNC_RESET_LINK 0x0F
#define DL_FUNC_ACK 0x00

#define AL_MAX_CHUNK_SIZE 16
#define DNP_HDR_LEN 10

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ENC_LITTLE_ENDIAN 2
#define PROTO_CHECKSUM_VERIFY 1
#define FALSE 0
#define TRUE 1

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef int gboolean;
typedef char gchar;
typedef int gint;

typedef struct {
    void* cinfo;
    void* pool;
    int fragmented;
    struct {
        int visited;
    } *fd;
    int num;
    int curr_layer_num;
} packet_info;

typedef struct tvbuff {
    unsigned char* data;
    int length;
} tvbuff_t;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct fragment_head {
    int reassembled_in;
    int reas_in_layer_num;
} fragment_head;

typedef struct {
    int* hf_al_frag_data;
} fragment_items;

static int proto_dnp3;
static int hf_dnp3_start;
static int hf_dnp3_len;
static int hf_dnp3_ctl;
static int hf_dnp3_ctl_dir;
static int hf_dnp3_ctl_prm;
static int hf_dnp3_ctl_fcb;
static int hf_dnp3_ctl_fcv;
static int hf_dnp3_ctl_prifunc;
static int hf_dnp3_ctl_dfc;
static int hf_dnp3_ctl_secfunc;
static int hf_dnp3_dst;
static int hf_dnp3_src;
static int hf_dnp3_addr;
static int hf_dnp3_data_hdr_crc;
static int hf_dnp3_data_hdr_crc_status;
static int hf_dnp3_tr_ctl;
static int hf_dnp3_tr_fin;
static int hf_dnp3_tr_fir;
static int hf_dnp3_tr_seq;
static int hf_dnp3_data_chunk;
static int hf_dnp3_data_chunk_len;
static int hf_dnp3_data_chunk_crc;
static int hf_dnp3_data_chunk_crc_status;
static int hf_al_frag_data;
static int ei_dnp3_data_hdr_crc_incorrect;
static int ei_dnp3_data_chunk_crc_incorrect;

static int ett_dnp3;
static int ett_dnp3_dl;
static int ett_dnp3_dl_ctl;
static int ett_dnp3_tr_ctl;
static int ett_dnp3_dl_data;
static int ett_dnp3_dl_chunk;

static fragment_items dnp3_frag_items;
static fragment_head al_reassembly_table;

static const struct {
    int value;
    const char* str;
} dnp3_ctl_func_pri_vals[] = {
    {0x00, "Reset Link"},
    {0x01, "Test Link"},
    {0x02, "Confirmed User Data"},
    {0x03, "Unconfirmed User Data"},
    {0x04, "Request Link Status"},
    {0x09, "Not Used"},
    {0x0B, "Request Link Status"},
    {0x0F, "Reset Link"},
    {0, NULL}
};

static const struct {
    int value;
    const char* str;
} dnp3_ctl_func_sec_vals[] = {
    {0x00, "ACK"},
    {0x01, "NACK"},
    {0x0B, "Status of Link"},
    {0x0F, "Service Not Supported"},
    {0, NULL}
};

#define _U_ __attribute__((unused))