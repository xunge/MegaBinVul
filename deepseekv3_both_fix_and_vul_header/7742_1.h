void* mNokogiriXmlSax;
void* cNokogiriXmlSaxParserContext;
void* rb_cObject;
int id_read;

void rb_undef_alloc_func(void*);
void* rb_define_class_under(void*, const char*, void*);
void rb_define_singleton_method(void*, const char*, void*, int);
void rb_define_method(void*, const char*, void*, int);
int rb_intern(const char*);

void parse_io();
void parse_memory();
void parse_file();
void parse_with();
void set_replace_entities();
void get_replace_entities();
void set_recovery();
void get_recovery();
void line();
void column();