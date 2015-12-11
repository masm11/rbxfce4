#ifndef RBXFCE4_GLOBAL_H__INCLUDED
#define RBXFCE4_GLOBAL_H__INCLUDED

#include <ruby.h>
#include <rbgobject.h>
#include <rbgtk.h>
#include <libxfce4panel/libxfce4panel.h>

#undef RG_DEF_METHOD
#define RG_DEF_METHOD(method, argc) \
        rb_define_method(RG_TARGET_NAMESPACE, #method, rg_ ## method, argc)
#undef RG_DEF_SMETHOD
#define RG_DEF_SMETHOD(method, argc) \
        rb_define_singleton_method(RG_TARGET_NAMESPACE, #method, rg_s_ ## method, argc)

void Init_panel_plugin(VALUE mXfce4, VALUE mGtk);
void Init_panel_plugin_provider(VALUE mXfce4, VALUE mGtk);

#endif	/* ifndef RBXFCE4_GLOBAL_H__INCLUDED */
