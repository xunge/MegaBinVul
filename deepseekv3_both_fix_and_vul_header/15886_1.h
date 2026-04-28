#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct stream_t stream_t;
typedef struct libvlc_instance_t libvlc_instance_t;

typedef struct
{
    int i_major;
    int i_minor;
    int i_revision;
    int i_extra;
    char *psz_url;
    char *psz_desc;
} release_t;

typedef enum
{
    BINARY_SIGNATURE,
    TEXT_SIGNATURE
} signature_type_t;

typedef struct
{
    signature_type_t type;
    uint8_t issuer_longid[8];
    uint8_t hash_verification[2];
} signature_packet_t;

typedef struct public_key_t
{
    uint8_t longid[8];
    void *key;
    signature_packet_t sig;
} public_key_t;

typedef struct
{
    libvlc_instance_t *p_libvlc;
    release_t release;
    public_key_t *p_pkey;
} update_t;

#define UPDATE_VLC_STATUS_URL "http://update.videolan.org/vlc/status.txt"
#define VLC_OBJECT(x) (x)
#define VLC_SUCCESS 0
#define FREENULL(x) do { free(x); x = NULL; } while(0)

extern const unsigned char videolan_public_key[1024];
extern const uint8_t videolan_public_key_longid[8];

extern stream_t *stream_UrlNew(libvlc_instance_t *, const char *);
extern int64_t stream_Size(stream_t *);
extern int stream_Read(stream_t *, void *, int64_t);
extern void stream_Delete(stream_t *);
extern void msg_Err(libvlc_instance_t *, const char *, ...);
extern void msg_Dbg(libvlc_instance_t *, const char *, ...);
extern void msg_Info(libvlc_instance_t *, const char *, ...);
extern void msg_Warn(libvlc_instance_t *, const char *, ...);
extern int download_signature(void *, signature_packet_t *, const char *);
extern public_key_t *download_key(void *, const uint8_t *, const uint8_t *);
extern int parse_public_key(const void *, size_t, public_key_t *, void *);
extern uint8_t *hash_from_public_key(public_key_t *);
extern uint8_t *hash_from_text(const char *, const signature_packet_t *);
extern int verify_signature(const signature_packet_t *, const void *, const uint8_t *);