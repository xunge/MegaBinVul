typedef void* VALUE;
typedef unsigned long ID;

VALUE mOSSL;
VALUE eOSSLError;
VALUE mPKey;
VALUE ePKeyError;
VALUE cPKey;
VALUE rb_cObject;
ID id_private_q;

VALUE rb_define_module_under(VALUE, const char*);
VALUE rb_define_class_under(VALUE, const char*, VALUE);
void rb_define_module_function(VALUE, const char*, void*, int);
void rb_define_alloc_func(VALUE, void*);
void rb_define_method(VALUE, const char*, void*, int);
ID rb_intern(const char*);

void Init_ossl_rsa(void);
void Init_ossl_dsa(void);
void Init_ossl_dh(void);
void Init_ossl_ec(void);

void* ossl_pkey_new_from_data;
void* ossl_pkey_alloc;
void* ossl_pkey_initialize;
void* ossl_pkey_private_to_der;
void* ossl_pkey_private_to_pem;
void* ossl_pkey_public_to_der;
void* ossl_pkey_public_to_pem;
void* ossl_pkey_sign;
void* ossl_pkey_verify;