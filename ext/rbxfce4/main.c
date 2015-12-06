#include <ruby.h>
#include <libxfce4panel/libxfce4panel.h>

static void construct_func(XfcePanelPlugin *plugin)
{
    rb_yield_values(0);
}

#define main rbxfce4_main
XFCE_PANEL_PLUGIN_REGISTER_EXTERNAL(construct_func)
#undef main

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

void
Init_rbxfce4(void) {
    VALUE mXfce4;
    
//  mXfce4 = rb_const_get(rb_cObject, rb_intern("Xfce4"));
    
    mXfce4 = rb_define_module("Xfce4");
    rb_define_module_function(mXfce4, "register", rbxfce4_register, 1);
    
    init_panel_plugin();
    
//  rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
//  rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
//  rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
