#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct jpc_bitstream_s jpc_bitstream_t;
typedef struct jpc_dec_s {
    int maxlyrs;
    struct jpc_dec_tile_s *curtile;
    struct jpc_cstate_s *cstate;
} jpc_dec_t;
typedef struct jpc_dec_tile_s {
    struct jpc_dec_cp_s *cp;
    struct jpc_dec_tcomp_s *tcomps;
} jpc_dec_tile_t;
typedef struct jpc_dec_tcomp_s {
    struct jpc_dec_rlvl_s *rlvls;
} jpc_dec_tcomp_t;
typedef struct jpc_dec_rlvl_s {
    struct jpc_dec_band_s *bands;
    int numbands;
} jpc_dec_rlvl_t;
typedef struct jpc_dec_band_s {
    void *data;
    struct jpc_dec_prc_s *prcs;
    int numbps;
} jpc_dec_band_t;
typedef struct jpc_dec_prc_s {
    struct jpc_dec_cblk_s *cblks;
    int numcblks;
    struct jpc_tagtree_s *incltagtree;
    struct jpc_tagtree_s *numimsbstagtree;
} jpc_dec_prc_t;
typedef struct jpc_dec_cblk_s {
    int numpasses;
    int numimsbs;
    int firstpassno;
    int numlenbits;
    struct jpc_dec_seg_s *curseg;
    struct {
        struct jpc_dec_seg_s *tail;
    } segs;
} jpc_dec_cblk_t;
typedef struct jpc_dec_seg_s {
    int passno;
    int type;
    int lyrno;
    int numpasses;
    int maxpasses;
    int cnt;
    struct jas_stream_s *stream;
    struct jpc_dec_seg_s *next;
} jpc_dec_seg_t;
typedef struct jpc_dec_cp_s {
    int csty;
    struct jpc_dec_ccp_s *ccps;
} jpc_dec_cp_t;
typedef struct jpc_dec_ccp_s {
    int cblkctx;
} jpc_dec_ccp_t;
typedef struct jpc_tagtree_s jpc_tagtree_t;
typedef struct jpc_tagtreenode_s jpc_tagtreenode_t;
typedef struct jpc_ms_s jpc_ms_t;
typedef struct jas_stream_s jas_stream_t;
typedef struct jpc_cstate_s jpc_cstate_t;

#define JPC_COD_SOP 0x01
#define JPC_COD_EPH 0x02
#define JPC_COX_LAZY 0x04
#define JPC_COX_TERMALL 0x08
#define JPC_MS_SOP 0xff91
#define JPC_MS_EPH 0xff92

#define JAS_DBGLOG(level, fmt, ...)
#define JAS_CAST(type, val) ((type)(val))
#define JAS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define JPC_SEGPASSCNT(passno, firstpassno, maxpasses, lazy, termall) (maxpasses)
#define JPC_SEGTYPE(passno, firstpassno, lazy) (0)

static int jpc_floorlog2(int n);
static int jpc_getnumnewpasses(jpc_bitstream_t *inb);
static int jpc_getcommacode(jpc_bitstream_t *inb);
static int jpc_getdata(jas_stream_t *in, jas_stream_t *out, int cnt);
static int jpc_dec_lookahead(jas_stream_t *in);
static jpc_ms_t *jpc_getms(jas_stream_t *in, jpc_cstate_t *cstate);
static int jpc_ms_gettype(jpc_ms_t *ms);
static void jpc_ms_destroy(jpc_ms_t *ms);
static int jas_eprintf(const char *format, ...);
static unsigned long jas_stream_getrwcount(jas_stream_t *stream);
static jpc_bitstream_t *jpc_bitstream_sopen(jas_stream_t *stream, const char *mode);
static int jpc_bitstream_getbit(jpc_bitstream_t *bitstream);
static int jpc_bitstream_inalign(jpc_bitstream_t *bitstream, int filldata, int fillmask);
static void jpc_bitstream_close(jpc_bitstream_t *bitstream);
static int jpc_bitstream_getbits(jpc_bitstream_t *bitstream, int n);
static jpc_tagtreenode_t *jpc_tagtree_getleaf(jpc_tagtree_t *tree, int n);
static int jpc_tagtree_decode(jpc_tagtree_t *tree, jpc_tagtreenode_t *leaf, int threshold, jpc_bitstream_t *in);
static jpc_dec_seg_t *jpc_seg_alloc(void);
static void jpc_seglist_insert(struct { jpc_dec_seg_t *tail; } *list, jpc_dec_seg_t *pos, jpc_dec_seg_t *seg);
static int jas_getdbglevel(void);
static jas_stream_t *jas_stream_memopen(char *buf, int bufsize);
static int jas_stream_gobble(jas_stream_t *in, int n);