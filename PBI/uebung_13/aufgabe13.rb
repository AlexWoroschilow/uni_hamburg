#!/usr/bin/ruby
require 'optparse'

class Option
  def initialize ()
    @echo = nil
    @search = nil
    @selecttop = nil
  end
  def echo?()
    return @echo != nil
  end
  def echo(value = nil)
    if(value == nil)
      return @echo
    end
    @echo = value
    return true
  end
  def search?()
    @search != nil
  end
  def search(value = nil)
    if(value == nil)
      return @search
    end
    @search = value
    return true
  end
  def selecttop(value = nil)
    if(value == nil)
      return @selecttop
    end
    @selecttop = value
    return false
  end
end


option = Option.new


OptionParser.new do |opts|
  
  opts.banner = "Usage: #{$0} [options] inputfile"

  opts.on("--selecttop", "--selecttop <entry>[,<entry>] ", "Genbank-Toplevel-Identifier. Mehrere Bezeichner werden durch Kommata getrennt.") do |selecttop|
    if (!option.selecttop(selecttop))
      raise 'Selecttop passt nicht!'              
    end
  end
  
  opts.on("--echo", "Echo-Modus soll verwendet werden") do |echo|
    if (!option.search?)
      if (!option.echo(echo))
        raise 'Echo passt nicht!'              
      end
    else
      raise 'Mand darf nicht "--echo" und "--search" zusammen benutzen'              
    end
  end
  
  opts.on("--search", "--search <regexp>", "Search-Modus soll mit dem angegebenen regulaeren Ausdruck verwendet weren.") do |search|
    if (!option.echo?)
      if (!option.search(search))
        raise 'Search string passt nicht!'              
      end
    else
      raise 'Mand darf nicht "--echo" und "--search" zusammen benutzen'              
    end
  end
  
end.parse!

puts option.echo
puts option.search
