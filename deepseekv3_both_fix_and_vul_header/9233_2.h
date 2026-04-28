#include <stdlib.h>

struct Trie {
    void (*destroy)(void *);
    void *data;
};

struct SSLSupport {
    int enabled;
    int force;
    void *sslContext;
    char *sniCertificatePattern;
    int generateMissing;
    int renegotiationCount;
    struct Trie sniContexts;
};

int serverSupportsSSL(void);
void initTrie(struct Trie *trie, void (*destroy)(void *), void *data);
void sslDestroyCachedContext(void *);