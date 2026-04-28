#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char gchar;

struct wtap_rec;
struct Buffer;

struct wtap {
    void* fh;
    struct {
        struct {
            char* opt_comment;
            char* shb_hardware;
            char* shb_os;
            char* shb_user_appl;
        } shb_hdr;
        int file_type_subtype;
        int file_encap;
        int file_tsprec;
        int (*subtype_read)(struct wtap*, int*, gchar**, long long*);
        int (*subtype_seek_read)(struct wtap*, long long, struct wtap_rec*, struct Buffer*, int*, gchar**);
        void (*subtype_close)(struct wtap*);
        int snapshot_length;
        void* priv;
    };
};

struct nettrace_3gpp_32_423_file_info_t {
    struct wtap* wth_tmp_file;
};

char xml_magic[] = "<?xml";
char Threegpp_doc_no[] = "32.423";

typedef enum {
    WTAP_OPEN_ERROR,
    WTAP_OPEN_NOT_MINE,
    WTAP_OPEN_MINE
} wtap_open_return_val;

extern int file_read(void *buf, int size, void *fh);
extern int file_error(void *fh, gchar **err_info);
extern int file_seek(void *fh, long offset, int whence, int *err);
extern wtap_open_return_val create_temp_pcapng_file(struct wtap *wth, int *err, gchar **err_info, struct nettrace_3gpp_32_423_file_info_t *file_info);
extern int nettrace_read(struct wtap *wth, int *err, gchar **err_info, long long *data_offset);
extern int nettrace_seek_read(struct wtap *wth, long long seek_off, struct wtap_rec *rec, struct Buffer *buf, int *err, gchar **err_info);
extern void nettrace_close(struct wtap *wth);

#define WTAP_FILE_TYPE_SUBTYPE_NETTRACE_3GPP_32_423 0
#define SEEK_SET 0
#define g_new0(type, count) ((type*)calloc(count, sizeof(type)))

typedef struct wtap wtap;
typedef struct nettrace_3gpp_32_423_file_info_t nettrace_3gpp_32_423_file_info_t;