from parser.alignment import Parser

class Alignment:
    
    parser = None
    
    
    def __init__(self, string):
        self.parser = Parser(string)
    
    
    def reset(self):
        return self.parser.reset() 
    
    
    def get_string(self):
        self.parser.get_string()
    
                 
    def set_string(self, value):
        self.parser.set_string(value)
    
        
    def add (self, type, count):
        if self.parser.is_valid_type(type) :
            return self.parser.add_multiedit(type, count)
        return False;
    
    
    def get_multiedit(self):
        return self.parser.get_next() 
    
        
    def __repr__(self):
        return self.get_string()