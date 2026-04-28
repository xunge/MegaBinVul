#include <stdint.h>
#include <stddef.h>

typedef struct _hf_register_info {
    int *hf_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint64_t bitmask;
        const char *blurb;
        int hfinfo;
    } hfinfo;
} hf_register_info;

typedef int gint;

static int hf_se_cpu_id;
static int hf_se_thread_id;
static int hf_se_event_length;
static int hf_se_nparams;
static int hf_se_event_type;
static int hf_se_param_lens;
static int hf_se_param_len;
static int hf_param_ID_bytes;
static int hf_param_action_uint32;
static int hf_param_addr_bytes;
static int hf_param_addr_uint64;
static int hf_param_args_string;
static int hf_param_argument_uint64;
static int hf_param_backlog_uint32;
static int hf_param_cgroups_bytes;
static int hf_param_clockid_uint8;
static int hf_param_cmd_bytes;
static int hf_param_cmd_int64;
static int hf_param_comm_string;
static int hf_param_core_uint8;
static int hf_param_cpu_sys_uint64;
static int hf_param_cpu_uint32;
static int hf_param_cpu_usr_uint64;
static int hf_param_cur_int64;
static int hf_param_cwd_string;
static int hf_param_data_bytes;
static int hf_param_desc_string;
static int hf_param_description_string;
static int hf_param_dev_string;
static int hf_param_dev_uint32;
static int hf_param_dir_string;
static int hf_param_dirfd_int64;
static int hf_param_domain_bytes;
static int hf_param_dpid_bytes;
static int hf_param_dqb_bhardlimit_uint64;
static int hf_param_dqb_bsoftlimit_uint64;
static int hf_param_dqb_btime_bytes;
static int hf_param_dqb_curspace_uint64;
static int hf_param_dqb_ihardlimit_uint64;
static int hf_param_dqb_isoftlimit_uint64;
static int hf_param_dqb_itime_bytes;
static int hf_param_dqi_bgrace_bytes;
static int hf_param_dqi_flags_bytes;
static int hf_param_dqi_igrace_bytes;
static int hf_param_egid_bytes;
static int hf_param_env_string;
static int hf_param_error_bytes;
static int hf_param_euid_bytes;
static int hf_param_event_data_bytes;
static int hf_param_event_data_uint64;
static int hf_param_event_type_uint32;
static int hf_param_exe_string;
static int hf_param_fd1_int64;
static int hf_param_fd2_int64;
static int hf_param_fd_in_int64;
static int hf_param_fd_int64;
static int hf_param_fd_out_int64;
static int hf_param_fdlimit_int64;
static int hf_param_fdlimit_uint64;
static int hf_param_fds_bytes;
static int hf_param_filename_bytes;
static int hf_param_filename_string;
static int hf_param_flags_bytes;
static int hf_param_flags_uint32;
static int hf_param_gid_bytes;
static int hf_param_gid_uint32;
static int hf_param_how_bytes;
static int hf_param_id_int64;
static int hf_param_id_string;
static int hf_param_id_uint32;
static int hf_param_image_string;
static int hf_param_in_fd_int64;
static int hf_param_initval_uint64;
static int hf_param_ino_uint64;
static int hf_param_interval_bytes;
static int hf_param_ip_uint64;
static int hf_param_json_string;
static int hf_param_key_int32;
static int hf_param_length_uint64;
static int hf_param_level_bytes;
static int hf_param_linkdirfd_int64;
static int hf_param_linkpath_bytes;
static int hf_param_linkpath_string;
static int hf_param_loginuid_int32;
static int hf_param_mask_uint32;
static int hf_param_max_int64;
static int hf_param_maxevents_bytes;
static int hf_param_mode_bytes;
static int hf_param_mode_uint32;
static int hf_param_name_bytes;
static int hf_param_name_string;
static int hf_param_nativeID_uint16;
static int hf_param_newcur_int64;
static int hf_param_newdir_int64;
static int hf_param_newdirfd_int64;
static int hf_param_newmax_int64;
static int hf_param_newpath_bytes;
static int hf_param_newpath_string;
static int hf_param_next_bytes;
static int hf_param_nsems_int32;
static int hf_param_nsops_uint32;
static int hf_param_nstype_bytes;
static int hf_param_offset_uint64;
static int hf_param_oldcur_int64;
static int hf_param_olddir_int64;
static int hf_param_olddirfd_int64;
static int hf_param_oldmax_int64;
static int hf_param_oldpath_bytes;
static int hf_param_oldpath_string;
static int hf_param_op_bytes;
static int hf_param_op_uint64;
static int hf_param_operation_bytes;
static int hf_param_optlen_uint32;
static int hf_param_optname_bytes;
static int hf_param_out_fd_int64;
static int hf_param_path_bytes;
static int hf_param_path_string;
static int hf_param_peer_uint64;
static int hf_param_pgft_maj_uint64;
static int hf_param_pgft_min_uint64;
static int hf_param_pgid_bytes;
static int hf_param_pgoffset_uint64;
static int hf_param_pid_bytes;
static int hf_param_plugin_ID_uint32;
static int hf_param_pos_uint64;
static int hf_param_prot_bytes;
static int hf_param_proto_uint32;
static int hf_param_ptid_bytes;
static int hf_param_queuelen_uint32;
static int hf_param_queuemax_uint32;
static int hf_param_queuepct_uint8;
static int hf_param_quota_fmt_bytes;
static int hf_param_quota_fmt_out_bytes;
static int hf_param_quotafilepath_string;
static int hf_param_ratio_uint32;
static int hf_param_request_bytes;
static int hf_param_request_uint64;
static int hf_param_res_bytes;
static int hf_param_res_int64;
static int hf_param_res_or_fd_bytes;
static int hf_param_res_uint64;
static int hf_param_resolve_bytes;
static int hf_param_resource_bytes;
static int hf_param_ret_bytes;
static int hf_param_rgid_bytes;
static int hf_param_ruid_bytes;
static int hf_param_scope_string;
static int hf_param_sem_flg_0_bytes;
static int hf_param_sem_flg_1_bytes;
static int hf_param_sem_num_0_uint16;
static int hf_param_sem_num_1_uint16;
static int hf_param_sem_op_0_int16;
static int hf_param_sem_op_1_int16;
static int hf_param_semflg_bytes;
static int hf_param_semid_int32;
static int hf_param_semnum_int32;
static int hf_param_sgid_bytes;
static int hf_param_sig_bytes;
static int hf_param_sigmask_bytes;
static int hf_param_size_uint32;
static int hf_param_size_uint64;
static int hf_param_source_string;
static int hf_param_source_uint64;
static int hf_param_special_string;
static int hf_param_spid_bytes;
static int hf_param_status_bytes;
static int hf_param_suid_bytes;
static int hf_param_tags_bytes;
static int hf_param_target_string;
static int hf_param_tid_bytes;
static int hf_param_timeout_bytes;
static int hf_param_timeout_int64;
static int hf_param_tty_int32;
static int hf_param_tuple_bytes;
static int hf_param_type_bytes;
static int hf_param_type_string;
static int hf_param_type_uint32;
static int hf_param_uid_bytes;
static int hf_param_uid_uint32;
static int hf_param_val_bytes;
static int hf_param_val_int32;
static int hf_param_val_uint64;
static int hf_param_vm_rss_uint32;
static int hf_param_vm_size_uint32;
static int hf_param_vm_swap_uint32;
static int hf_param_vpid_bytes;
static int hf_param_vtid_bytes;
static int hf_param_whence_bytes;

static gint ett_sysdig_event;
static gint ett_sysdig_parm_lens;
static gint ett_sysdig_syscall;

static int proto_sysdig_event;

#define FT_UINT16 1
#define FT_UINT64 2
#define FT_UINT32 3
#define FT_BYTES 4
#define FT_STRING 5
#define FT_INT64 6
#define FT_UINT8 7
#define FT_INT32 8
#define FT_INT16 9
#define BASE_DEC 1
#define BASE_HEX 2
#define BASE_NONE 3
#define BASE_OCT 4
#define HFILL 0

#define VALS(x) NULL

static const char* event_type_vals[] = { NULL };
static const char* nativeID_uint16_vals[] = { NULL };

#define array_length(x) (sizeof(x)/sizeof(x[0]))

void proto_register_field_array(int proto, hf_register_info *hf, int count);
void proto_register_subtree_array(gint **ett, int count);
int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void register_dissector(const char *name, void (*dissector)(void), int proto);
void dissect_sysdig_event(void);