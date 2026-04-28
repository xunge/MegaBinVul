#include <stdio.h>

typedef unsigned int u32;
typedef unsigned long long u64;
typedef int GF_Err;
typedef double Double;
typedef long long s64;

#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_NON_COMPLIANT_BITSTREAM 2

#define GPAC_DISABLE_BIFS
#define GPAC_DISABLE_LASER

#define GF_ISOM_MEDIA_SCENE 1
#define GF_ISOM_MEDIA_OD 2
#define GF_ISOM_SUBTYPE_MP4S 3
#define GF_CODECID_TEXT_MPEG4 4
#define GF_CODECID_AFX 5
#define GF_CODECID_SYNTHESIZED_TEXTURE 6
#define GF_STREAM_SCENE 7
#define RAP 1

typedef enum {
    GF_ISOM_EDIT_NORMAL,
    GF_ISOM_EDIT_DURATION,
    GF_ISOM_EDIT_EMPTY
} GF_ISOEditType;

typedef struct {
    u32 ESID;
    u32 streamType;
    u32 objectTypeIndication;
    u32 timeScale;
    u32 codec_id;
} GF_StreamContext;

typedef struct {
    u32 DTS;
    u32 IsRAP;
    char *data;
    u32 dataLength;
} GF_ISOSample;

typedef struct {
    void *commands;
} GF_AUContext;

typedef struct {
    u32 objectTypeIndication;
    u32 streamType;
    void *decoderSpecificInfo;
} GF_DecoderConfig;

typedef struct {
    u32 ESID;
    GF_DecoderConfig *decoderConfig;
    u32 dependsOnESID;
} GF_ESD;

typedef struct {
    void *commands;
} GF_ODCom;

typedef struct {
    void *ctx;
    void *isom;
    void *scene_graph;
} GF_SceneLoader;

typedef struct {
    void *data;
    u32 dataLength;
} GF_Descriptor;

typedef struct {
    void *isom;
} GF_ODCodec;

typedef struct {
    void *scene_graph;
} GF_BifsDecoder;

typedef struct {
    void *scene_graph;
} GF_LASeRCodec;

void gf_odf_desc_del(GF_Descriptor *desc);
GF_Err gf_bifs_decoder_configure_stream(GF_BifsDecoder *bifs_dec, u32 ESID, void *data, u32 dataLength, u32 objectTypeIndication);
GF_Err gf_laser_decoder_configure_stream(GF_LASeRCodec *lsr_dec, u32 ESID, void *data, u32 dataLength);
GF_Err gf_bifs_decode_command_list(GF_BifsDecoder *bifs_dec, u32 ESID, void *data, u32 dataLength, void *commands);
GF_Err gf_laser_decode_command_list(GF_LASeRCodec *lsr_dec, u32 ESID, void *data, u32 dataLength, void *commands);
GF_Err gf_odf_codec_set_au(GF_ODCodec *od_dec, void *data, u32 dataLength);
GF_Err gf_odf_codec_decode(GF_ODCodec *od_dec);
GF_ODCom *gf_odf_codec_get_com(GF_ODCodec *od_dec);
void gf_list_add(void *list, void *item);
void gf_isom_sample_del(GF_ISOSample **samp);
u32 gf_isom_get_track_count(void *isom);
u32 gf_isom_get_media_type(void *isom, u32 track);
u32 gf_isom_get_mpeg4_subtype(void *isom, u32 track, u32 sample);
u32 gf_isom_get_sample_count(void *isom, u32 track);
GF_ESD *gf_isom_get_esd(void *isom, u32 track, u32 sample);
u32 gf_isom_get_media_timescale(void *isom, u32 track);
u32 gf_isom_get_track_id(void *isom, u32 track);
u32 gf_isom_get_edits_count(void *isom, u32 track);
void gf_isom_get_edit(void *isom, u32 track, u32 edit, u64 *EditTime, u64 *dur, u64 *mtime, GF_ISOEditType *mode);
u32 gf_isom_get_timescale(void *isom);
GF_ISOSample *gf_isom_get_sample(void *isom, u32 track, u32 sample, u32 *di);
GF_Err gf_isom_last_error(void *isom);
void gf_isom_text_set_streaming_mode(void *isom, u32 mode);
GF_StreamContext *gf_sm_stream_new(void *ctx, u32 ESID, u32 streamType, u32 objectTypeIndication);
GF_AUContext *gf_sm_stream_au_new(GF_StreamContext *sc, u32 DTS, Double time, u32 isRAP);
void gf_set_progress(const char *msg, u32 done, u32 total);
void mp4_report(GF_SceneLoader *load, GF_Err e, const char *msg, ...);
GF_BifsDecoder *gf_bifs_decoder_new(void *scene_graph, u32 flag);
GF_LASeRCodec *gf_laser_decoder_new(void *scene_graph);
GF_ODCodec *gf_odf_codec_new();
void gf_bifs_decoder_del(GF_BifsDecoder *bifs_dec);
void gf_laser_decoder_del(GF_LASeRCodec *lsr_dec);
void gf_odf_codec_del(GF_ODCodec *od_dec);
void gf_fclose(FILE *file);
void UpdateODCommand(void *isom, GF_ODCom *odc);