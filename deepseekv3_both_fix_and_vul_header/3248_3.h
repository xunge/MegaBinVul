#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define HTTP_INTERNAL_SERVER_ERROR 500

typedef struct dav_error dav_error;
typedef struct apr_pool_t apr_pool_t;
typedef struct dav_hooks dav_hooks;

typedef struct svn_stringbuf_t {
    char *data;
    size_t len;
} svn_stringbuf_t;

typedef struct dav_resource_private {
    svn_stringbuf_t *uri_path;
    void *repos;
    void *root;
    void *r;
    void *svn_client_options;
    char *repos_path;
    int restype;
} dav_resource_private;

typedef struct dav_resource {
    int type;
    int exists;
    int collection;
    int versioned;
    dav_hooks *hooks;
    apr_pool_t *pool;
    char *uri;
    dav_resource_private *info;
} dav_resource;

enum {
    DAV_RESOURCE_TYPE_REGULAR,
    DAV_RESOURCE_TYPE_WORKING,
    DAV_RESOURCE_TYPE_ACTIVITY,
    DAV_RESOURCE_TYPE_PRIVATE
};

enum {
    DAV_SVN_RESTYPE_WRK_COLLECTION,
    DAV_SVN_RESTYPE_ACT_COLLECTION,
    DAV_SVN_RESTYPE_TXN_COLLECTION,
    DAV_SVN_RESTYPE_REV_COLLECTION
};

static void* apr_pcalloc(apr_pool_t *pool, size_t size);
static char* apr_psprintf(apr_pool_t *pool, const char *fmt, ...);
static char* get_parent_path(const char *path, int canonicalize, apr_pool_t *pool);
static char* svn_urlpath__canonicalize(const char *uri, apr_pool_t *pool);
static svn_stringbuf_t* svn_stringbuf_create(const char *str, apr_pool_t *pool);
static dav_error* dav_svn__new_error(apr_pool_t *pool, int code, int subcode, const char *msg);
static dav_resource* create_private_resource(const dav_resource *resource, int restype);