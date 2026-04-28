#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

typedef unsigned long ulong;

typedef struct bootm_headers {
    struct {
        uint8_t arch;
    } os;
    int verify;
    char *fit_uname_cfg;
} bootm_headers_t;

enum fit_load_op {
    FIT_LOAD_IGNORED,
    FIT_LOAD_OPTIONAL_NON_ZERO,
    FIT_LOAD_REQUIRED
};

enum ih_comp {
    IH_COMP_NONE,
    IH_COMP_GZIP,
    IH_COMP_BZIP2,
    IH_COMP_LZMA,
    IH_COMP_LZO,
    IH_COMP_LZ4,
    IH_COMP_ZSTD
};

enum ih_os {
    IH_OS_INVALID,
    IH_OS_OPENBSD,
    IH_OS_NETBSD,
    IH_OS_FREEBSD,
    IH_OS_4_4BSD,
    IH_OS_LINUX,
    IH_OS_SVR4,
    IH_OS_ESIX,
    IH_OS_SOLARIS,
    IH_OS_IRIX,
    IH_OS_SCO,
    IH_OS_DELL,
    IH_OS_NCR,
    IH_OS_LYNXOS,
    IH_OS_VXWORKS,
    IH_OS_PSOS,
    IH_OS_QNX,
    IH_OS_U_BOOT,
    IH_OS_RTEMS,
    IH_OS_ARTOS,
    IH_OS_UNITY,
    IH_OS_INTEGRITY,
    IH_OS_OSE,
    IH_OS_PLAN9,
    IH_OS_OPENRTOS,
    IH_OS_ARM_TRUSTED_FIRMWARE,
    IH_OS_TEE,
    IH_OS_OPENSBI,
    IH_OS_EFI,
    IH_OS_COUNT
};

enum ih_type {
    IH_TYPE_INVALID,
    IH_TYPE_STANDALONE,
    IH_TYPE_KERNEL,
    IH_TYPE_RAMDISK,
    IH_TYPE_MULTI,
    IH_TYPE_FIRMWARE,
    IH_TYPE_SCRIPT,
    IH_TYPE_FILESYSTEM,
    IH_TYPE_FLATDT,
    IH_TYPE_KWBIMAGE,
    IH_TYPE_IMXIMAGE,
    IH_TYPE_UBLIMAGE,
    IH_TYPE_OMAPIMAGE,
    IH_TYPE_AISIMAGE,
    IH_TYPE_KERNEL_NOLOAD,
    IH_TYPE_PBLIMAGE,
    IH_TYPE_MXSIMAGE,
    IH_TYPE_GPIMAGE,
    IH_TYPE_ATMELIMAGE,
    IH_TYPE_SOCFPGAIMAGE,
    IH_TYPE_X86_SETUP,
    IH_TYPE_LPC32XXIMAGE,
    IH_TYPE_LOADABLE,
    IH_TYPE_RKIMAGE,
    IH_TYPE_RKSD,
    IH_TYPE_RKSPI,
    IH_TYPE_ZYNQIMAGE,
    IH_TYPE_ZYNQMPIMAGE,
    IH_TYPE_ZYNQMPBIF,
    IH_TYPE_FPGA,
    IH_TYPE_VYBRIDIMAGE,
    IH_TYPE_TEE,
    IH_TYPE_FIRMWARE_IVT,
    IH_TYPE_PMMC,
    IH_TYPE_STM32IMAGE,
    IH_TYPE_SOCFPGAIMAGE_V1,
    IH_TYPE_MTKIMAGE,
    IH_TYPE_IMX8MIMAGE,
    IH_TYPE_IMX8IMAGE,
    IH_TYPE_COPRO,
    IH_TYPE_SUNXI_EGON,
    IH_TYPE_SUNXI_TOC0,
    IH_TYPE_COUNT
};

#define IMAGE_SIZE_INVAL (-1)
#define IMAGE_ENABLE_BEST_MATCH 1
#define FIT_IMAGE_ENABLE_VERIFY 1
#define IMAGE_ENABLE_DECRYPT 1
#define CONFIG_IS_ENABLED(option) 1
#define CONFIG_FIT_CIPHER 1
#define CONFIG_FIT_IMAGE_POST_PROCESS 1
#define CONFIG_SANDBOX 1
#define USE_HOSTCC 0
#define BOOTSTAGE_SUB_FORMAT 0
#define BOOTSTAGE_SUB_FORMAT_OK 1
#define BOOTSTAGE_SUB_UNIT_NAME 2
#define BOOTSTAGE_SUB_NO_UNIT_NAME 3
#define BOOTSTAGE_SUB_HASH 4
#define BOOTSTAGE_SUB_GET_DATA 5
#define BOOTSTAGE_SUB_GET_DATA_OK 6
#define BOOTSTAGE_SUB_LOAD 7
#define BOOTSTAGE_SUB_CHECK_ARCH 8
#define BOOTSTAGE_SUB_CHECK_ALL 9
#define BOOTSTAGE_SUB_CHECK_ALL_OK 10
#define BOOTSTAGE_SUB_SUBNODE 11
#define BOOTSTAGE_ID_FIT_CONFIG 12

extern const void *gd_fdt_blob(void);
extern void *map_sysmem(ulong addr, int len);
extern ulong map_to_sysmem(void *ptr);
extern int fit_check_format(const void *fit, int size);
extern int fit_image_get_node(const void *fit, const char *image_uname);
extern int fit_conf_find_compat(const void *fit, const void *fdt_blob);
extern int fit_conf_get_node(const void *fit, const char *conf_uname);
extern const char *fit_get_image_type_property(int type);
extern int fit_image_select(const void *fit, int noffset, int verify);
extern int fit_image_check_target_arch(const void *fit, int noffset);
extern void fit_image_get_arch(const void *fit, int noffset, uint8_t *arch);
extern int fit_image_check_type(const void *fit, int noffset, int type);
extern int fit_image_check_os(const void *fit, int noffset, int os);
extern void fit_image_get_os(const void *fit, int noffset, uint8_t *os);
extern int fit_image_get_data_and_size(const void *fit, int noffset, const void **data, size_t *size);
extern int fit_image_get_load(const void *fit, int noffset, ulong *load);
extern int fit_image_get_comp(const void *fit, int noffset, uint8_t *comp);
extern int fit_image_uncipher(const void *fit, int noffset, void **data, size_t *size);
extern int fit_config_verify(const void *fit, int noffset);
extern int fit_conf_get_prop_node(const void *fit, int noffset, const char *prop_name);
extern const char *fit_get_name(const void *fit, int noffset, int *len);
extern ulong fit_get_size(const void *fit);
extern int image_decomp(uint8_t comp, ulong load, ulong image_start, int type, void *load_buf, void *image_buf, ulong image_len, ulong unc_len, ulong *load_end);
extern const char *genimg_get_os_name(uint8_t os);
extern const char *genimg_get_arch_name(int arch);
extern const char *genimg_get_type_name(int type);
extern int host_build(void);
extern void board_fit_image_post_process(void **p_image, size_t *p_size);
extern void bootstage_mark(int id);
extern void bootstage_error(int id);
extern int fdt_check_header(const void *fdt);
extern char *fdt_get_name(const void *fdt, int nodeoffset, int *len);