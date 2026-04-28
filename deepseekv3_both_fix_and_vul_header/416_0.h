#include <stdio.h>
#include <string.h>

#define GF_EXPORT
typedef unsigned int u32;
typedef unsigned char u8;

#define GF_4CC(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))

#define GF_ISOM_BOX_TYPE_FTYP GF_4CC('f','t','y','p')
#define GF_ISOM_BOX_TYPE_MOOV GF_4CC('m','o','o','v')
#define GF_ISOM_BOX_TYPE_MOOF GF_4CC('m','o','o','f')
#define GF_ISOM_BOX_TYPE_STYP GF_4CC('s','t','y','p')
#define GF_ISOM_BOX_TYPE_SIDX GF_4CC('s','i','d','x')
#define GF_ISOM_BOX_TYPE_AFRA GF_4CC('a','f','r','a')
#define GF_ISOM_BOX_TYPE_ABST GF_4CC('a','b','s','t')
#define GF_ISOM_BOX_TYPE_MDAT GF_4CC('m','d','a','t')
#define GF_ISOM_BOX_TYPE_FREE GF_4CC('f','r','e','e')
#define GF_ISOM_BOX_TYPE_SKIP GF_4CC('s','k','i','p')
#define GF_ISOM_BOX_TYPE_UDTA GF_4CC('u','d','t','a')
#define GF_ISOM_BOX_TYPE_META GF_4CC('m','e','t','a')
#define GF_ISOM_BOX_TYPE_VOID GF_4CC('v','o','i','d')
#define GF_ISOM_BOX_TYPE_JP GF_4CC('j','p',' ',' ')
#define GF_QT_BOX_TYPE_WIDE GF_4CC('w','i','d','e')

#define gf_fopen fopen
#define gf_fclose fclose