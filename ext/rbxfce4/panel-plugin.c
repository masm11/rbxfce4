#include <ruby.h>
#include <rbgobject.h>
#include <libxfce4panel/libxfce4panel.h>

static VALUE rbxfce4_register(VALUE self, VALUE rargv)
{
    if (!rb_block_given_p())
	rb_raise(rb_eArgError, "Expected block");
    
    static char *argv[128];
    int i, argc = 0;
    argv[argc++] = "test.rb";
    for (i = 0; ; i++) {
	VALUE v = rb_ary_entry(rargv, i);
	if (TYPE(v) == T_NIL)
	    break;
	argv[argc++] = StringValuePtr(v);
    }
    argv[argc] = NULL;
    
    for (i = 0; argv[i] != NULL; i++)
	fprintf(stderr, "%s\n", argv[i]);
    
    rbxfce4_main(argc, argv);
    
    return Qnil;
}

static void initialize(VALUE self)
{
    fprintf(stderr, "panel-plugin.initialize\n");
}

void init_panel_plugin(void) {
//  mXfce4 = rb_const_get(rb_cObject, rb_intern("Xfce4"));
    VALUE mXfce4 = rb_define_module("Xfce4");
    VALUE mGtk = rb_define_module("Gtk");
    
    rb_define_module_function(mXfce4, "register", rbxfce4_register, 1);
    
    VALUE cPanelPlugin = rb_define_class_under(mXfce4, "PanelPlugin", rb_const_get(mGtk, rb_intern("EventBox")));
    rb_define_method(cPanelPlugin, "initialize", initialize, 0);
//  rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
//  rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
//  rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
