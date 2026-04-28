#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef bool gboolean;
typedef uint32_t guint;

typedef struct tvbuff tvbuff_t;
typedef struct _packet_info {
    void *cinfo;
    int num;
    struct {
        void *src;
        void *dst;
        void *dl_src;
        void *dl_dst;
    };
} packet_info;

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;

typedef struct _address {
    void *addr1;
    void *addr2;
} address;

typedef struct _conversation_key {
    address *addr1;
    address *addr2;
} conversation_key;

typedef struct _conversation {
    conversation_key *key_ptr;
} conversation_t;

typedef struct _wmem_strbuf_t wmem_strbuf_t;
typedef struct _wmem_list_frame_t wmem_list_frame_t;

typedef struct {
    guint32 moduleIdentNr;
    guint32 subModuleIdentNr;
    guint16 slotNr;
    guint16 subSlotNr;
    guint16 length;
    guint16 f_crc_len;
    guint16 f_dest_adr;
    guint8 last_sb_cb;
    guint8 lastToggleBit;
    gboolean profisafeSupported;
    gboolean discardIOXS;
    guint8 amountInGSDML;
    char *moduleNameStr;
    guint16 frameOffset;
} ioDataObject;

typedef struct {
    guint16 slotNr;
    guint16 subSlotNr;
    guint16 frameOffset;
} iocsObject;

typedef struct {
    guint32 modulID;
} moduleDiffInfo;

typedef struct {
    guint16 ioDataObjectNr;
    guint16 iocsNr;
    char *typeofstation;
    char *nameofstation;
    gboolean gsdPathLength;
    gboolean gsdFound;
    char *gsdLocation;
    void *ioobject_data_in;
    void *ioobject_data_out;
    void *iocs_data_in;
    void *iocs_data_out;
    void *diff_module;
} stationInfo;

#define COL_PROTOCOL 0
#define COL_INFO 1
#define PT_NONE 0
#define ENC_NA 0

#define F_MESSAGE_TRAILER_4BYTE 4
#define FALSE false
#define TRUE true
#define _U_ __attribute__((unused))

extern int proto_pn_io_rtc1;
extern int ett_pn_io_rtc;
extern int hf_pn_io_packedframe_SFCRC;
extern int hf_pn_io_frame_info_type;
extern int hf_pn_io_frame_info_vendor;
extern int hf_pn_io_frame_info_nameofstation;
extern int hf_pn_io_frame_info_gsd_found;
extern int hf_pn_io_frame_info_gsd_error;
extern int hf_pn_io_frame_info_gsd_path;
extern int hf_pn_io_io_data_object;
extern int hf_pn_io_io_data_object_info_module_diff;
extern int hf_pn_io_io_data_object_info_moduleidentnumber;
extern int hf_pn_io_io_data_object_info_submoduleidentnumber;
extern int hf_pn_io_ps_f_dest_adr;
extern int hf_pn_io_ps_f_data;
extern int hf_pn_io_ps_sb_toggelBitChanged;
extern int hf_pn_io_ps_sb_toggelBitChange_slot_nr;
extern int hf_pn_io_ps_sb_toggelBitChange_subslot_nr;
extern int hf_pn_io_ps_sb;
extern int hf_pn_io_iops;
extern int hf_pn_io_iocs;
extern int hf_pn_io_ps_cb_toggelBitChanged;
extern int hf_pn_io_ps_cb_toggelBitChange_slot_nr;
extern int hf_pn_io_ps_cb_toggelBitChange_subslot_nr;
extern int hf_pn_io_ps_cb;
extern int ett_pn_io_io_data_object;

extern gboolean pnio_ps_selection;
extern int proto_pn_dcp;

extern const char *ps_sb_fields;
extern const char *ps_cb_fields;
extern const char *ioxs_fields;

extern void *ei_pn_io_too_many_data_objects;

void col_set_str(void *cinfo, int col, const char *str);
void col_append_str(void *cinfo, int col, const char *str);
proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int len, const char *format, ...);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
int dissect_CSF_SDU_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);
conversation_t *find_conversation(int num, void *src, void *dst, int type, int port1, int port2, int options);
void *conversation_get_proto_data(conversation_t *conv, int proto);
int addresses_equal(void *addr1, void *addr2);
proto_item *proto_tree_add_string_format_value(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, const char *value, const char *format, ...);
proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, int encoding);
void proto_item_append_text(proto_item *item, const char *format, ...);
wmem_list_frame_t *wmem_list_head(void *list);
wmem_list_frame_t *wmem_list_frame_next(wmem_list_frame_t *frame);
void *wmem_list_frame_data(wmem_list_frame_t *frame);
void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, guint32 value);
int dissect_pn_io_ps_uint(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf, int length, guint64 *value);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
proto_item *proto_tree_add_uint_format_value(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...);
void PROTO_ITEM_SET_HIDDEN(proto_item *item);
int dissect_pn_io_ps_SB(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf, const char *fields);
int dissect_pn_user_data(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int length, const char *label);
int dissect_PNIO_IOxS(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf, const char *fields);
void proto_item_set_len(proto_item *item, int length);
wmem_strbuf_t *wmem_strbuf_new(void *scope, const char *str);
void *wmem_packet_scope(void);
void wmem_strbuf_append(wmem_strbuf_t *buf, const char *str);
char *wmem_strdup(void *scope, const char *str);
void *wmem_file_scope(void);
const char *wmem_strbuf_get_str(wmem_strbuf_t *buf);
int dissect_PNIO_IOCS(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf, guint16 slot, guint16 subslot, const char *fields);
int tvb_captured_length(tvbuff_t *tvb);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
int dissect_pn_io_ps_CB(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf, const char *fields);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
void expert_add_info_format(packet_info *pinfo, proto_item *item, void *ei, const char *format, ...);