#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_BAD_PARAM 1
#define GF_ISOM_INVALID_FILE 2
#define GF_OK 0
#define GF_NOT_SUPPORTED 3

#define GF_ISOM_BOX_TYPE_URL 0x75726C20
#define GF_QT_BOX_TYPE_ALIS 0x616C6973
#define GF_ISOM_BOX_TYPE_URN 0x75726E20

#define GF_ISOM_OPEN_WRITE 1
#define GF_ISOM_DATA_MAP_READ 1

typedef struct GF_DataMap GF_DataMap;
typedef struct GF_DataEntryURLBox GF_DataEntryURLBox;
typedef struct GF_MediaBox GF_MediaBox;

struct GF_DataEntryURLBox {
    u32 type;
    u32 flags;
    char *location;
};

struct GF_MediaBox {
    struct {
        struct {
            struct {
                struct {
                    void *child_boxes;
                } *dref;
            } *dataInformation;
        } *information;
    };
    struct {
        struct {
            struct {
                char *fileName;
                u32 openMode;
            } *mov;
        } *moov;
    } *mediaTrack;
};

extern GF_Err gf_isom_datamap_new(char *location, char *fileName, u32 mode, GF_DataMap **map);
extern void gf_isom_datamap_del(GF_DataMap *map);
extern void *gf_list_get(void *list, u32 index);
extern u32 gf_list_count(void *list);