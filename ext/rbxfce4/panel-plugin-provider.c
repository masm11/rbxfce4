#include "global.h"

#define RG_TARGET_NAMESPACE cPanelPluginProvider
#define _SELF(self) XFCE_PANEL_PLUGIN_PROVIDER(RVAL2GOBJ(self))

static VALUE rg_initialize(int argc, VALUE *argv, VALUE self)
{
    fprintf(stderr, "panel-plugin-provider.rg_initialize\n");
    
    // argc=0 だった…
    fprintf(stderr, "panel-plugin-provider.rg_initialize: argc=%d\n", argc);
    for (int i = 0; i < argc; argc++) {
	if (TYPE(argv[i]) == T_STRING)
	    fprintf(stderr, "panel-plugin-provider.rg_initialize: argv[%d]=%s\n", i, RVAL2CSTR(argv[i]));
	else
	    fprintf(stderr, "panel-plugin-provider.rg_initialize: argv[%d]=unknown\n", i);
    }

    // ruby 上で new しないなら、不要?
    // でも↓これは要るだろう...

    // RBGTK_INITIALIZE(self, widget);

    fprintf(stderr, "panel-plugin-provider.rg_initialize: done.\n");
    return Qnil;
}

static VALUE rg_name(VALUE self)
{
    return CSTR2RVAL(xfce_panel_plugin_provider_get_name(_SELF(self)));
}

void Init_panel_plugin_provider(VALUE mXfce4, VALUE mGtk) {
    VALUE RG_TARGET_NAMESPACE = G_DEF_CLASS(XFCE_TYPE_PANEL_PLUGIN, "PanelPluginProvider", mXfce4);
    
    RG_DEF_METHOD(initialize, -1);
    RG_DEF_METHOD(name, 0);

    // rb_define_module_function(mXfce4, "register", rbxfce4_register, 1);
    
//    VALUE cPanelPlugin = rb_define_class_under(mXfce4, "PanelPlugin", rb_const_get(mGtk, rb_intern("EventBox")));
//  rb_define_method(cPanelPlugin, "initialize", initialize, 0);
//  rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
//  rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
//  rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
