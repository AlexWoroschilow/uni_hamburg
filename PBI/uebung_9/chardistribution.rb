#!/usr/bin/ruby

# Default fine name, 
filename = 'testfile'

# falls wir was anderes lesen sollten 
if (newfilename = ARGV.at(0))
  # aendern wir auch den filename
  filename = newfilename
end 


begin
  
  
  # read new file
  file = File.new(filename, "r")
  contents = file.read
  file.close
  
  
 # See String#encode
  options = {
    :invalid           => :replace,  # Replace invalid byte sequences
    :undef             => :replace,  # Replace anything not defined in ASCII
    :replace           => '',        # Use a blank for those replacements
    :universal_newline => true       # Always break lines with \n
  }
  contents.encode!(Encoding.find('ASCII'), options)
  

  
  contents.delete!("\n")
  
  contents.each {|s| p s}
  
  

# falls was falsch gelaufen hast, zeigen wir das
rescue => err
    puts "Exception: #{err}"
    err
end
