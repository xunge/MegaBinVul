#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned char byte;

typedef struct gs_param_string_s {
    const byte *data;
    unsigned int size;
} gs_param_string;

typedef struct gs_param_string_array_s {
    gs_param_string *data;
    unsigned int size;
} gs_param_string_array;

typedef struct gs_memory_s {
    // Placeholder for memory management structure
} gs_memory_t;

typedef struct cos_dict_s {
    // Placeholder for COS dictionary structure
} cos_dict_t;

typedef struct rc_struct_s {
    // Placeholder for reference counting structure
} rc_struct;

typedef struct gx_device_s {
    // Base device structure
} gx_device;

typedef struct gx_device_pdf_s {
    gx_device *dev;
    float CompatibilityLevel;
    struct {
        bool LockDistillerParams;
        int ColorConversionStrategy;
        int TransferFunctionInfo;
        bool ConvertCMYKImagesToRGB;
        struct {
            const char *Filter;
        } ColorImage, GrayImage, MonoImage;
    } params;
    gs_memory_t *memory;
    gs_memory_t *pdf_memory;
    bool ForOPDFRead;
    bool is_ps2write;
    bool is_open;
    int PDFA;
    bool AbortPDFAX;
    bool PDFX;
    bool HaveTransparency;
    bool PreserveSMask;
    bool ResourcesBeforeUsage;
    bool HaveCFF;
    bool HavePDFWidths;
    bool HaveStrokeColor;
    bool HaveTrueTypes;
    bool Linearise;
    bool FlattenFonts;
    bool PreserveTrMode;
    long FirstObjectNumber;
    long next_id;
    struct {
        FILE *file;
    } xref;
    int PageCount;
    gs_param_string OwnerPassword;
    cos_dict_t *Catalog;
    int version;
    int pcm_color_info_index;
    int saved_fill_color;
    int saved_stroke_color;
    long MaxInlineImageSize;
    bool ProduceDSC;
    float ParamCompatibilityLevel;
    rc_struct *icc_struct;
} gx_device_pdf;

typedef struct gs_param_list_s {
    gs_memory_t *memory;
} gs_param_list;

typedef char *gs_param_name;

typedef struct gs_param_item_s {
    const char *key;
    unsigned int type;
    unsigned int offset;
} gs_param_item_t;

enum {
    tfi_Preserve = 0,
    tfi_Apply = 1
};

enum {
    ccs_ByObjectType = 0,
    ccs_LeaveColorUnchanged = 1,
    ccs_UseDeviceDependentColor = 2,
    ccs_UseDeviceIndependentColor = 3,
    ccs_UseDeviceIndependentColorForImages = 4,
    ccs_CMYK = 5,
    ccs_Gray = 6,
    ccs_sRGB = 7,
    ccs_RGB = 8
};

enum {
    psdf_version_level2 = 0,
    psdf_version_level2_with_TT = 1,
    psdf_version_ll3 = 2
};

#define max_long LONG_MAX
#define CoreDistVersion 0
#define pdf_num_initial_ids 100

extern int gs_error_rangecheck;
extern int gs_error_ioerror;
extern gs_param_item_t pdf_param_items[];
extern const unsigned int gs_param_type_sizes[];

/* Function prototypes */
static gs_memory_t *gs_memory_stable(gs_memory_t *mem);
static int param_read_string_array(gs_param_list *plist, gs_param_name param_name, gs_param_string_array *ppa);
static int pdfwrite_pdf_open_document(gx_device_pdf *pdev);
static int pdfmark_process(gx_device_pdf *pdev, gs_param_string_array *ppa);
static void param_signal_error(gs_param_list *plist, gs_param_name param_name, int code);
static int pdf_dsc_process(gx_device_pdf *pdev, gs_param_string_array *ppa);
static int param_read_string(gs_param_list *plist, gs_param_name param_name, gs_param_string *pps);
static int cos_dict_put_string(cos_dict_t *pcd, const byte *key, int key_len, const byte *value, unsigned int value_size);
static int param_read_bool(gs_param_list *plist, gs_param_name param_name, bool *pvalue);
static int param_put_int(gs_param_list *plist, gs_param_name param_name, int *pvalue, int ecode);
static int gs_note_error(int code);
static int param_read_float(gs_param_list *plist, gs_param_name param_name, float *pvalue);
static int gs_param_read_items(gs_param_list *plist, gx_device_pdf *pdev, gs_param_item_t *items);
static int param_put_enum(gs_param_list *plist, gs_param_name param_name, int *pvalue, const char *const *enum_names, int ecode);
static void pdf_set_process_color_model(gx_device_pdf *pdev, int pcm);
static void rc_decrement(rc_struct *p, const char *cname);
static int gdev_psdf_put_params(gx_device *dev, gs_param_list *plist);
static void emprintf(gs_memory_t *mem, const char *fmt, ...);
static int gsicc_init_device_profile_struct(gx_device *dev, void *icc_manager, int flags);
static int gp_fseek_64(FILE *file, long offset, int whence);
static void pdf_initialize_ids(gx_device_pdf *pdev);
static void gs_closedevice(gx_device *dev);