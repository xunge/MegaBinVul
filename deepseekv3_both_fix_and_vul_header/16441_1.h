typedef unsigned long VALUE;

extern VALUE cNokogiriXmlSchema;
extern VALUE cNokogiriXmlRelaxNG;

VALUE rb_define_module(const char *name);
VALUE rb_define_module_under(VALUE parent, const char *name);
VALUE rb_define_class_under(VALUE parent, const char *name, VALUE super);
void rb_define_singleton_method(VALUE klass, const char *name, VALUE (*func)(), int argc);
void rb_define_private_method(VALUE klass, const char *name, VALUE (*func)(), int argc);

VALUE read_memory(VALUE self, VALUE str);
VALUE from_document(VALUE self, VALUE doc);
VALUE validate_document(VALUE self, VALUE doc);