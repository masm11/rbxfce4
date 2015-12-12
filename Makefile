#

all:
	rake clean
	rake compile

	rm rbxfce4-*.gem
	gem build rbxfce4.gemspec

	gem uninstall rbxfce4
	rm -fr $(HOME)/.gem/ruby/2.2.0/gems/rbxfce4-*
	rm -fr $(HOME)/.gem/ruby/2.2.0/extensions/x86_64-linux/2.2.0/rbxfce4-*
	gem install ./rbxfce4-*.gem

gtk:
	cd $(HOME)/work/ruby-gnome2/gtk2 && \
	rm -f gtk2-*.gem && \
	gem build gtk2.gemspec && \
	gem uninstall --ignore-dependencies gtk2 && \
	rm -fr $(HOME)/.gem/ruby/2.2.0/gems/gtk2-* && \
	rm -fr $(HOME)/.gem/ruby/2.2.0/extensions/x86_64-linux/2.2.0/gtk2-* && \
	gem install ./gtk2-*.gem && \
	cd $(HOME)/.gem/ruby/2.2.0/gems/gtk2-*/ext/gtk2 && cp -i rbgdk.h rbgdkconversions.h rbgtk.h rbgtkconversions.h rbgtkmacros.h $(HOME)/.gem/ruby/2.2.0/extensions/x86_64-linux/2.2.0/gtk2-*/
