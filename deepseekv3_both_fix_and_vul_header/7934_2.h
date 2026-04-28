typedef struct {
    int meths_count;
} srv_ext_st;

typedef struct {
    srv_ext_st srv_ext;  // Changed from pointer to direct struct
} cert_st;

typedef struct {
    int hit;
    cert_st *cert;
} SSL;

#define n2s(c,s) ((s=(((unsigned int)(c[0]))<< 8)| \
                   (((unsigned int)(c[1]))    )),c+=2)

int custom_ext_parse(SSL *s, int server, unsigned short type,
                    const unsigned char *data, unsigned short size, int *al);