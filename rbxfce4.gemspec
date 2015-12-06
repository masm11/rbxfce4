Gem::Specification.new do |s|
  s.name	= 'rbxfce4'
  s.version	= '0.0.1'
  s.summary	= 'ruby binding for xfce4'
  s.description	= 'ruby binding for xfce4, only xfce4-panel'
  s.authors	= ['Yuuki Harano']
  s.email	= 'masm@masm11.ddo.jp'
  s.files	= [ 'README.md', 'COPYING', 'Rakefile',
                    'ext/rbxfce4/extconf.rb',
                    'ext/rbxfce4/main.c', 'ext/rbxfce4/panel-plugin.c',
                    'lib/rbxfce4.rb' ]
  s.extensions  = 'ext/rbxfce4/extconf.rb'
  s.homepage	= 'https://github.com/masm11/rbxfce4'
  s.license	= 'GPL'
  s.add_runtime_dependency 'gtk2', '~> 3.0', '>= 3.0.7'
end
