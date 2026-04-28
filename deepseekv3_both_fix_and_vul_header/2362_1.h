#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define SSH2_FILEXFER_ATTR_PERMISSIONS 0x00000004
#define HANDLE_FILE 1

typedef struct Attrib {
    u_int32_t flags;
    u_int32_t perm;
} Attrib;

extern u_int32_t SSH2_FX_FAILURE;
extern u_int32_t SSH2_FX_PERMISSION_DENIED;
extern u_int32_t SSH2_FX_OK;
extern int readonly;
extern void *iqueue;
extern int sshbuf_get_cstring(void *, char **, size_t *);
extern int sshbuf_get_u32(void *, u_int32_t *);
extern int handle_new(int, char *, int, int, void *);
extern void send_handle(u_int32_t, int);
extern void send_status(u_int32_t, int);
extern int decode_attrib(void *, Attrib *);
extern int flags_from_portable(u_int32_t);
extern const char *string_from_portable(u_int32_t);
extern int errno_to_portable(int);
extern void fatal(const char *, ...);
extern void debug3(const char *, ...);
extern void logit(const char *, ...);
extern void verbose(const char *, ...);
extern const char *ssh_err(int);