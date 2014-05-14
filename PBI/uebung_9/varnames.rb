#!/usr/bin/ruby
# This small example script is meant to be corrected. Some of the variable
# identifiers do not follow the rules of Ruby and/or do not follow the Ruby
# naming conventions.
# Additionally add comments to the identifiers to classify them as either
# *name
# *global
# *function
# *classname
# *instance variable
# *class variable

class Humanbeing
  #counts the number of instances created
  @@HBCOUNTER = 0
  def initialize
    @@HBCOUNTER += 1
  end
  #getter function
  def name
    return @name_1 + " " + @name_2
  end
  #setter functions
  def firstname(name)
    @name_1 = name
  end
  def secondname(name)
    @name_2 = name
  end
end

person = Humanbeing.new

person.firstname("Peter")
person.secondname("Petersen")

puts person.name
