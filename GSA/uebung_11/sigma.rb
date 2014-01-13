
class Sigma
  def initialize (match, mismatch)
    @match = match
    @mismatch = mismatch
  end
  def get_cost(u,v)
    if(u == v)
      return @match
    end
    return @mismatch
  end
end
