#include <stddef.h>
#include <stdint.h>

#define AES_ENCRYPT     1
#define AES_DECRYPT     0
#define XYSSL_PADLOCK_C
#define XYSSL_HAVE_X86

typedef struct {
    int nr;
    unsigned long *rk;
} aes_context;

extern unsigned char FSb[256];
extern unsigned char RSb[256];

#define GET_ULONG_LE(n,b,i)                      \
{                                                \
    (n) = ( (unsigned long) (b)[(i)    ]       ) \
        | ( (unsigned long) (b)[(i) + 1] <<  8 ) \
        | ( (unsigned long) (b)[(i) + 2] << 16 ) \
        | ( (unsigned long) (b)[(i) + 3] << 24 ); \
}

#define PUT_ULONG_LE(n,b,i)                      \
{                                                \
    (b)[(i)    ] = (unsigned char) ( (n)       ); \
    (b)[(i) + 1] = (unsigned char) ( (n) >>  8 ); \
    (b)[(i) + 2] = (unsigned char) ( (n) >> 16 ); \
    (b)[(i) + 3] = (unsigned char) ( (n) >> 24 ); \
}

#define AES_FROUND(X0,X1,X2,X3,Y0,Y1,Y2,Y3)     \
{                                               \
    X0 = *RK++ ^ FT0[ ( Y0       ) & 0xFF ] ^   \
                 FT1[ ( Y1 >>  8 ) & 0xFF ] ^   \
                 FT2[ ( Y2 >> 16 ) & 0xFF ] ^   \
                 FT3[ ( Y3 >> 24 ) & 0xFF ];    \
                                                \
    X1 = *RK++ ^ FT0[ ( Y1       ) & 0xFF ] ^   \
                 FT1[ ( Y2 >>  8 ) & 0xFF ] ^   \
                 FT2[ ( Y3 >> 16 ) & 0xFF ] ^   \
                 FT3[ ( Y0 >> 24 ) & 0xFF ];    \
                                                \
    X2 = *RK++ ^ FT0[ ( Y2       ) & 0xFF ] ^   \
                 FT1[ ( Y3 >>  8 ) & 0xFF ] ^   \
                 FT2[ ( Y0 >> 16 ) & 0xFF ] ^   \
                 FT3[ ( Y1 >> 24 ) & 0xFF ];    \
                                                \
    X3 = *RK++ ^ FT0[ ( Y3       ) & 0xFF ] ^   \
                 FT1[ ( Y0 >>  8 ) & 0xFF ] ^   \
                 FT2[ ( Y1 >> 16 ) & 0xFF ] ^   \
                 FT3[ ( Y2 >> 24 ) & 0xFF ];    \
}

#define AES_RROUND(X0,X1,X2,X3,Y0,Y1,Y2,Y3)     \
{                                               \
    X0 = *RK++ ^ RT0[ ( Y0       ) & 0xFF ] ^   \
                 RT1[ ( Y3 >>  8 ) & 0xFF ] ^   \
                 RT2[ ( Y2 >> 16 ) & 0xFF ] ^   \
                 RT3[ ( Y1 >> 24 ) & 0xFF ];    \
                                                \
    X1 = *RK++ ^ RT0[ ( Y1       ) & 0xFF ] ^   \
                 RT1[ ( Y0 >>  8 ) & 0xFF ] ^   \
                 RT2[ ( Y3 >> 16 ) & 0xFF ] ^   \
                 RT3[ ( Y2 >> 24 ) & 0xFF ];    \
                                                \
    X2 = *RK++ ^ RT0[ ( Y2       ) & 0xFF ] ^   \
                 RT1[ ( Y1 >>  8 ) & 0xFF ] ^   \
                 RT2[ ( Y0 >> 16 ) & 0xFF ] ^   \
                 RT3[ ( Y3 >> 24 ) & 0xFF ];    \
                                                \
    X3 = *RK++ ^ RT0[ ( Y3       ) & 0xFF ] ^   \
                 RT1[ ( Y2 >>  8 ) & 0xFF ] ^   \
                 RT2[ ( Y1 >> 16 ) & 0xFF ] ^   \
                 RT3[ ( Y0 >> 24 ) & 0xFF ];    \
}

extern unsigned long FT0[256];
extern unsigned long FT1[256];
extern unsigned long FT2[256];
extern unsigned long FT3[256];
extern unsigned long RT0[256];
extern unsigned long RT1[256];
extern unsigned long RT2[256];
extern unsigned long RT3[256];

int padlock_supports(int feature);
int padlock_xcryptecb(aes_context *ctx, int mode, const unsigned char *input, unsigned char *output);
#define PADLOCK_ACE 1