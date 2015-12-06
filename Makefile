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
