class Einheitskost:
    def __init__(self):
        return None
    
    def get(self, char1, char2):
        if char1 == None or  char2 == None :
            return 1
        if char1 == char2 :
            return 0
        return 1
