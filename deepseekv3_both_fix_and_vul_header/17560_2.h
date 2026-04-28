#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>

#define GNTTABOP_ARG_MASK 0xff
#define GNTTABOP_CMD_MASK 0xff

#define GNTTABOP_map_grant_ref 1
#define GNTTABOP_unmap_grant_ref 2
#define GNTTABOP_unmap_and_replace 3
#define GNTTABOP_setup_table 4
#define GNTTABOP_transfer 5
#define GNTTABOP_copy 6
#define GNTTABOP_query_size 7
#define GNTTABOP_set_version 8
#define GNTTABOP_get_status_frames 9
#define GNTTABOP_get_version 10
#define GNTTABOP_swap_grant_ref 11
#define GNTTABOP_cache_flush 12

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define guest_handle_cast(handle, type) ((void*)(handle))
#define guest_handle_okay(handle, count) (1)
#define guest_handle_add_offset(handle, offset) ((void)0)
#define unlikely(x) (x)

#define ASSERT(cond) ((void)0)
#define __HYPERVISOR_grant_table_op 0
#define hypercall_create_continuation(op, fmt, ...) (0)

typedef void gnttab_map_grant_ref_t;
typedef void gnttab_unmap_grant_ref_t;
typedef void gnttab_unmap_and_replace_t;
typedef void gnttab_setup_table_t;
typedef void gnttab_transfer_t;
typedef void gnttab_copy_t;
typedef void gnttab_query_size_t;
typedef void gnttab_set_version_t;
typedef void gnttab_get_status_frames_t;
typedef void gnttab_get_version_t;
typedef void gnttab_swap_grant_ref_t;
typedef void gnttab_cache_flush_t;

long gnttab_map_grant_ref(void*, unsigned int);
long gnttab_unmap_grant_ref(void*, unsigned int);
long gnttab_unmap_and_replace(void*, unsigned int);
long gnttab_setup_table(void*, unsigned int, unsigned int);
long gnttab_transfer(void*, unsigned int);
long gnttab_copy(void*, unsigned int);
long gnttab_query_size(void*, unsigned int);
long gnttab_set_version(void*);
long gnttab_get_status_frames(void*, unsigned int, unsigned int);
long gnttab_get_version(void*);
long gnttab_swap_grant_ref(void*, unsigned int);
long gnttab_cache_flush(void*, unsigned int*, unsigned int);