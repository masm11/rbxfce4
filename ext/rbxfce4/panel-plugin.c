#include "global.h"

#define RG_TARGET_NAMESPACE cPanelPlugin
#define _SELF(self) XFCE_PANEL_PLUGIN(RVAL2GOBJ(self))

static VALUE rg_initialize(int argc, VALUE *argv, VALUE self)
{
    fprintf(stderr, "panel-plugin.rg_initialize\n");
    
    RBGTK_INITIALIZE(self, widget);

    fprintf(stderr, "panel-plugin.rg_initialize: done.\n");
    return Qnil;
}

void Init_panel_plugin(VALUE mXfce4, VALUE mGtk) {
    VALUE RG_TARGET_NAMESPACE = G_DEF_CLASS(XFCE_TYPE_PANEL_PLUGIN, "PanelPlugin", mXfce4);
    
    RG_DEF_METHOD(initialize, -1);

    // rb_define_module_function(mXfce4, "register", rbxfce4_register, 1);
    
//    VALUE cPanelPlugin = rb_define_class_under(mXfce4, "PanelPlugin", rb_const_get(mGtk, rb_intern("EventBox")));
//  rb_define_method(cPanelPlugin, "initialize", initialize, 0);
//  rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
//  rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
//  rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
