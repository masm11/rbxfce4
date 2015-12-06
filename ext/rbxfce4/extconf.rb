#!/usr/bin/env ruby

require "mkmf"

pkg_config('libxfce4panel-1.0')

create_makefile 'rbxfce4/rbxfce4'
