#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/uio.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define ENOTBLK 19
#define WRITE 1
#define READ 0
#define DIO_LOCKING 1
#define EIOCBQUEUED 1

typedef int (get_block_t)(void);
typedef void (dio_iodone_t)(void);

struct kiocb;
struct inode {
    unsigned long i_blkbits;
    void *i_mapping;
    void *i_mutex;
};
struct buffer_head {
    void *b_private;
    int b_state;
};

struct page;
struct bio;
struct task_struct;

typedef long sector_t;
typedef long loff_t;
typedef int spinlock_t;

struct dio {
    struct inode *inode;
    int rw;
    unsigned blkbits;
    int blkfactor;
    int start_zero_done;
    loff_t size;
    sector_t block_in_file;
    unsigned blocks_available;
    struct page *cur_page;
    unsigned boundary;
    int reap_counter;
    get_block_t *get_block;
    dio_iodone_t *end_io;
    struct buffer_head map_bh;
    sector_t final_block_in_bio;
    sector_t next_block_for_io;
    int page_errors;
    int io_error;
    ssize_t result;
    struct kiocb *iocb;
    loff_t i_size;
    spinlock_t bio_lock;
    int refcount;
    struct bio *bio_list;
    struct task_struct *waiter;
    unsigned long pages_in_io;
    unsigned long first_block_in_page;
    sector_t final_block_in_request;
    int head;
    int tail;
    int curr_page;
    int total_pages;
    unsigned long curr_user_address;
    int is_async;
    int lock_type;
    struct bio *bio;
};

static inline loff_t i_size_read(struct inode *inode) { return 0; }
static inline void spin_lock_init(spinlock_t *lock) {}
static inline int unlikely(int x) { return x; }
static inline void dio_cleanup(struct dio *dio) {}
static inline void dio_zero_block(struct dio *dio, int flag) {}
static inline ssize_t dio_send_cur_page(struct dio *dio) { return 0; }
static inline void page_cache_release(struct page *page) {}
static inline void dio_bio_submit(struct dio *dio) {}
static inline void blk_run_address_space(void *mapping) {}
static inline void mutex_unlock(void *mutex) {}
static inline void BUG_ON(int condition) {}
static inline void dio_await_completion(struct dio *dio) {}
static inline void spin_lock_irqsave(spinlock_t *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) {}
static inline ssize_t dio_complete(struct dio *dio, loff_t offset, ssize_t ret) { return ret; }
static inline void kfree(void *ptr) {}
static inline ssize_t do_direct_IO(struct dio *dio) { return 0; }