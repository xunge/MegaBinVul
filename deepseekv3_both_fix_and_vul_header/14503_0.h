#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_MovieBox GF_MovieBox;
typedef struct GF_List GF_List;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_TrafToSampleMap GF_TrafToSampleMap;
typedef struct GF_FragmentStart GF_FragmentStart;

struct GF_ISOFile {
    GF_MovieBox *moov;
};

struct GF_MovieBox {
    GF_List *trackList;
};

struct GF_TrackBox {
    GF_MediaBox *Media;
};

struct GF_MediaBox {
    GF_MediaInformationBox *information;
};

struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
};

struct GF_SampleTableBox {
    GF_TrafToSampleMap *traf_map;
};

struct GF_TrafToSampleMap {
    u32 nb_entries;
    GF_FragmentStart *frag_starts;
};

struct GF_FragmentStart {
    u64 mdat_end;
};