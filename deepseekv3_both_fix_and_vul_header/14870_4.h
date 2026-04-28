#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdint.h>

#define SNDRV_DMA_TYPE_DEV 1
#define EINVAL 22
#define EFAULT 14
#define KERN_ERR "<3>"
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef long ssize_t;
typedef size_t size_t;
typedef uint64_t dma_addr_t;

struct file;
struct pci_dev;

struct snd_dma_buffer {
    void *area;
    dma_addr_t addr;
    size_t bytes;
    void *private_data;
};

#define __user

int printk(const char *fmt, ...);
char *gettoken(char **);
long simple_strtol(const char *, char **, int);
unsigned long memparse(const char *, char **);
int copy_from_user(void *, const void *, unsigned long);
int pci_set_dma_mask(struct pci_dev *, unsigned long);
int pci_set_consistent_dma_mask(struct pci_dev *, unsigned long);
struct pci_dev *pci_get_device(unsigned int, unsigned int, struct pci_dev *);
void pci_dev_put(struct pci_dev *);
int snd_dma_alloc_pages(int, void *, size_t, struct snd_dma_buffer *);
void snd_dma_reserve_buf(struct snd_dma_buffer *, unsigned int);
void *snd_dma_pci_data(struct pci_dev *);
unsigned int snd_dma_pci_buf_id(struct pci_dev *);
void free_all_reserved_pages(void);