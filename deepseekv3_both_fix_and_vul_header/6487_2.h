struct crypto_tfm;

struct crypto_rng {
    int (*generate)(void);
    int (*seed)(void);
    int seedsize;
};

struct rng_alg {
    int (*generate)(void);
    int (*seed)(void);
    int seedsize;
};

struct old_rng_alg {
    int (*rng_make_random)(void);
    int seedsize;
};

static int generate;
static int rngapi_reset;

static inline struct crypto_rng *__crypto_rng_cast(struct crypto_tfm *tfm) { return (struct crypto_rng *)tfm; }
static inline struct rng_alg *crypto_rng_alg(struct crypto_rng *rng) { return (struct rng_alg *)rng; }
static inline struct old_rng_alg *crypto_old_rng_alg(struct crypto_rng *rng) { return (struct old_rng_alg *)rng; }