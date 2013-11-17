class Parser:
    
    string = None
    string_len = None
    string_pos = None
    
    def __init__(self, string):
        self.string = string
        self.string_len = len(string) 
        self.string_pos = 0

    def reset(self):
        self.string_pos = 0
        
    def get_string(self):
        return self.string

        
    def set_string(self, value):
        self.string = None
        self.string_len = None
        self.string_pos = None
        if value != None :
            self.string = value
            self.string_len = len(value)
            self.string_pos = 0
        
        
    def get_next(self):
        if self.string_pos < self.string_len  :
            result = self.string[self.string_pos]
            self.string_pos = self.string_pos + 1
            return result
        return None