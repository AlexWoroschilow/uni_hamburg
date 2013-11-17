from parser import MultieditParser

class Multiedit:
    
    parser = None

    
    def __init__(self, string):
        self.parser = MultieditParser(string)


    def is_insert(self):
        if self.parser.type() is 'I':
            return True
        return False

    def is_replace(self):
        if self.parser.type() is 'R':
            return True
        return False

    def is_delete(self):
        if self.parser.type() is 'D':
            return True
        return False
        
    def get_type (self):
        return self.parser.type()

    
    def get_count(self):
        return int(self.parser.count())

    
    def __repr__(self):
        return self.parser.string
