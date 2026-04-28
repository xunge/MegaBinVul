#include <stdint.h>
#include <stdbool.h>

typedef int32_t int32;
typedef int64_t int64;

typedef struct ContinuousAgg {
    int relid;
    struct {
        int32 mat_hypertable_id;
        int32 raw_hypertable_id;
    } data;
    int64 (*bucket_function)(int64);
} ContinuousAgg;

typedef struct InternalTimeRange {
    int64 start;
    int64 end;
    char type;
} InternalTimeRange;

typedef enum CaggRefreshCallContext {
    CAGG_REFRESH_POLICY,
    CAGG_REFRESH_OTHER
} CaggRefreshCallContext;

typedef struct CaggsInfo {
    void* caggs;
} CaggsInfo;

typedef struct Catalog {
    int dummy;
} Catalog;

typedef struct Hypertable {
    int dummy;
} Hypertable;

#define INVALID_CHUNK_ID 0
#define REFRESH_FUNCTION_NAME "continuous_agg_refresh"
#define SPI_OK_CONNECT 1
#define SPI_OK_FINISH 2
#define LOG 3
#define DEBUG1 4
#define ACLCHECK_NOT_OWNER 5
#define AccessExclusiveLock 6
#define CONTINUOUS_AGGS_INVALIDATION_THRESHOLD 7
#define SPI_OPT_NONATOMIC 8
#define ERROR 9
#define ERRCODE_INVALID_PARAMETER_VALUE 10
#define ERRCODE_INTERNAL_ERROR 11

Catalog* ts_catalog_get();
int pg_class_ownercheck(int relid, int userid);
int GetUserId();
void aclcheck_error(int code, int type, const char* name);
int get_rel_relkind(int relid);
int get_relkind_objtype(int relkind);
const char* get_rel_name(int relid);
void PreventCommandIfReadOnly(const char* name);
void PreventInTransactionBlock(bool condition, const char* name);
Hypertable* cagg_get_hypertable_or_fail(int id);
bool hypertable_is_distributed(Hypertable* ht);
bool ts_continuous_agg_bucket_width_variable(const ContinuousAgg* cagg);
void ts_compute_inscribed_bucketed_refresh_window_variable(int64* start, int64* end, int64 (*func)(int64));
InternalTimeRange compute_inscribed_bucketed_refresh_window(const InternalTimeRange* range, int64 width);
int64 ts_continuous_agg_bucket_width(const ContinuousAgg* cagg);
void ereport(int level, ...);
int errcode(int code);
int errmsg(const char* msg);
int errdetail(const char* detail);
int errhint(const char* hint);
void log_refresh_window(int level, const ContinuousAgg* cagg, InternalTimeRange* window, const char* msg);
void LockRelationOid(int oid, int lockmode);
int catalog_get_table_id(Catalog* catalog, int table);
int64 invalidation_threshold_compute(const ContinuousAgg* cagg, InternalTimeRange* window);
int64 invalidation_threshold_set_or_get(int raw_id, int64 threshold);
void emit_up_to_date_notice(const ContinuousAgg* cagg, CaggRefreshCallContext ctx);
int SPI_connect_ext(int options);
const char* SPI_result_code_string(int code);
int SPI_finish();
int SPI_exec(const char* src, int tcount);
int SPI_commit_and_chain();
CaggsInfo ts_continuous_agg_get_all_caggs_info(int raw_id);
void remote_invalidation_process_hypertable_log(int mat_id, int raw_id, char type, const CaggsInfo* info);
void invalidation_process_hypertable_log(int mat_id, int raw_id, char type, const CaggsInfo* info);
const ContinuousAgg* ts_continuous_agg_find_by_mat_hypertable_id(int mat_id);
bool process_cagg_invalidations_and_refresh(const ContinuousAgg* cagg, InternalTimeRange* window, CaggRefreshCallContext ctx, int chunk_id);
void elog(int level, const char* fmt, ...);