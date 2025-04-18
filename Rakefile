# frozen_string_literal: true

require "rake/extensiontask"

task build: :compile

Rake::ExtensionTask.new("vmaware") do |ext|
  ext.lib_dir = "lib/vmaware"
end

task default: %i[clobber compile]
