#include <string.h>

#define BUG_ON(condition) do { if (condition) abort(); } while (0)

#define KVM_EXIT_MMIO 0

struct kvm_vcpu {
    struct kvm_run *run;
    int mmio_needed;
    struct kvm_mmio_fragment *mmio_fragments;
    int mmio_cur_fragment;
    int mmio_is_write;
    int mmio_nr_fragments;
    int mmio_read_completed;
    struct {
        void (*complete_userspace_io)(struct kvm_vcpu *);
    } arch;
};

struct kvm_run {
    int exit_reason;
    struct {
        unsigned long phys_addr;
        unsigned char data[8];
        unsigned int len;
        int is_write;
    } mmio;
};

struct kvm_mmio_fragment {
    unsigned char *data;
    unsigned long gpa;
    unsigned int len;
};

int complete_emulated_io(struct kvm_vcpu *vcpu);