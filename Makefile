#

all:
	rake clean
	rake compile

	rm rbxfce4-*.gem
	gem build rbxfce4.gemspec

	rm -fr $HOME/.gem/ruby/2.2.0/gems/rbxfce4-*
	rm -fr $HOME/.gem/ruby/2.2.0/extensions/x86_64-linux/2.2.0/rbxfce4-0.0.1/rbxfce4/rbxfce4.so
	gem install ./rbxfce4-0.0.1.gem
