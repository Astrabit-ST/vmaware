# frozen_string_literal: true

require "mkmf"

ext_vmaware_path = File.dirname(__FILE__)
wrapper_path = File.join(ext_vmaware_path, "../vmaware_wrapper")

unless Gem.win_platform?
  `g++ -O3 -c #{wrapper_path}/vmaware_wrapper.cpp -o #{wrapper_path}/vmaware_wrapper.o -fPIC`
  `ar rvs #{wrapper_path}/libvmaware_wrapper.a #{wrapper_path}/vmaware_wrapper.o`
else
  # https://gist.github.com/jsancheznet/23b1fc8c592455f1bb84
  `cl /O2 /c /EHsc #{wrapper_path}/vmaware_wrapper.cpp`
  `lib /OUT:#{wrapper_path}/vmaware_wrapper.lib #{wrapper_path}/vmaware_wrapper.obj`
end

found_wrapper = find_library("vmaware_wrapper", nil, wrapper_path)
raise "Failed to find wrapper" unless found_wrapper

create_makefile("vmaware/vmaware")
