from parser.alignment import Parser

class Alignment:
    parser = None
    
    def __init__(self, string):
        self.parser = Parser(string)
        
    def add (self, type, count):
        if self.parser.is_valid_type(type) :
            return self.parser.add(type, count)
        return False;
    
    def get_multiedit(self):
        if self.parser.has_next() :
            return self.parser.next() 
        return None
        
    def __repr__(self):
        return self.parser.string