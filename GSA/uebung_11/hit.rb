class Hit 
  def initialize (string)
    parsed = string.match(/([\w]*)[\s]*([\w]*)/)
    @i = parsed.values_at(1).pop
    @j = parsed.values_at(2).pop
  end
  def get_i()
    return @i.to_i
  end
  def get_j()
    return @j.to_i
  end
end
