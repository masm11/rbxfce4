require 'gtk2'

module Xfce4

  VERSION = "0.0.1"

  class<<self
    @xpp_atom = nil
    @xpp_bg_image = nil
    @xpp_bg_style = 0
    @quitting = false
    
    def register  # construct_func
      if ARGV.size < 7
        ::GLib::critical("Not enough arguments are passed to the plugin");
        return
      end
      
      @xpp_atom = Gdk::Atom::intern('XFCE4_PANEL_PLUGIN_46');
      socket_id = ARGV[2].to_i
      plug = Gtk::Plug.new(socket_id)
      plug.name = 'XfcePanelWindowExternal'
      plug.signal_connect('embedded') do |plug|
        if !plug.embedded
          if !quitting
            quitting = true
            Gtk::main_quit
          end
        end
      end
      plug.signal_connect('expose-event') do |plug, event|
        cr = nil
        color = nil
        real_alpha = 0
        pixbuf = nil
        error = nil
        
        if !(plug.visible? && plug.mapped?)
          return false
        end
        
        if @xpp_bg_style == 2
          # fixme: cairo を使っててちょっと面倒いんで、後回し。
        end
        
        false
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
      signal_realize_id = xpp.signal_connect_after('realize', plug) do |xpp, plug|
        xpp.signal_handler_disconnect signal_realize_id
        xpp.signal_connect('provider-signal', plug) do |xpp, plug|
          # _xpp_provider_signal
        end
        
        if block_given?
          yield xpp
        end
        
        ebox = xpp.child
        if ebox && ebox.is_a?(Gtk::EventBox)
          ebox.visible_window = false
        end
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
  end
  
end

require "rbxfce4/rbxfce4"
