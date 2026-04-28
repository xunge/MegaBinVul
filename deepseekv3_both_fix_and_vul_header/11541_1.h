struct mm_struct {
    unsigned long vmacache_seqnum;
};

extern void vmacache_flush_all(struct mm_struct *mm);

#define unlikely(x) __builtin_expect(!!(x), 0)