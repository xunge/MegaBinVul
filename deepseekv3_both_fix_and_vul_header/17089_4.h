#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HTTP_MAX_URI 1024
#define MIME_MAX_SUPER 64
#define MIME_MAX_TYPE 64

typedef struct cupsd_job_s cupsd_job_t;
typedef struct cupsd_client_s cupsd_client_t;
typedef struct cupsd_printer_s cupsd_printer_t;
typedef struct mime_type_s mime_type_t;
typedef struct cups_array_s cups_array_t;

typedef enum {
    CUPSD_LOG_DEBUG,
    CUPSD_LOG_DEBUG2,
    CUPSD_LOG_INFO,
    CUPSD_LOG_NOTICE
} cupsd_log_level_t;

typedef enum {
    IPP_JOB_PENDING,
    IPP_JOB_HELD,
    IPP_JOB_STOPPED,
    IPP_JOB_ABORTED
} ipp_jstate_t;

typedef enum {
    IPP_TAG_ZERO,
    IPP_TAG_INTEGER,
    IPP_TAG_ENUM,
    IPP_TAG_BOOLEAN,
    IPP_TAG_TEXT,
    IPP_TAG_NAME,
    IPP_TAG_NAMELANG,
    IPP_TAG_KEYWORD,
    IPP_TAG_URI,
    IPP_TAG_MIMETYPE,
    IPP_TAG_RANGE,
    IPP_TAG_BEGIN_COLLECTION,
    IPP_TAG_JOB,
    IPP_TAG_UNSUPPORTED_GROUP,
    IPP_TAG_NOVALUE
} ipp_tag_t;

typedef enum {
    IPP_OK,
    IPP_OK_SUBST,
    IPP_BAD_REQUEST,
    IPP_NOT_AUTHORIZED,
    IPP_NOT_ACCEPTING,
    IPP_CONFLICT,
    IPP_DOCUMENT_FORMAT,
    IPP_ATTRIBUTES,
    IPP_NOT_POSSIBLE,
    IPP_INTERNAL_ERROR,
    IPP_CREATE_JOB
} ipp_status_t;

typedef enum {
    HTTP_OK,
    HTTP_UNAUTHORIZED,
    HTTP_UPGRADE_REQUIRED,
    HTTP_URI_CODING_ALL
} http_status_t;

typedef enum {
    CUPS_PRINTER_CLASS = 0x01,
    CUPS_PRINTER_REMOTE = 0x02
} cups_printer_type_t;

typedef enum {
    CUPSD_DIRTY_JOBS,
    CUPSD_JOB_PURGE,
    CUPSD_EVENT_JOB_CREATED
} cupsd_constants_t;

typedef struct {
    int integer;
    char *text;
    struct {
        int lower;
        int upper;
    } range;
    void *collection;
    struct {
        char *text;
    } string;
} ipp_value_t;

typedef struct ipp_attribute_s {
    ipp_tag_t value_tag;
    int num_values;
    ipp_value_t *values;
    struct ipp_attribute_s *next;
    ipp_tag_t group_tag;
} ipp_attribute_t;

typedef struct {
    int op;
    struct {
        struct {
            int operation_id;
        } op;
        struct {
            ipp_status_t status_code;
        } status;
    } request;
    ipp_attribute_t *attrs;
} ipp_t;

typedef struct {
    char *hostname;
    void *hostaddr;
    int tls;
    int port;
} http_t;

struct cupsd_client_s {
    int number;
    char username[256];
    http_t *http;
    ipp_t *request;
    ipp_t *response;
    char clientname[256];
    int clientport;
};

struct ppd_cache_s {
    void *mandatory;
};

struct cupsd_printer_s {
    char *name;
    char *uri;
    int type;
    int shared;
    int accepting;
    struct ppd_cache_s *pc;
    char *job_sheets[2];
    int num_options;
    char **options;
    void *filetypes;
    int num_auth_info_required;
    char **auth_info_required;
    void *op_policy_ptr;
    int holding_new_jobs;
};

struct mime_type_s {
    char *super;
    char *type;
};

struct cupsd_job_s {
    int id;
    int dtype;
    ipp_t *attrs;
    int dirty;
    char *username;
    char *name;
    ipp_attribute_t *state;
    ipp_jstate_t state_value;
    ipp_attribute_t *reasons;
    ipp_attribute_t *impressions;
    ipp_attribute_t *sheets;
    ipp_attribute_t *job_sheets;
    time_t hold_until;
};

extern int MaxCopies;
extern int MaxJobs;
extern int StrictConformance;
extern int MultipleOperationTimeout;
extern int ClassifyOverride;
extern char *Classification;
extern char *ServerName;
extern cups_array_t *Jobs;

/* Function declarations */
void cupsdLogMessage(cupsd_log_level_t level, const char *format, ...);
int _cups_strcasecmp(const char *s1, const char *s2);
void send_ipp_status(cupsd_client_t *con, ipp_status_t status, const char *message, ...);
const char *_(const char *msgid);
ipp_attribute_t *ippFindAttribute(ipp_t *ipp, const char *name, ipp_tag_t type);
http_status_t cupsdCheckPolicy(void *policy, cupsd_client_t *con, void *data);
void send_http_error(cupsd_client_t *con, http_status_t status, cupsd_printer_t *printer);
void ippDeleteAttribute(ipp_t *ipp, ipp_attribute_t *attr);
void *cupsArrayFirst(void *array);
void *cupsArrayNext(void *array);
int cupsArrayFind(void *array, void *element);
ipp_attribute_t *ippAddString(ipp_t *ipp, ipp_tag_t group, ipp_tag_t type, const char *name, const char *language, const char *value);
ipp_attribute_t *ippAddInteger(ipp_t *ipp, ipp_tag_t group, ipp_tag_t type, const char *name, int value);
int cupsdFindBanner(const char *name);
int _ppdCacheGetPageSize(struct ppd_cache_s *pc, ipp_t *request, void *media, int *exact);
ipp_t *ippNew();
void ippAddCollection(ipp_t *ipp, ipp_tag_t group, const char *name, ipp_t *collection);
void ippDelete(ipp_t *ipp);
int cupsArrayCount(void *array);
void cupsdCleanJobs();
int check_quotas(cupsd_client_t *con, cupsd_printer_t *printer);
const char *cupsGetOption(const char *name, int num_options, char **options);
ipp_attribute_t *ippCopyAttribute(ipp_t *ipp, ipp_attribute_t *attr, int index);
int ippValidateAttribute(ipp_attribute_t *attr);
const char *cupsLastErrorString();
cupsd_job_t *cupsdAddJob(int priority, const char *dest);
ipp_t *ippNewRequest(int op);
void cupsdMarkDirty(int what);
void add_job_uuid(cupsd_job_t *job);
void apply_printer_defaults(cupsd_printer_t *printer, cupsd_job_t *job);
void cupsdSetString(char **ptr, const char *s);
void ippSetString(ipp_t *ipp, ipp_attribute_t **attr, int index, const char *value);
void ippSetGroupTag(ipp_t *ipp, ipp_attribute_t **attr, ipp_tag_t group);
void ippSetName(ipp_t *ipp, ipp_attribute_t **attr, const char *name);
void save_auth_info(cupsd_client_t *con, cupsd_job_t *job, ipp_attribute_t *auth_info);
void ippAddOutOfBand(ipp_t *ipp, ipp_tag_t group, ipp_tag_t type, const char *name);
void ippAddDate(ipp_t *ipp, ipp_tag_t group, const char *name, const char *value);
const char *ippTimeToDate(time_t t);
ipp_attribute_t *ippAddStrings(ipp_t *ipp, ipp_tag_t group, ipp_tag_t type, const char *name, const char *language, int num_values, const char * const *values);
void cupsdSetJobHoldUntil(cupsd_job_t *job, const char *until, int update);
const char *ippGetString(ipp_attribute_t *attr, int index, const char *language);
void cupsdLogJob(cupsd_job_t *job, cupsd_log_level_t level, const char *format, ...);
int copy_banner(cupsd_client_t *con, cupsd_job_t *job, const char *name);
void cupsdSetJobState(cupsd_job_t *job, ipp_jstate_t state, int purge, const char *message);
void cupsdUpdateQuota(cupsd_printer_t *printer, const char *username, int pages, int kbytes);
void httpAssembleURIf(http_status_t encoding, char *uri, size_t urisize, const char *scheme, const char *username, const char *host, int port, const char *resource, ...);
void add_job_subscriptions(cupsd_client_t *con, cupsd_job_t *job);
void cupsdAddEvent(cupsd_constants_t event, void *object, void *data, const char *message);