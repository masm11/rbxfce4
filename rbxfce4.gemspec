Gem::Specification.new do |s|
  s.name	= 'rbxfce4'
  s.version	= '0.0.1'
  s.summary	= 'ruby binding for xfce4'
  s.description	= 'ruby binding for xfce4'
  s.authors	= ['Yuuki Harano']
  s.email	= 'masm@masm11.ddo.jp'
  s.files	= [ 'README.md', 'COPYING',
                    'lib/mxmms/version.rb',
                    'lib/mxmms/backend.rb', 'lib/mxmms/gui.rb' ]
#  s.homepage	= 'https://github.com/masm11/mxmms'
  s.license	= 'GPL'
  s.add_runtime_dependency 'gtk2', '~> 3.0', '>= 3.0.7'
end
