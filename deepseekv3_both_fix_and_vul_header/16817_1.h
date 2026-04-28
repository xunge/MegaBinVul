#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_FALSE 0
#define GF_TRUE 1

#define GF_ISOM_CENC_SCHEME 0
#define GF_ISOM_CBC_SCHEME 0
#define GF_ISOM_CENS_SCHEME 0
#define GF_ISOM_CBCS_SCHEME 0
#define GF_ISOM_PIFF_SCHEME 0
#define GF_ISOM_BOX_TYPE_SINF 0
#define GF_ISOM_BOX_TYPE_SENC 0
#define GF_ISOM_BOX_UUID_PSEC 0
#define GF_ISOM_SAMPLE_GROUP_SEIG 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_LOG_WARNING 0
#define GF_LOG_CONTAINER 0

typedef struct GF_List GF_List;
typedef struct GF_MovieBox GF_MovieBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_SampleEntryBox GF_SampleEntryBox;
typedef struct GF_ProtectionSchemeInfoBox GF_ProtectionSchemeInfoBox;
typedef struct GF_SampleGroupDescriptionBox GF_SampleGroupDescriptionBox;
typedef struct GF_CENCSampleEncryptionGroupEntry GF_CENCSampleEncryptionGroupEntry;
typedef struct GF_UUIDBox GF_UUIDBox;
typedef struct GF_TrackBox GF_TrackBox;

struct GF_TrackBox {
    GF_MediaBox *Media;
    GF_MovieBox *moov;
    struct {
        u32 type;
    } *sample_encryption;
};

struct GF_MediaBox {
    GF_MediaInformationBox *information;
};

struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
};

struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
    GF_List *sampleGroupsDescription;
};

struct GF_SampleDescriptionBox {
    GF_List *child_boxes;
};

struct GF_SampleEntryBox {
    GF_List *child_boxes;
};

struct GF_ProtectionSchemeInfoBox {
    struct {
        struct {
            Bool isProtected;
            u8 crypt_byte_block;
            u8 skip_byte_block;
            const u8 *key_info;
        } *tenc;
        struct {
            const u8 *key_info;
        } *piff_tenc;
    } *info;
};

struct GF_SampleGroupDescriptionBox {
    u32 grouping_type;
    u32 default_description_index;
    GF_List *group_descriptions;
};

struct GF_CENCSampleEncryptionGroupEntry {
    Bool IsProtected;
    u8 crypt_byte_block;
    u8 skip_byte_block;
    const u8 *key_info;
    u32 key_info_size;
};

struct GF_UUIDBox {
    u32 internal_4cc;
};

struct GF_MovieBox {
    struct {
        Bool is_smooth;
    } *mov;
};

void GF_LOG(int level, int category, const char *message);
GF_List *gf_list_new();
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
GF_ProtectionSchemeInfoBox *isom_get_sinf_entry(GF_TrackBox *trak, u32 sampleDescriptionIndex, u32 scheme, void *ptr);
void *gf_isom_box_find_child(GF_List *child_boxes, u32 box_type);