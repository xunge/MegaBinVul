#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t GF_Err;

#define GF_ODF_IOD_TAG 1
#define GF_ODF_ESD_TAG 2
#define GF_ODF_DCD_TAG 3
#define GF_ODF_SLC_TAG 4
#define GF_ODF_OD_TAG 5
#define GF_ODF_ISOM_IOD_TAG 6
#define GF_ODF_ISOM_OD_TAG 7
#define GF_ODF_ESD_INC_TAG 8
#define GF_ODF_ESD_REF_TAG 9
#define GF_ODF_SEGMENT_TAG 10
#define GF_ODF_MUXINFO_TAG 11
#define GF_ODF_AUX_VIDEO_DATA 12
#define GF_ODF_LANG_TAG 13
#define GF_ODF_GPAC_LANG 14
#define GF_ODF_MEDIATIME_TAG 15
#define GF_ODF_IPMP_TAG 16
#define GF_ODF_IPMP_PTR_TAG 17
#define GF_ODF_CC_TAG 18
#define GF_ODF_CC_DATE_TAG 19
#define GF_ODF_CC_NAME_TAG 20
#define GF_ODF_CI_TAG 21
#define GF_ODF_TEXT_TAG 22
#define GF_ODF_EXT_PL_TAG 23
#define GF_ODF_IPI_PTR_TAG 24
#define GF_ODF_ISOM_IPI_PTR_TAG 25
#define GF_ODF_KW_TAG 26
#define GF_ODF_OCI_DATE_TAG 27
#define GF_ODF_OCI_NAME_TAG 28
#define GF_ODF_PL_IDX_TAG 29
#define GF_ODF_QOS_TAG 30
#define GF_ODF_RATING_TAG 31
#define GF_ODF_REG_TAG 32
#define GF_ODF_SHORT_TEXT_TAG 33
#define GF_ODF_SMPTE_TAG 34
#define GF_ODF_SCI_TAG 35
#define GF_ODF_IPMP_TL_TAG 36
#define GF_ODF_IPMP_TOOL_TAG 37
#define GF_ODF_DSI_TAG 38

#define GF_NON_COMPLIANT_BITSTREAM 0
#define GF_OK 0
#define GF_LOG_ERROR 0
#define GF_LOG_CODING 0

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_Descriptor {
    int tag;
} GF_Descriptor;

typedef struct GF_InitialObjectDescriptor GF_InitialObjectDescriptor;
typedef struct GF_ESD GF_ESD;
typedef struct GF_DecoderConfig GF_DecoderConfig;
typedef struct GF_SLConfig GF_SLConfig;
typedef struct GF_ObjectDescriptor GF_ObjectDescriptor;
typedef struct GF_IsomInitialObjectDescriptor GF_IsomInitialObjectDescriptor;
typedef struct GF_IsomObjectDescriptor GF_IsomObjectDescriptor;
typedef struct GF_ES_ID_Inc GF_ES_ID_Inc;
typedef struct GF_ES_ID_Ref GF_ES_ID_Ref;
typedef struct GF_Segment GF_Segment;
typedef struct GF_AuxVideoDescriptor GF_AuxVideoDescriptor;
typedef struct GF_Language GF_Language;
typedef struct GF_MediaTime GF_MediaTime;
typedef struct GF_IPMP_Descriptor GF_IPMP_Descriptor;
typedef struct GF_IPMPPtr GF_IPMPPtr;
typedef struct GF_CCDescriptor GF_CCDescriptor;
typedef struct GF_CC_Date GF_CC_Date;
typedef struct GF_CC_Name GF_CC_Name;
typedef struct GF_CIDesc GF_CIDesc;
typedef struct GF_ExpandedTextual GF_ExpandedTextual;
typedef struct GF_PLExt GF_PLExt;
typedef struct GF_IPIPtr GF_IPIPtr;
typedef struct GF_KeyWord GF_KeyWord;
typedef struct GF_OCI_Data GF_OCI_Data;
typedef struct GF_OCICreators GF_OCICreators;
typedef struct GF_PL_IDX GF_PL_IDX;
typedef struct GF_QoS_Descriptor GF_QoS_Descriptor;
typedef struct GF_Rating GF_Rating;
typedef struct GF_Registration GF_Registration;
typedef struct GF_ShortTextual GF_ShortTextual;
typedef struct GF_SMPTECamera GF_SMPTECamera;
typedef struct GF_SCIDesc GF_SCIDesc;
typedef struct GF_IPMP_ToolList GF_IPMP_ToolList;
typedef struct GF_IPMP_Tool GF_IPMP_Tool;
typedef struct GF_DefaultDescriptor GF_DefaultDescriptor;

u64 gf_bs_get_cookie(GF_BitStream *bs);
void gf_bs_set_cookie(GF_BitStream *bs, u64 cookie);
void GF_LOG(int level, int category, const char* message);
GF_Err gf_odf_read_descriptor_internal(GF_BitStream *bs, GF_Descriptor *desc, u32 DescSize);
GF_Err gf_odf_read_iod(GF_BitStream *bs, GF_InitialObjectDescriptor *desc, u32 DescSize);
GF_Err gf_odf_read_esd(GF_BitStream *bs, GF_ESD *desc, u32 DescSize);
GF_Err gf_odf_read_dcd(GF_BitStream *bs, GF_DecoderConfig *desc, u32 DescSize);
GF_Err gf_odf_read_slc(GF_BitStream *bs, GF_SLConfig *desc, u32 DescSize);
GF_Err gf_odf_read_od(GF_BitStream *bs, GF_ObjectDescriptor *desc, u32 DescSize);
GF_Err gf_odf_read_isom_iod(GF_BitStream *bs, GF_IsomInitialObjectDescriptor *desc, u32 DescSize);
GF_Err gf_odf_read_isom_od(GF_BitStream *bs, GF_IsomObjectDescriptor *desc, u32 DescSize);
GF_Err gf_odf_read_esd_inc(GF_BitStream *bs, GF_ES_ID_Inc *desc, u32 DescSize);
GF_Err gf_odf_read_esd_ref(GF_BitStream *bs, GF_ES_ID_Ref *desc, u32 DescSize);
GF_Err gf_odf_read_segment(GF_BitStream *bs, GF_Segment *desc, u32 DescSize);
GF_Err gf_odf_read_auxvid(GF_BitStream *bs, GF_AuxVideoDescriptor *desc, u32 DescSize);
GF_Err gf_odf_read_lang(GF_BitStream *bs, GF_Language *desc, u32 DescSize);
GF_Err gf_odf_read_mediatime(GF_BitStream *bs, GF_MediaTime *desc, u32 DescSize);
GF_Err gf_odf_read_ipmp(GF_BitStream *bs, GF_IPMP_Descriptor *desc, u32 DescSize);
GF_Err gf_odf_read_ipmp_ptr(GF_BitStream *bs, GF_IPMPPtr *desc, u32 DescSize);
GF_Err gf_odf_read_cc(GF_BitStream *bs, GF_CCDescriptor *desc, u32 DescSize);
GF_Err gf_odf_read_cc_date(GF_BitStream *bs, GF_CC_Date *desc, u32 DescSize);
GF_Err gf_odf_read_cc_name(GF_BitStream *bs, GF_CC_Name *desc, u32 DescSize);
GF_Err gf_odf_read_ci(GF_BitStream *bs, GF_CIDesc *desc, u32 DescSize);
GF_Err gf_odf_read_exp_text(GF_BitStream *bs, GF_ExpandedTextual *desc, u32 DescSize);
GF_Err gf_odf_read_pl_ext(GF_BitStream *bs, GF_PLExt *desc, u32 DescSize);
GF_Err gf_odf_read_ipi_ptr(GF_BitStream *bs, GF_IPIPtr *desc, u32 DescSize);
GF_Err gf_odf_read_kw(GF_BitStream *bs, GF_KeyWord *desc, u32 DescSize);
GF_Err gf_odf_read_oci_date(GF_BitStream *bs, GF_OCI_Data *desc, u32 DescSize);
GF_Err gf_odf_read_oci_name(GF_BitStream *bs, GF_OCICreators *desc, u32 DescSize);
GF_Err gf_odf_read_pl_idx(GF_BitStream *bs, GF_PL_IDX *desc, u32 DescSize);
GF_Err gf_odf_read_qos(GF_BitStream *bs, GF_QoS_Descriptor *desc, u32 DescSize);
GF_Err gf_odf_read_rating(GF_BitStream *bs, GF_Rating *desc, u32 DescSize);
GF_Err gf_odf_read_reg(GF_BitStream *bs, GF_Registration *desc, u32 DescSize);
GF_Err gf_odf_read_short_text(GF_BitStream *bs, GF_ShortTextual *desc, u32 DescSize);
GF_Err gf_odf_read_smpte_camera(GF_BitStream *bs, GF_SMPTECamera *desc, u32 DescSize);
GF_Err gf_odf_read_sup_cid(GF_BitStream *bs, GF_SCIDesc *desc, u32 DescSize);
GF_Err gf_odf_read_ipmp_tool_list(GF_BitStream *bs, GF_IPMP_ToolList *desc, u32 DescSize);
GF_Err gf_odf_read_ipmp_tool(GF_BitStream *bs, GF_IPMP_Tool *desc, u32 DescSize);
GF_Err gf_odf_read_default(GF_BitStream *bs, GF_DefaultDescriptor *desc, u32 DescSize);