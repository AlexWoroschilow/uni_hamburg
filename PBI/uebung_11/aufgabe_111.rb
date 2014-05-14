#!/usr/bin/ruby
require 'optparse'

optionen = Hash.new
optionen['echo'] = false
optionen['selecttop'] = nil
optionen['search'] = nil

OptionParser.new do |opts|
  
  opts.banner = "Usage: #{$0} [options] inputfile"

  opts.on("--selecttop", "--selecttop <entry>[,<entry>] ", "Genbank-Toplevel-Identifier. Mehrere Bezeichner werden durch Kommata getrennt.") do |selecttop|
    optionen['selecttop'] = selecttop
  end
  
  opts.on("--echo", "Echo-Modus soll verwendet werden") do |echo|
    optionen['echo'] = echo
  end
  
  opts.on("--search", "--search <regexp>", "Search-Modus soll mit dem angegebenen regulaeren Ausdruck verwendet weren.") do |search|
    if (optionen['echo'] != nil)
      raise 'Mand darf nicht "--echo" und "--search" zusammen benutzen'              
    end
    optionen['search'] = search
  end
  
end.parse!


p optionen
