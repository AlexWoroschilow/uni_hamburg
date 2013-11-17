from parser import MultieditParser

class Multiedit:
    
    parser = None
    
    def __init__(self, string):
        self.parser = MultieditParser(string)
        
    def get_type (self):
        return self.parser.type()
    
    def get_count(self):
        return int(self.parser.count())
    
    def __repr__(self):
        return self.parser.string
