typedef unsigned long VALUE;

extern VALUE rb_define_module(const char *name);
extern VALUE rb_define_module_under(VALUE parent, const char *name);
extern VALUE rb_define_class_under(VALUE parent, const char *name, VALUE super);
extern void rb_define_singleton_method(VALUE klass, const char *name, VALUE (*func)(), int argc);
extern void rb_define_private_method(VALUE klass, const char *name, VALUE (*func)(), int argc);

VALUE cNokogiriXmlSchema;
VALUE rb_cObject;

VALUE read_memory(VALUE self, VALUE str);
VALUE from_document(VALUE self, VALUE doc);
VALUE validate_document(VALUE self, VALUE doc);
VALUE validate_file(VALUE self, VALUE filename);