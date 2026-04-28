#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint8_t ut8;

struct minidump_location_descriptor {
    uint32_t data_size;
    uint32_t rva;
};

struct minidump_memory_descriptor {
    uint64_t start_of_memory_range;
    struct minidump_location_descriptor memory;
};

struct minidump_memory_descriptor64 {
    uint64_t start_of_memory_range;
    uint64_t data_size;
};

struct minidump_thread {
    uint32_t thread_id;
    uint32_t suspend_count;
    uint32_t priority_class;
    uint32_t priority;
    uint64_t teb;
    struct minidump_memory_descriptor stack;
    struct minidump_location_descriptor thread_context;
};

struct minidump_thread_list {
    uint32_t number_of_threads;
    struct minidump_thread threads[0];
};

struct minidump_thread_ex {
    uint32_t thread_id;
    uint32_t suspend_count;
    uint32_t priority_class;
    uint32_t priority;
    uint64_t teb;
    struct minidump_memory_descriptor stack;
    struct minidump_location_descriptor thread_context;
    struct minidump_memory_descriptor backing_store;
};

struct minidump_thread_ex_list {
    uint32_t number_of_threads;
    struct minidump_thread_ex threads[0];
};

struct minidump_module {
    uint64_t base_of_image;
    uint32_t size_of_image;
    uint32_t checksum;
    uint32_t time_date_stamp;
    uint32_t module_name_rva;
    // ... other fields
};

struct minidump_module_list {
    uint32_t number_of_modules;
    struct minidump_module modules[0];
};

struct minidump_memory_list {
    uint32_t number_of_memory_ranges;
    struct minidump_memory_descriptor memory_ranges[0];
};

struct minidump_memory64_list {
    uint64_t number_of_memory_ranges;
    uint64_t base_rva;
    struct minidump_memory_descriptor64 memory_ranges[0];
};

struct minidump_unloaded_module {
    uint64_t base_of_image;
    uint32_t size_of_image;
    uint32_t checksum;
    uint32_t time_date_stamp;
    uint32_t module_name_rva;
};

struct minidump_unloaded_module_list {
    uint32_t size_of_header;
    uint32_t size_of_entry;
    uint32_t number_of_entries;
    struct minidump_unloaded_module entries[0];
};

struct minidump_memory_info {
    uint64_t base_address;
    uint64_t allocation_base;
    uint32_t allocation_protect;
    uint32_t __alignment1;
    uint64_t region_size;
    uint32_t state;
    uint32_t protect;
    uint32_t type;
    uint32_t __alignment2;
};

struct minidump_memory_info_list {
    uint32_t size_of_header;
    uint32_t size_of_entry;
    uint64_t number_of_entries;
    struct minidump_memory_info memory_info[0];
};

struct minidump_thread_info {
    uint32_t thread_id;
    uint32_t dump_flags;
    uint32_t dump_error;
    uint32_t exit_status;
    uint64_t create_time;
    uint64_t exit_time;
    uint64_t kernel_time;
    uint64_t user_time;
    uint64_t start_address;
    uint64_t affinity;
};

struct minidump_thread_info_list {
    uint32_t size_of_header;
    uint32_t size_of_entry;
    uint32_t number_of_entries;
    struct minidump_thread_info entries[0];
};

struct avrf_handle_operation {
    // Define fields as needed
};

struct minidump_handle_operation_list {
    uint32_t size_of_header;
    uint32_t size_of_entry;
    uint32_t number_of_entries;
    uint32_t reserved;
    struct avrf_handle_operation operations[0];
};

struct minidump_directory {
    uint32_t stream_type;
    struct minidump_location_descriptor location;
};

struct r_bin_mdmp_obj {
    struct {
        void *buf;
        uint64_t length;
    } *b;
    void *kv;
    struct {
        void *threads;
        void *modules;
        void *memories;
        struct {
            uint64_t base_rva;
            void *memories;
        } memories64;
        void *memory_infos;
        void *ex_threads;
        void *unloaded_modules;
        void *thread_infos;
        void *operations;
        void *exception;
        void *system_info;
        void *comments_a;
        void *comments_w;
        void *handle_data;
        void *function_table;
        struct {
            void *misc_info_1;
        } misc_info;
    } streams;
};

enum {
    THREAD_LIST_STREAM,
    MODULE_LIST_STREAM,
    MEMORY_LIST_STREAM,
    EXCEPTION_STREAM,
    SYSTEM_INFO_STREAM,
    THREAD_EX_LIST_STREAM,
    MEMORY_64_LIST_STREAM,
    COMMENT_STREAM_A,
    COMMENT_STREAM_W,
    HANDLE_DATA_STREAM,
    FUNCTION_TABLE_STREAM,
    UNLOADED_MODULE_LIST_STREAM,
    MISC_INFO_STREAM,
    MEMORY_INFO_LIST_STREAM,
    THREAD_INFO_LIST_STREAM,
    HANDLE_OPERATION_LIST_STREAM,
    LAST_RESERVED_STREAM,
    UNUSED_STREAM,
    RESERVED_STREAM_0,
    RESERVED_STREAM_1
};

static inline void eprintf(const char *fmt, ...) {}
static inline void sdb_set(void *kv, const char *k, const char *v, int n) {}
static inline void sdb_num_set(void *kv, const char *k, uint64_t v, int n) {}
static inline char *sdb_fmt(const char *fmt, ...) { return NULL; }
static inline void r_list_append(void *list, void *item) {}