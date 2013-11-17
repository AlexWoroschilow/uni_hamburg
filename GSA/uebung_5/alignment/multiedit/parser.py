class MultieditParser:
    
    string = None
    
    def __init__(self, string):
        self.string = string
        return None
    
    def count(self):
        if self.string != None :
            return self.string[1:]
        return None
    
    def type(self):
        if self.string != None :
            return self.string[0:1]
        return None
    
    def __repr__(self):
        if self.string != None :
            return self.string
        return ''