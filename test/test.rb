#!/usr/bin/env ruby

require 'gtk2'
require 'rbxfce4'

p ARGV

# Xfce4::register

class Test < Xfce4::PanelPlugin
  def initialize
    super()
    p 'Test'
  end
end

Test.new

Xfce4::register(ARGV) do |xpp|
  p "back!\n"
end
