#include <stdint.h>
#include <stdbool.h>

#define PAGE_SHIFT 12
#define DMA_32BIT_MASK 0xFFFFFFFF
#define IOMMU_CONTROL_ENABLED 1

#define IOMMU_PTE_PRESENT_MASK 0x1
#define IOMMU_PTE_PRESENT_SHIFT 0
#define IOMMU_PTE_ADDR_HIGH_MASK 0xFFFFFFFF
#define IOMMU_PTE_ADDR_HIGH_SHIFT 0
#define IOMMU_PTE_ADDR_LOW_MASK 0xFFFFF000
#define IOMMU_PTE_ADDR_LOW_SHIFT 0
#define IOMMU_PDE_NEXT_LEVEL_MASK 0x7
#define IOMMU_PDE_NEXT_LEVEL_SHIFT 9
#define IOMMU_PTE_IO_WRITE_PERMISSION_MASK 0x1
#define IOMMU_PTE_IO_WRITE_PERMISSION_SHIFT 0
#define IOMMU_PTE_IO_READ_PERMISSION_MASK 0x1
#define IOMMU_PTE_IO_READ_PERMISSION_SHIFT 1
#define IOMMU_PDE_ADDR_HIGH_MASK 0xFFFFFFFF
#define IOMMU_PDE_ADDR_HIGH_SHIFT 0
#define IOMMU_PDE_IO_WRITE_PERMISSION_MASK 0x1
#define IOMMU_PDE_IO_WRITE_PERMISSION_SHIFT 0
#define IOMMU_PDE_IO_READ_PERMISSION_MASK 0x1
#define IOMMU_PDE_IO_READ_PERMISSION_SHIFT 1
#define IOMMU_PTE_FC_MASK 0x1
#define IOMMU_PTE_FC_SHIFT 0
#define IOMMU_PDE_ADDR_LOW_MASK 0xFFFFF000
#define IOMMU_PDE_ADDR_LOW_SHIFT 0
#define IOMMU_PDE_PRESENT_MASK 0x1
#define IOMMU_PDE_PRESENT_SHIFT 0

typedef bool bool_t;
typedef uint32_t u32;
typedef uint64_t u64;

static inline u32 get_field_from_reg_u32(u32 reg, u32 mask, u32 shift) {
    return (reg & mask) >> shift;
}

static inline void set_field_in_reg_u32(u32 val, u32 old, u32 mask, u32 shift, u32 *new) {
    *new = (old & ~(mask << shift)) | ((val & mask) << shift);
}