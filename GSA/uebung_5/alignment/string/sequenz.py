from parser.sequenz import Parser


class Sequenz:
    
    parser = None

    def __init__(self, string):
        self.parser = Parser(string)

    def reset(self):
        return self.parser.reset() 
        
    def get_string(self):
        return self.parser.get_string()
    
                 
    def set_string(self, value):
        self.parser.set_string(value)
        
        
    def get_next(self):
        return self.parser.get_next() 
        
        
