#include <stdint.h>
#include <assert.h>

#define MPTSAS_MAX_REQUEST_SIZE 1024

typedef uint64_t hwaddr;

typedef struct PCIDevice {
    // Placeholder for PCI device structure
} PCIDevice;

typedef struct MPTSASState {
    int state;
    hwaddr host_mfa_high_addr;
    // Other necessary fields
} MPTSASState;

typedef struct MPIRequestHeader {
    uint8_t Function;
    // Other necessary fields
} MPIRequestHeader;

typedef struct MPIMsgSCSIIORequest {
    // Placeholder for SCSI IO request structure
} MPIMsgSCSIIORequest;

enum {
    MPI_IOC_STATE_OPERATIONAL = 1,
    MPI_IOCSTATUS_INVALID_STATE = 2,
    MPI_FUNCTION_SCSI_IO_REQUEST = 0
};

enum {
    request_post
};

static const int mpi_request_sizes[] = {
    [MPI_FUNCTION_SCSI_IO_REQUEST] = sizeof(MPIMsgSCSIIORequest),
    // Add other function sizes as needed
};

void mptsas_set_fault(MPTSASState *s, int status);
void mptsas_process_scsi_io_request(MPTSASState *s, MPIMsgSCSIIORequest *req, hwaddr addr);
void mptsas_process_message(MPTSASState *s, MPIRequestHeader *hdr);
void pci_dma_read(PCIDevice *pci, hwaddr addr, void *buf, int len);
uint32_t MPTSAS_FIFO_GET(MPTSASState *s, int fifo);