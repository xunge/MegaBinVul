#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define BUFSIZE 1024

typedef void* gpointer;
typedef void (*GCallback)(gpointer data);

typedef struct cpdb_frontend_obj_t cpdb_frontend_obj_t;
typedef struct cpdb_printer_obj_t {
    char *name;
    char *backend_name;
    void *backend_proxy;
    char *id;
} cpdb_printer_obj_t;
typedef struct cpdb_options_t {
    int count;
    int media_count;
    void *table;
    void *media;
} cpdb_options_t;
typedef struct cpdb_job_t {
    char *job_id;
    char *title;
    char *printer_id;
    char *state;
    char *submitted_at;
} cpdb_job_t;
typedef struct cpdb_margin_t {
    int left;
    int right;
    int top;
    int bottom;
} cpdb_margin_t;

typedef struct {
    void* dummy[3];
} GHashTableIter;

extern cpdb_frontend_obj_t *f;
extern const char *locale;
extern void printOption(gpointer value);
extern void printMedia(gpointer value);
extern void display_help();
extern void printTranslations(cpdb_printer_obj_t *p);
extern void acquire_details_callback(cpdb_printer_obj_t *p, gpointer user_data);
extern void acquire_translations_callback(cpdb_printer_obj_t *p, gpointer user_data);

/* Function prototypes */
void cpdbDeleteFrontendObj(cpdb_frontend_obj_t *f);
void g_message(const char *msg);
void cpdbDisconnectFromDBus(cpdb_frontend_obj_t *f);
void cpdbConnectToDBus(cpdb_frontend_obj_t *f);
void cpdbHideRemotePrinters(cpdb_frontend_obj_t *f);
void cpdbUnhideRemotePrinters(cpdb_frontend_obj_t *f);
void cpdbHideTemporaryPrinters(cpdb_frontend_obj_t *f);
void cpdbUnhideTemporaryPrinters(cpdb_frontend_obj_t *f);
cpdb_printer_obj_t *cpdbFindPrinterObj(cpdb_frontend_obj_t *f, const char *printer_id, const char *backend_name);
cpdb_options_t *cpdbGetAllOptions(cpdb_printer_obj_t *p);
char *cpdbGetDefault(cpdb_printer_obj_t *p, const char *option_name);
char *cpdbGetSetting(cpdb_printer_obj_t *p, const char *setting_name);
char *cpdbGetCurrent(cpdb_printer_obj_t *p, const char *option_name);
char *cpdbGetStringCopy(const char *str);
void cpdbAddSettingToPrinter(cpdb_printer_obj_t *p, char *name, char *value);
void cpdbClearSettingFromPrinter(cpdb_printer_obj_t *p, const char *name);
char *cpdbGetState(cpdb_printer_obj_t *p);
int cpdbIsAcceptingJobs(cpdb_printer_obj_t *p);
void print_backend_call_ping_sync(void *proxy, char *id, void *arg1, void *arg2);
cpdb_printer_obj_t *cpdbGetDefaultPrinter(cpdb_frontend_obj_t *f);
cpdb_printer_obj_t *cpdbGetDefaultPrinterForBackend(cpdb_frontend_obj_t *f, const char *backend_name);
int cpdbSetUserDefaultPrinter(cpdb_printer_obj_t *p);
int cpdbSetSystemDefaultPrinter(cpdb_printer_obj_t *p);
void cpdbPrintFilePath(cpdb_printer_obj_t *p, const char *file_path, const char *final_path);
void cpdbPrintFile(cpdb_printer_obj_t *p, const char *file_path);
int cpdbGetActiveJobsCount(cpdb_printer_obj_t *p);
int cpdbGetAllJobs(cpdb_frontend_obj_t *f, cpdb_job_t **jobs, int active_only);
int cpdbCancelJob(cpdb_printer_obj_t *p, const char *job_id);
void cpdbPicklePrinterToFile(cpdb_printer_obj_t *p, const char *path, cpdb_frontend_obj_t *f);
char *cpdbGetOptionTranslation(cpdb_printer_obj_t *p, const char *option_name, const char *locale);
char *cpdbGetChoiceTranslation(cpdb_printer_obj_t *p, const char *option_name, const char *choice_name, const char *locale);
char *cpdbGetGroupTranslation(cpdb_printer_obj_t *p, const char *group_name, const char *locale);
void cpdbGetAllTranslations(cpdb_printer_obj_t *p, const char *locale);
int cpdbGetMediaSize(cpdb_printer_obj_t *p, const char *media, int *width, int *length);
int cpdbGetMediaMargins(cpdb_printer_obj_t *p, const char *media, cpdb_margin_t **margins);
void cpdbAcquireDetails(cpdb_printer_obj_t *p, GCallback callback, gpointer user_data);
void cpdbAcquireTranslations(cpdb_printer_obj_t *p, const char *locale, GCallback callback, gpointer user_data);
void g_hash_table_iter_init(GHashTableIter *iter, void *hash_table);
int g_hash_table_iter_next(GHashTableIter *iter, gpointer *key, gpointer *value);