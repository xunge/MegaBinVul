#include <stdlib.h>
#include <stdarg.h>

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_MovieBox GF_MovieBox;
typedef struct GF_MovieFragmentBox GF_MovieFragmentBox;
typedef struct GF_List GF_List;
typedef struct GF_TrackFragmentBox GF_TrackFragmentBox;
typedef struct GF_TrackBox GF_TrackBox;

struct GF_TrackFragmentHeaderBox {
    unsigned int trackID;
};

struct GF_TrackHeaderBox {
    unsigned int trackID;
};

struct GF_TrackFragmentBox {
    struct GF_TrackFragmentHeaderBox *tfhd;
};

struct GF_TrackBox {
    struct GF_TrackHeaderBox *Header;
};

struct GF_MovieBox {
    GF_List *trackList;
};

struct GF_MovieFragmentBox {
    GF_List *TrackList;
};

struct GF_ISOFile {
    GF_MovieBox *moov;
    GF_MovieFragmentBox *moof;
};

enum GF_LogLevel {
    GF_LOG_WARNING,
    GF_LOG_CONTAINER
};

void GF_LOG(enum GF_LogLevel level, enum GF_LogLevel module, const char *format, ...);
unsigned int gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, unsigned int position);