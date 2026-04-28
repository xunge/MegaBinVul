#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;

#define GF_EXPORT
#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1

#define GPAC_DISABLE_ISOM_WRITE
#define GPAC_DISABLE_ISOM_FRAGMENTS

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Box GF_Box;
typedef struct GF_MovieFragmentRandomAccessBox GF_MovieFragmentRandomAccessBox;
typedef struct GF_MovieFragmentRandomAccessOffsetBox GF_MovieFragmentRandomAccessOffsetBox;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_List GF_List;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_DataMap GF_DataMap;

struct GF_ISOFile {
    int openMode;
    u32 FragmentsFlags;
    GF_MovieFragmentRandomAccessBox *mfra;
    GF_DataMap *editFileMap;
    GF_DataMap *movieFileMap;
    struct {
        GF_List *trackList;
    } *moov;
};

struct GF_MovieFragmentRandomAccessBox {
    GF_MovieFragmentRandomAccessOffsetBox *mfro;
    u64 size;
};

struct GF_TrackBox {
    GF_MediaBox *Media;
};

struct GF_MediaBox {
    GF_MediaInformationBox *information;
};

struct GF_MediaInformationBox {
    GF_DataMap *scalableDataHandler;
};

GF_Err gf_isom_get_duration(GF_ISOFile *movie);
GF_Err gf_isom_close_fragments(GF_ISOFile *movie);
GF_Box *gf_isom_box_new(u32 box_type);
GF_Err gf_isom_box_size(GF_Box *box);
GF_Err gf_isom_box_write(GF_Box *box, GF_BitStream *bs);
GF_Err WriteToFile(GF_ISOFile *movie);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void gf_isom_datamap_del(GF_DataMap *ptr);

#define GF_ISOM_OPEN_READ 1
#define GF_ISOM_OPEN_WRITE 2
#define GF_ISOM_FRAG_WRITE_READY 1
#define GF_ISOM_BOX_TYPE_MFRO 0x6d66726f