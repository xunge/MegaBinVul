#include <stdint.h>
#include <stddef.h>

typedef struct {
    int version;
    int from_version;
} Bit_Chain;

typedef struct {
    struct {
        int dwg_version;
    } header;
    struct {
        void *LTYPE_BYBLOCK;
        void *LTYPE_BYLAYER;
    } header_vars;
    int num_objects;
    void *object;
} Dwg_Data;

typedef struct {
    int fixedtype;
    int type;
    struct {
        struct {
            union {
                void *VPORT_CONTROL;
                void *LTYPE_CONTROL;
                void *LAYER_CONTROL;
                void *STYLE_CONTROL;
                void *VIEW_CONTROL;
                void *UCS_CONTROL;
                void *APPID_CONTROL;
                void *DIMSTYLE_CONTROL;
                void *VX_CONTROL;
                void *BLOCK_CONTROL;
            } tio;
        } *object;
    } tio;
} Dwg_Object;

typedef struct {
    unsigned int num_entries;
    void **entries;
} Dwg_Object_VPORT_CONTROL, Dwg_Object_LTYPE_CONTROL, 
  Dwg_Object_LAYER_CONTROL, Dwg_Object_STYLE_CONTROL,
  Dwg_Object_VIEW_CONTROL, Dwg_Object_UCS_CONTROL,
  Dwg_Object_APPID_CONTROL, Dwg_Object_DIMSTYLE_CONTROL,
  Dwg_Object_VX_CONTROL, Dwg_Object_BLOCK_CONTROL;

typedef struct {
    void *ref;
} Dwg_Object_Ref;

#define DWG_TYPE_VPORT_CONTROL 0
#define DWG_TYPE_VPORT 0
#define DWG_TYPE_LTYPE_CONTROL 0
#define DWG_TYPE_LTYPE 0
#define DWG_TYPE_LAYER_CONTROL 0
#define DWG_TYPE_LAYER 0
#define DWG_TYPE_STYLE_CONTROL 0
#define DWG_TYPE_STYLE 0
#define DWG_TYPE_VIEW_CONTROL 0
#define DWG_TYPE_VIEW 0
#define DWG_TYPE_UCS_CONTROL 0
#define DWG_TYPE_UCS 0
#define DWG_TYPE_APPID_CONTROL 0
#define DWG_TYPE_APPID 0
#define DWG_TYPE_DIMSTYLE_CONTROL 0
#define DWG_TYPE_DIMSTYLE 0
#define DWG_TYPE_VX_CONTROL 0
#define DWG_TYPE_VX_TABLE_RECORD 0
#define DWG_TYPE_BLOCK_CONTROL 0
#define DWG_TYPE_BLOCK_HEADER 0
#define DWG_SUPERTYPE_OBJECT 0

#define R_9c1 0
#define R_10c1 0
#define R_12 0
#define R_2000 0
#define R_2018 0

#define SECTION(x)
#define SINCE(x)
#define TABLE(x)
#define COMMON_TABLE_CONTROL_FLAGS
#define ENDTAB()
#define ENDSEC()
#define VALUE_TV(x, y)
#define VALUE_RS(x, y)
#define RECORD(x)
#define LOG_ERROR(x)

#define DWG_ERR_INVALIDDWG 0