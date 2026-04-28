#include <stddef.h>
#include <sys/types.h>
#include <errno.h>

typedef int sctp_disposition_t;
typedef int sctp_subtype_t;
typedef int sctp_cmd_seq_t;

struct sctp_endpoint;
struct sctp_association;
struct sctp_chunk;
struct sctp_paramhdr;

#define SCTP_CID_ABORT 0
#define SCTP_MIB_OUTCTRLCHUNKS 0
#define SCTP_MIB_CURRESTAB 0
#define SCTP_MIB_ABORTEDS 0
#define ECONNABORTED ECONNABORTED
#define SCTP_ERROR_PROTO_VIOLATION 0

#define SCTP_ST_CHUNK(x) 0
#define SCTP_CHUNK(x) NULL
#define SCTP_PERR(x) NULL
#define SCTP_ERROR(x) NULL

static int sctp_auth_recv_cid(int cid, const struct sctp_association *asoc) { return 0; }
static struct sctp_chunk *sctp_make_violation_paramlen(const struct sctp_association *asoc, struct sctp_chunk *chunk, struct sctp_paramhdr *param) { return NULL; }
static void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, void *arg) {}
static void sctp_sf_pdiscard(const struct sctp_endpoint *ep, const struct sctp_association *asoc, int state, void *arg, sctp_cmd_seq_t *commands) {}

#define SCTP_CMD_REPLY 0
#define SCTP_CMD_SET_SK_ERR 0
#define SCTP_CMD_ASSOC_FAILED 0
#define SCTP_DISPOSITION_ABORT 0
#define SCTP_DISPOSITION_NOMEM 0