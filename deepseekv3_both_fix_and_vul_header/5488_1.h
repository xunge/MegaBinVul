struct crypto_template;
struct crypto_template *__crypto_lookup_template(const char *name);
int try_then_request_module(int err, const char *name, ...);