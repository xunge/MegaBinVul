#include <stdint.h>
#include <string.h>

#define BAD_APICID 0xFFFFFFFF
#define MSI_DATA_VECTOR_MASK 0x000000FF
#define MSI_ADDR_DEST_ID_MASK 0x000FF000

#define MSI_DATA_VECTOR(x) ((x) & 0xFF)
#define MSI_ADDR_DEST_ID(x) (((x) & 0xFF) << 12)

#define ASSERT(x) do { if (!(x)) __builtin_unreachable(); } while (0)

struct msi_msg {
    uint32_t address_lo;
    uint32_t address_hi;
    uint32_t data;
    uint32_t dest32;
};

struct msi_desc {
    struct msi_msg msg;
};

struct irq_desc {
    struct msi_desc *msi_desc;
    struct {
        unsigned int vector;
    } arch;
    int lock;
};

typedef struct cpumask_t cpumask_t;

static inline int spin_is_locked(int *lock) { return *lock != 0; }

unsigned int set_desc_affinity(struct irq_desc *desc, const cpumask_t *mask);
void write_msi_msg(struct msi_desc *msi_desc, struct msi_msg *msg);
int read_msi_msg(struct msi_desc *msi_desc, struct msi_msg *msg);