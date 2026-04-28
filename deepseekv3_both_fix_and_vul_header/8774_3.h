#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>

typedef int File;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef unsigned short my_bool;
typedef long long my_off_t;
typedef unsigned long long ha_rows;
typedef unsigned int myf;

typedef struct st_mi_state {
    ha_rows records;
    my_off_t del;
    my_off_t data_file_length;
    my_off_t key_file_length;
    ulong checksum;
    short empty;
} MI_STATE;

typedef struct st_mi_pack {
    my_off_t header_length;
} MI_PACK;

typedef struct st_mi_header {
    uchar options[2];
} MI_HEADER;

typedef struct st_mi_share_state {
    MI_STATE state;
    MI_HEADER header;
    ulong version;
    my_off_t dellink;
    ulong changed;
    ulong split;
} MI_SHARE_STATE;

typedef struct st_keyinfo {
    void *seg;
} KEYINFO;

typedef struct st_io_cache {
    int error;
    my_off_t end_of_file;
    File file;
} IO_CACHE;

typedef struct st_myisam_share {
    MI_PACK pack;
    MI_SHARE_STATE state;
    ulong options;
    File kfile;
    char *data_file_name;
    void *file_map;
    size_t mmaped_length;
    KEYINFO *keyinfo;
    ulong base_keys;
    ulong state_key_map;
    int pack_reclength;
    int data_file_type;
    int new_data_file_type;
} MYISAM_SHARE;

typedef struct st_mi_info {
    MYISAM_SHARE *s;
    MI_STATE *state;
    File dfile;
    IO_CACHE rec_cache;
    short opt_flag;
    short update;
    int errkey;
    my_off_t dupp_key_pos;
    uchar *lastkey;
} MI_INFO;

typedef struct st_mi_check {
    ulong testflag;
    size_t use_buffers;
    int using_global_keycache;
    size_t key_cache_block_size;
    size_t read_buffer_length;
    size_t write_buffer_length;
    IO_CACHE read_cache;
    char *temp_filename;
    int tmpfile_createflag;
    int error_printed;
    int retry_repair;
    ulong glob_crc;
} MI_CHECK;

typedef struct st_sort_info {
    MI_INFO *info;
    MI_CHECK *param;
    my_off_t filelength;
    ha_rows dupp;
    ha_rows max_records;
    void *buff;
    int new_data_file_type;
} SORT_INFO;

typedef struct st_mi_sort_param {
    SORT_INFO *sort_info;
    IO_CACHE read_cache;
    my_off_t pos;
    my_off_t max_pos;
    my_off_t filepos;
    my_off_t start_recpos;
    void *record;
    void *rec_buff;
    int fix_datafile;
    int master;
    int calc_checksum;
} MI_SORT_PARAM;

#define STATE_NOT_OPTIMIZED_KEYS (1UL << 0)
#define STATE_NOT_SORTED_PAGES (1UL << 1)
#define STATE_NOT_ANALYZED (1UL << 2)

#define MYF(flags) flags
#define MY_WME 0
#define MY_WAIT_IF_FULL 0
#define MY_SEEK_END 0
#define MY_REDEL_MAKE_BACKUP 0
#define MY_REDEL_NO_COPY_STAT 0
#define DATA_TMP_EXT ".TMD"
#define MI_NAME_DEXT ".MYD"
#define T_UNPACK 0
#define T_SILENT 0
#define T_REP 0
#define T_CALC_CHECKSUM 0
#define T_CREATE_MISSING_KEYS 0
#define T_VERBOSE 0
#define T_FORCE_UNIQUENESS 0
#define T_QUICK 0
#define T_RETRY_WITHOUT_QUICK 0
#define T_WRITE_LOOP 0
#define T_SAFE_REPAIR 0
#define T_BACKUP_DATA 0
#define HA_OPTION_CHECKSUM 0
#define HA_OPTION_COMPRESS_RECORD 0
#define HA_OFFSET_ERROR ((my_off_t)-1)
#define HA_STATE_CHANGED 0
#define HA_STATE_ROW_CHANGED 0
#define HA_ERR_FOUND_DUPP_KEY 0
#define USE_WHOLE_KEY 0
#define READ_CACHE 0
#define WRITE_CACHE 0
#define WRITE_CACHE_USED 0
#define READ_CACHE_USED 0
#define mi_key_file_datatmp 0

#define DBUG_ENTER(x)
#define DBUG_RETURN(x) return x
#define DBUG_DUMP(x,y,z)
#define DBUG_ASSERT(x)

#define dflt_key_cache NULL
#define mi_int2store(x,y)
#define mi_set_all_keys_active(x,y)
#define mi_check_print_error(x,...)
#define mi_check_print_warning(x,...)
#define mi_check_print_info(x,...)
#define mi_alloc_rec_buff(x,y,z) 0
#define mi_get_rec_buff_ptr(x,y) NULL
#define mi_open_datafile(x,y,z,w) 0
#define mi_mark_crashed_on_repair(x)
#define mi_drop_all_indexes(x,y,z)
#define lock_memory(x)
#define sort_get_next_record(x) 0
#define writekeys(x) 0
#define _mi_make_key(x,y,z,w,v) 0
#define _mi_print_key(x,y,z,w) 0
#define sort_write_record(x) 0
#define write_data_suffix(x,y) 0
#define flush_io_cache(x) 0
#define end_io_cache(x) 0
#define flush_blocks(x,y,z) 0
#define change_to_newfile(x,y,z,w) 0
#define init_key_cache(x,y,z,w,v) 0
#define init_io_cache(x,y,z,w,v,u,t) 0
#define set_data_file_type(x,y) 0
#define filecopy(x,y,z,w,v,u) 0
#define fn_format(x,y,z,w,v) NULL
#define mysql_file_create(x,y,z,w,v) 0
#define mysql_file_seek(x,y,z,w) 0
#define mysql_file_chsize(x,y,z,w) 0
#define mysql_file_close(x,y) 0
#define mysql_file_delete(x,y,z) 0
#define my_munmap(x,y) 0
#define my_errno errno
#define my_free(x) free(x)
#define bzero(x,y) memset(x,0,y)
#define llstr(x,y) "0"