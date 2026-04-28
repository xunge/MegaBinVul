#include <cstdint>
#include <cstddef>

class Process;
class MemoryRegion;

struct VirtualAddress {
    uintptr_t address;
};

class MemoryManager {
public:
    bool validate_user_write(const Process& process, VirtualAddress vaddr) const;
    MemoryRegion* user_region_from_vaddr(Process& process, VirtualAddress vaddr) const;
    MemoryRegion* region_from_vaddr(const Process& process, VirtualAddress vaddr) const;
};

class MemoryRegion {
public:
    bool is_user_accessible() const;
    bool is_writable() const;
};