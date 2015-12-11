require 'gtk2'

module Xfce4

  VERSION = "0.0.1"

  @xpp_atom = nil
  @xpp_bg_image = nil
  @xpp_bg_style = 0

  def register  # construct_func
    if ARGV.size < 7
      ::GLib::critical("Not enough arguments are passed to the plugin");
      return
    end

    @xpp_atom = Gdk::Atom::intern('XFCE4_PANEL_PLUGIN_46');
    socket_id = ARGV[2].to_i
    plug = Gtk::Plug.new(socket_id)
    plug.name = 'XfcePanelWindowExternal'
    plug.signal_connect('embedded') do
      # _xpp_plug_embedded
    end
    plug.signal_connect('expose-event') do
      # _xpp_expose_event
    end
    
    plug.app_paintable = true

    screen = plug.screen
    colormap = screen.rgba_colormap
    if colormap
      plug.colormap = colormap
    end

    unique_id = ARGV[1].to_i
    xpp = Xfce4::PanelPlugin.new(
      ARGV[3],    # name
      unique_id,
      ARGV[4],    # display_name
      ARGV[5],    # comment
      ARGV[7..ARGV.size - 7])
    plug.add xpp
    xpp.signal_connect_after('realize', plug) do |w, plug|
      # _xpp_realize
    end
    xpp.signal_connect_after('destroy') do
      # _xpp_quit_main_loop
    end
    xpp.show

    if ARGV[6].length > 0
      @xpp_bg_image = ARGV[6]
      @xpp_bg_style = 2
    end

    plug.signal_connect('client-event', xpp) do |w, xpp|
      # _xpp_client_event
    end
    plug.show

    Gtk::main

    # cleanup.

    return 0
  end
  module_function :register
  
end

require "rbxfce4/rbxfce4"
