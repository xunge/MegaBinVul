#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    off_t total_uploaded;
} ULHandler;

typedef struct {
    off_t files;
    off_t size;
} Quota;

typedef struct {
    int state;
    off_t download_total_size;
    off_t download_current_size;
    off_t restartat;
    time_t xfer_date;
    char filename[256];
} shm_data_t;

struct statvfs statfsbuf;

extern int type;
extern off_t restartat;
extern int guest;
extern int anon_noupload;
extern int dot_write_ok;
extern int no_truncate;
extern mode_t u_mask;
extern int xferfd;
extern int clientfd;
extern int tls_cnx;
extern int tls_data_cnx;
extern int passive;
extern int data_protection_level;
extern int throttling_bandwidth_ul;
extern off_t user_quota_size;
extern int user_quota_files;
extern unsigned long long uploaded;
extern shm_data_t *shm_data_cur;
extern int state_needs_update;
extern int overflow;

extern int addreply_noformat(int, const char *);
extern int addreply(int, const char *, ...);
extern int error(int, const char *);
extern int ul_check_free_space(const char *, double);
extern int checknamesanity(const char *, int);
extern const char *get_atomic_file(const char *);
extern void opendata(void);
extern void doreply(void);
extern void tls_init_data_session(int, int);
extern void setprocessname(const char *);
extern double get_usec_time(void);
extern int ul_init(ULHandler *, int, int, int, const char *, int, int, off_t, int, int, off_t);
extern int ul_send(ULHandler *);
extern void ul_exit(ULHandler *);
extern void closedata(void);
extern off_t get_file_size(const char *);
extern int tryautorename(const char *, const char *, const char **);
extern int ul_quota_update(const char *, int, off_t);
extern void displayrate(const char *, off_t, double, const char *, int);
extern void ftpwho_lock(void);
extern void ftpwho_unlock(void);
extern int quota_update(Quota *, long long, long long, int *);
extern int rename(const char *, const char *);

#define QUOTAS
#define ANON_CAN_RESUME
#define WITH_TLS
#define FTPWHO
#define SHOW_REAL_DISK_SPACE
#define MAX_SESSION_XFER_IDLE 0
#define CPL_PRIVATE 0
#define FTPWHO_STATE_UPLOAD 0
#define MSG_NO_ASCII_RESUME ""
#define MSG_ANON_CANT_OVERWRITE ""
#define MSG_NO_DISK_SPACE ""
#define MSG_SANITY_FILE_FAILURE ""
#define MSG_RENAME_FAILURE ""
#define MSG_OPEN_FAILURE2 ""
#define MSG_STAT_FAILURE2 ""
#define MSG_NOT_REGULAR_FILE ""
#define MSG_TRANSFER_SUCCESSFUL ""
#define MSG_ABORTED ""
#define MSG_UPLOADED ""
#define MSG_QUOTA_EXCEEDED ""
#define MSG_SPACE_FREE_M ""
#define MSG_SPACE_FREE_K ""
#define FSTATFS(f, buf) fstatvfs(f, buf)
#define STATFS_BAVAIL(buf) (buf.f_bavail)
#define STATFS_FRSIZE(buf) (buf.f_frsize)