#include <cstdint>

typedef unsigned int GLenum;
typedef int32_t int32;
typedef uint32_t uint32;

class QueryManager;

class Query {
public:
    Query(QueryManager* manager, GLenum target, int32 shm_id, uint32 shm_offset);
};

struct AsyncReadPixelsCompletedQuery : public Query {
    AsyncReadPixelsCompletedQuery(QueryManager* manager, GLenum target, int32 shm_id, uint32 shm_offset);
    bool completed_;
    bool complete_result_;
};