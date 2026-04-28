#include <stdio.h>
#include <time.h>
#include <sys/types.h>

#define HA_MAX_POSSIBLE_KEY 64
#define HA_KEY_ALG_RTREE 1
#define HA_OFFSET_ERROR (~(my_off_t)0)
#define T_SILENT 1
#define MI_NAME_IEXT ".MYI"
#define INDEX_TMP_EXT ".TMD"
#define WRITEINFO_UPDATE_KEYFILE 1
#define F_UNLCK 0
#define F_WRLCK 1
#define STATE_NOT_SORTED_PAGES 1
#define FLUSH_IGNORE_CHANGED 1
#define MYF(x) x
#define MY_WME 1
#define MY_REDEL_NO_COPY_STAT 2
#define HA_STATE_CHANGED 1
#define HA_STATE_ROW_CHANGED 2

typedef unsigned int uint;
typedef unsigned long ulong;
typedef long my_off_t;
typedef int File;
typedef unsigned char my_bool;
#define reg1 register
#define reg2 register

typedef struct st_mi_check {
    int testflag;
    char temp_filename[1024];
    int tmpfile_createflag;
    my_off_t new_file_pos;
} MI_CHECK;

typedef struct st_mi_keydef {
    int key_alg;
} MI_KEYDEF;

typedef struct st_mi_state_info {
    ulong version;
    my_off_t key_root[HA_MAX_POSSIBLE_KEY];
    my_off_t key_del[HA_MAX_POSSIBLE_KEY];
    struct {
        uint max_block_size_index;
    } header;
    ulong changed;
    ulong key_map;
    my_off_t key_file_length;
} MI_STATE_INFO;

typedef struct st_myisam_share {
    File kfile;
    char index_file_name[1024];
    struct {
        uint keys;
        my_off_t keystart;
    } base;
    MI_KEYDEF keyinfo[HA_MAX_POSSIBLE_KEY];
    MI_STATE_INFO state;
    uint r_locks;
    uint w_locks;
    uint tot_locks;
    void *key_cache;
} MYISAM_SHARE;

typedef struct st_mi_info {
    MYISAM_SHARE *s;
    MI_STATE_INFO *state;
    int lock_type;
    short update;
} MI_INFO;

extern int mi_key_file_datatmp;

void DBUG_ENTER(const char *func);
void DBUG_RETURN(int retval);
char *fn_format(char *to, const char *name, const char *extension, const char *suffix, int flag);
File mysql_file_create(int key, const char *filename, int mode, int createflag, int myf);
void mi_check_print_error(MI_CHECK *param, const char *fmt, ...);
int filecopy(MI_CHECK *param, File to_file, File from_file, long pos, ulong length, const char *message);
int mi_is_key_active(ulong key_map, uint key);
int sort_one_index(MI_CHECK *param, MI_INFO *info, MI_KEYDEF *keyinfo, my_off_t root, File new_file);
void flush_key_blocks(void *key_cache, File file, int flush_flag);
int _mi_writeinfo(MI_INFO *info, int flag);
int mysql_file_close(File file, int myf);
int change_to_newfile(const char *filename, const char *extension, const char *tmp_ext, int myf);
int mi_open_keyfile(MYISAM_SHARE *share);
void _mi_readinfo(MI_INFO *info, int lock_type, int flag);
int mysql_file_delete(int key, const char *filename, int myf);