#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <endian.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef int gboolean;
typedef char gchar;

#define FALSE 0
#define TRUE 1
#define MAX_NAMELENGTH 256
#define MAX_LINE_LENGTH 1024
#define G_DIR_SEPARATOR_S "/"
#define PT_NONE 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

typedef struct DIR GDir;
struct GDir {
    DIR* dir;
};

typedef struct _stationInfo {
    gboolean gsdFound;
    gboolean gsdPathLength;
    guint16 u16Vendor_id;
    guint16 u16Device_id;
    gchar *gsdLocation;
} stationInfo;

typedef struct _ioDataObject {
    gboolean profisafeSupported;
    gchar *moduleNameStr;
    guint16 slotNr;
    guint16 subSlotNr;
    guint32 moduleIdentNr;
    guint32 subModuleIdentNr;
    gboolean discardIOXS;
    guint32 amountInGSDML;
    guint32 fParameterIndexNr;
} ioDataObject;

typedef struct _conversation {
    // conversation structure members
} conversation_t;

typedef struct _proto_item proto_item;
typedef struct _proto_tree proto_tree;
typedef struct _packet_info {
    guint32 num;
    void *dl_src;
    void *dl_dst;
} packet_info;
typedef struct _tvbuff tvbuff_t;

extern guint8 pnio_ps_networkpath[MAX_LINE_LENGTH];
extern int hf_pn_io_number_of_apis;
extern int hf_pn_io_api_tree;
extern int hf_pn_io_api;
extern int hf_pn_io_slot_nr;
extern int hf_pn_io_module_ident_number;
extern int hf_pn_io_module_properties;
extern int hf_pn_io_number_of_submodules;
extern int hf_pn_io_submodule_tree;
extern int hf_pn_io_subslot_nr;
extern int hf_pn_io_submodule_ident_number;
extern int hf_pn_io_submodule_properties;
extern int hf_pn_io_submodule_properties_reserved;
extern int hf_pn_io_submodule_properties_discard_ioxs;
extern int hf_pn_io_submodule_properties_reduce_output_submodule_data_length;
extern int hf_pn_io_submodule_properties_reduce_input_submodule_data_length;
extern int hf_pn_io_submodule_properties_shared_input;
extern int hf_pn_io_submodule_properties_type;
extern int ett_pn_io_api;
extern int ett_pn_io_submodule;
extern int ett_pn_io_submodule_properties;
extern int proto_pn_dcp;
extern int ei_pn_io_block_version;

extern void *wmem_alloc(void *scope, size_t size);
extern void *wmem_new0(void *scope, size_t size);
extern char *wmem_strdup(void *scope, const char *str);
extern char *wmem_strdup_printf(void *scope, const char *format, ...);
extern void *wmem_packet_scope(void);
extern void *wmem_file_scope(void);

extern conversation_t *find_conversation(guint32 num, void *src, void *dst, int ptype, guint32 port1, guint32 port2, guint32 options);
extern conversation_t *conversation_new(guint32 num, void *src, void *dst, int ptype, guint32 port1, guint32 port2, guint32 options);
extern void *conversation_get_proto_data(conversation_t *conv, int proto);

extern int dissect_dcerpc_uint16(void *tvb, int offset, void *pinfo, void *tree, guint8 *drep, int hfindex, guint16 *value);
extern int dissect_dcerpc_uint32(void *tvb, int offset, void *pinfo, void *tree, guint8 *drep, int hfindex, guint32 *value);
extern int dissect_DataDescription(void *tvb, int offset, void *pinfo, void *tree, guint8 *drep, ioDataObject *io_data_object);

extern void expert_add_info_format(void *pinfo, void *item, int *expert_info, const char *format, ...);
extern void proto_item_append_text(void *item, const char *format, ...);
extern void proto_item_set_len(void *item, int length);
extern void *proto_tree_add_item(void *tree, int hfindex, void *tvb, int offset, int length, int encoding);
extern void *proto_item_add_subtree(void *item, int ettindex);

extern FILE *ws_fopen(const char *path, const char *mode);
extern GDir *g_dir_open(const char *path, guint flags, void *error);
extern const gchar *g_dir_read_name(GDir *dir);
extern void g_dir_close(GDir *dir);

// Add forward declaration for wmem_new0() with correct type
extern void *wmem_new0(void *scope, size_t size);
#define wmem_new0(scope, type) ((type *)wmem_new0(scope, sizeof(type)))