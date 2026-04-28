#include <stdbool.h>
#include <stddef.h>

#define ENOENT 2
#define EBUSY 16
#define EDEADLOCK 35

#define WARN_ON(condition) (condition)
#define READ_ONCE(x) (x)

struct rw_semaphore {
    // Minimal stub implementation
};

struct io_pagetable {
    struct rw_semaphore domains_rwsem;
    struct rw_semaphore iova_rwsem;
};

struct iopt_area {
    struct iopt_pages *pages;
    unsigned long num_accesses;
    bool prevent_access;
    // Other members omitted
};

struct iopt_pages {
    // Minimal stub implementation
};

void down_read(struct rw_semaphore *sem);
void down_write(struct rw_semaphore *sem);
void up_read(struct rw_semaphore *sem);
void up_write(struct rw_semaphore *sem);

struct iopt_area *iopt_area_iter_first(struct io_pagetable *iopt, unsigned long start, unsigned long last);
unsigned long iopt_area_last_iova(struct iopt_area *area);
unsigned long iopt_area_iova(struct iopt_area *area);
unsigned long iopt_area_length(struct iopt_area *area);
void iopt_area_unfill_domains(struct iopt_area *area, struct iopt_pages *pages);
void iopt_abort_area(struct iopt_area *area);
void iopt_put_pages(struct iopt_pages *pages);
void iommufd_access_notify_unmap(struct io_pagetable *iopt, unsigned long start, unsigned long length);