#!/usr/bin/env ruby

require "mkmf"

pkg_config('libxfce4panel-1.0')

require 'glib2'
require 'gtk2'
print "#{$LOAD_PATH}\n"
$LOAD_PATH.each do |dir|
  if /\/extensions\// =~ dir
    $INCFLAGS << " -I#{dir}"
  end
end

create_makefile 'rbxfce4/rbxfce4'
