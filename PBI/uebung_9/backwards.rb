#!/usr/bin/ruby

# Default fine name, 
filename = 'testfile'

# falls wir was anderes lesen sollten 
if (newfilename = ARGV.at(0))
  # aendern wir auch den filename
  filename = newfilename
end 


begin
  
  # initialize cache array
  content = Array.new
  
  # read new file
  file = File.new(filename, "r")
  file.each_line {|line|
    # reverse string sofort
    content.push line.reverse!
  }  
  file.close
  # reverse array with zeilen
  content.reverse!

  # geben wir jetzt die Zeilen aus
  content.each {
    |string| puts string  
  }

# falls was falsch gelaufen hast, zeigen wir das
rescue => err
    puts "Exception: #{err}"
    err
end
