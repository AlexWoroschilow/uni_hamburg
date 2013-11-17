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
        if self.string_pos < self.string_len :
            string = self.string[self.string_pos]
            position = self.string_pos + 1
            if position < self.string_len :
                while not self.is_valid_type(self.string[position]) :
                    position = position + 1
                    if position >= self.string_len :
                        break;
                string = self.string[self.string_pos:(position)]                
                self.string_pos = position
                return string 
        return None

            
    def add_multiedit (self, type, count):
        self.string = ''.join([self.string, ("%s%d" % (type, count))])
        self.string_len = len(self.string)
        self.string_pos = 0
        return True
    
    
    def is_valid_type(self, type):
        return type in ['D', 'R', 'I']
    
    
    def __repr__(self):
        return self.string

