#include <stdint.h>
#include <stdlib.h>

#define MAX_CPU 32
#define OPENPIC_OUTPUT_NB 32
#define OPENPIC_GLB_REG_START 0
#define OPENPIC_GLB_REG_SIZE 0
#define OPENPIC_TMR_REG_START 0
#define OPENPIC_TMR_REG_SIZE 0
#define OPENPIC_SRC_REG_START 0
#define OPENPIC_SRC_REG_SIZE 0
#define OPENPIC_CPU_REG_START 0
#define OPENPIC_CPU_REG_SIZE 0
#define OPENPIC_MSI_REG_START 0
#define OPENPIC_MSI_REG_SIZE 0
#define OPENPIC_SUMMARY_REG_START 0
#define OPENPIC_SUMMARY_REG_SIZE 0
#define RAVEN_MAX_EXT 0
#define RAVEN_MAX_IRQ 0
#define RAVEN_IPI_IRQ 0
#define RAVEN_TMR_IRQ 0
#define GCR_MODE_MIXED 0
#define GCR_MODE_PROXY 0
#define IVPR_MASK_MASK 0
#define IVPR_MODE_MASK 0
#define VID_REVISION_1_3 0
#define VIR_GENERIC 0
#define OPENPIC_FLAG_IDR_CRIT (1 << 0)
#define OPENPIC_FLAG_ILR (1 << 1)
#define TYPE_OPENPIC "openpic"
#define QERR_PROPERTY_VALUE_OUT_OF_RANGE 0

typedef struct Error Error;
typedef struct DeviceState DeviceState;
typedef struct SysBusDevice SysBusDevice;
typedef int qemu_irq;

typedef enum {
    OPENPIC_MODEL_FSL_MPIC_20,
    OPENPIC_MODEL_FSL_MPIC_42,
    OPENPIC_MODEL_RAVEN
} OpenPICModel;

typedef struct MemReg {
    const char *name;
    const void *ops;
    uint32_t start;
    uint32_t size;
} MemReg;

typedef struct FSLMPIC {
    const void *ops;
} FSLMPIC;

typedef struct OpenPICState {
    OpenPICModel model;
    int nb_cpus;
    int nb_irqs;
    int max_irq;
    int irq_ipi0;
    int irq_tim0;
    uint32_t brr1;
    uint32_t flags;
    uint32_t vector_mask;
    uint32_t tfrr_reset;
    uint32_t ivpr_reset;
    uint32_t idr_reset;
    uint32_t mpic_mode_mask;
    uint32_t vid;
    uint32_t vir;
    const FSLMPIC *fsl;
    struct {
        qemu_irq *irqs;
    } dst[MAX_CPU];
    void *mem;
} OpenPICState;

extern const FSLMPIC fsl_mpic_20;
extern const FSLMPIC fsl_mpic_42;
extern const void openpic_glb_ops_le;
extern const void openpic_tmr_ops_le;
extern const void openpic_src_ops_le;
extern const void openpic_cpu_ops_le;
extern const void openpic_glb_ops_be;
extern const void openpic_tmr_ops_be;
extern const void openpic_src_ops_be;
extern const void openpic_cpu_ops_be;
extern const void openpic_msi_ops_be;
extern const void openpic_summary_ops_be;

#define SYS_BUS_DEVICE(obj) ((SysBusDevice *)obj)
#define OPENPIC(obj) ((OpenPICState *)obj)

void error_set(Error **errp, int err_class, const char *fmt, ...);
void error_setg(Error **errp, const char *fmt, ...);
void *g_new(size_t size, size_t count);
void sysbus_init_irq(SysBusDevice *dev, qemu_irq *irq);
void sysbus_init_mmio(SysBusDevice *dev, void *mem);
void qdev_init_gpio_in(DeviceState *dev, void (*handler)(void *, int, int), int n);
void register_savevm(DeviceState *dev, const char *id, int instance_id,
                    int version_id,
                    void (*save)(void *, void *),
                    int (*load)(void *, void *, int),
                    void *opaque);
void openpic_save(void *opaque, void *file);
int openpic_load(void *opaque, void *file, int version_id);
void openpic_set_irq(void *opaque, int n, int level);
void fsl_common_init(OpenPICState *opp);
void map_list(OpenPICState *opp, const MemReg *list, int *count);

#define g_new(type, count) ((type *)g_new(sizeof(type), (count)))