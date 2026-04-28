#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef int32_t GF_Err;
typedef int32_t Bool;

#define GF_EXPORT
#define GF_BAD_PARAM 1
#define GF_ISOM_INVALID_FILE 2
#define GF_OK 0
#define GF_4CC(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))
#define GF_ISOM_BOX_TYPE_URL 0x75726c20
#define GF_ISOM_BOX_TYPE_URN 0x75726e20

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_ItemInfos {
    void* item_infos;
} GF_ItemInfos;

typedef struct GF_ItemLocations {
    void* location_entries;
} GF_ItemLocations;

typedef struct GF_Protections {
    void* protection_information;
} GF_Protections;

typedef struct GF_DataReference {
    void* child_boxes;
} GF_DataReference;

typedef struct GF_FileLocations {
    GF_DataReference* dref;
} GF_FileLocations;

typedef struct GF_MetaBox {
    GF_ItemInfos* item_infos;
    GF_ItemLocations* item_locations;
    GF_Protections* protections;
    GF_FileLocations* file_locations;
} GF_MetaBox;

typedef struct GF_ItemInfoEntryBox {
    u32 item_ID;
    const char* item_name;
    const char* content_type;
    const char* content_encoding;
    u32 item_type;
    u32 item_protection_index;
} GF_ItemInfoEntryBox;

typedef struct GF_ProtectionSchemeInfoBox {
    struct {
        u32 scheme_type;
        u32 scheme_version;
    }* scheme_type;
} GF_ProtectionSchemeInfoBox;

typedef struct GF_ItemLocationEntry {
    u32 item_ID;
    u32 data_reference_index;
    u32 base_offset;
    void* extent_entries;
} GF_ItemLocationEntry;

typedef struct GF_Box {
    u32 type;
} GF_Box;

typedef struct GF_DataEntryURLBox {
    const char* location;
} GF_DataEntryURLBox;

typedef struct GF_DataEntryURNBox {
    const char* location;
    const char* nameURN;
} GF_DataEntryURNBox;

typedef struct GF_ItemExtentEntry {
    u32 extent_length;
    u32 original_extent_offset;
} GF_ItemExtentEntry;

GF_MetaBox* gf_isom_get_meta(GF_ISOFile* file, Bool root_meta, u32 track_num);
void* gf_list_get(void* list, u32 index);
u32 gf_list_count(void* list);