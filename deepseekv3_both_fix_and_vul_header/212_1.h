#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef int GF_Err;
#define GF_OK 0
#define GF_BAD_PARAM 1

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_SampleEntryBox GF_SampleEntryBox;
typedef struct GF_ProtectionSchemeInfoBox GF_ProtectionSchemeInfoBox;
typedef struct GF_OriginalFormatBox GF_OriginalFormatBox;

struct GF_ProtectionSchemeInfoBox {
    GF_OriginalFormatBox *original_format;
};

struct GF_OriginalFormatBox {
    u32 data_format;
};

struct GF_SampleEntryBox {
    void *protections;
};

struct GF_TrackBox {
    void *Media;
};

#define GF_EXPORT
#define gf_isom_get_track_from_file(the_file, trackNumber) NULL
#define Media_GetSampleDesc(media, index, entry, out_info) (0)
#define gf_list_get(list, index) NULL