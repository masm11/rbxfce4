#include "global.h"

#define RG_TARGET_NAMESPACE cPanelPlugin
#define _SELF(self) XFCE_PANEL_PLUGIN(RVAL2GOBJ(self))

static VALUE rg_initialize(int argc, VALUE *argv, VALUE self)
{
    GtkWidget *widget;
    
    fprintf(stderr, "panel-plugin.rg_initialize\n");
    
    fprintf(stderr, "panel-plugin.rg_initialize: argc=%d\n", argc);
    
    const char *name = RVAL2CSTR(argv[0]);
    fprintf(stderr, "panel-plugin.rg_initialize: name=%s\n", name);
    
    int unique_id = NUM2INT(argv[1]);
    fprintf(stderr, "panel-plugin.rg_initialize: unique_id=%d.\n", unique_id);
    
    const char *display_name = RVAL2CSTR(argv[2]);
    fprintf(stderr, "panel-plugin.rg_initialize: display_name=%s\n", display_name);
    
    const char *comment = RVAL2CSTR(argv[3]);
    fprintf(stderr, "panel-plugin.rg_initialize: comment=%s\n", comment);
    
    static char *args[] = { NULL, }; // fixme: 仮
    widget = g_object_new(XFCE_TYPE_PANEL_PLUGIN,
	    "name", name,
	    "unique-id", unique_id,
	    "display-name", display_name,
	    "comment", comment,
	    "arguments", args, NULL);
    
    RBGTK_INITIALIZE(self, widget);
    
    fprintf(stderr, "panel-plugin.rg_initialize: done.\n");
    return Qnil;
}

static VALUE rg_name(VALUE self)
{
    return CSTR2RVAL(xfce_panel_plugin_get_name(_SELF(self)));
}

void Init_panel_plugin(VALUE mXfce4, VALUE mGtk) {
    VALUE RG_TARGET_NAMESPACE = G_DEF_CLASS(XFCE_TYPE_PANEL_PLUGIN, "PanelPlugin", mXfce4);
    
    RG_DEF_METHOD(initialize, -1);
    RG_DEF_METHOD(name, 0);

    // rb_define_module_function(mXfce4, "register", rbxfce4_register, 1);
    
//    VALUE cPanelPlugin = rb_define_class_under(mXfce4, "PanelPlugin", rb_const_get(mGtk, rb_intern("EventBox")));
//  rb_define_method(cPanelPlugin, "initialize", initialize, 0);
//  rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
//  rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
//  rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
