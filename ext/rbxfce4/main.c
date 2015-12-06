#include <ruby.h>
#include <libxfce4panel/libxfce4panel.h>

static void construct_func(void)
{
}

#define main _main
XFCE_PANEL_PLUGIN_REGISTER_EXTERNAL(construct_func)
#undef main

static VALUE rbxfce4_register(void)
{
    return Qnil;
}

void
Init_rbxfce4(void) {
    VALUE mXfce4;

//  mXfce4 = rb_const_get(rb_cObject, rb_intern("Xfce4"));
    mXfce4 = rb_define_module("Xfce4");

    rb_define_module_function(mXfce4, "register", rbxfce4_register, 0);
//  rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
//  rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
//  rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
