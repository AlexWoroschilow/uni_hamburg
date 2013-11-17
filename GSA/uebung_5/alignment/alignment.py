from cost import Cost
from validator import Validator
from string.sequenz import Sequenz as SequenzString
from string.alignment import Alignment as AlignmentString

class Alignment:
    
    cost = None
    alignment = None
    sequenz1 = None
    sequenz2 = None
    
    
    def __init__(self, sequenz1, sequenz2, alignment):
        self.cost = Cost()
        self.sequenz1 = sequenz1
        self.sequenz2 = sequenz2
        self.alignment = AlignmentString(alignment) 

    # Create new instance of alignments 
    # with two sequenz strings and empty alignment string        
    def alignment_new(self):
        return Alignment(self.sequenz1, self.sequenz2, '')
    
    # Done 
    # TODO: validation 
    def alignment_add_replacement(self, count):
#         self.validator.alignment(self.alignment)
#         self.validator.sequenz1(self.sequenz1)
#         self.validator.sequenz2(self.sequenz2)
#         if self.validator.is_erlaubt('R', count) :
        return self.alignment.add('R', count)
        return False

    
    # Done 
    # TODO: validation 
    def alignment_add_deletion(self, count):
#         self.validator.alignment(self.alignment)
#         self.validator.sequenz1(self.sequenz1)
#         self.validator.sequenz2(self.sequenz2)
#         if self.validator.is_erlaubt('D', count) :
        return self.alignment.add('D', count)
        return False

    
    # Done 
    # TODO: validation 
    def alignment_add_insertion(self, count):
#         self.validator.alignment(self.alignment)
#         self.validator.sequenz1(self.sequenz1)
#         self.validator.sequenz2(self.sequenz2)
#         if self.validator.is_erlaubt('I', count) :
        return self.alignment.add('I', count)
        return False

    
    def alignment_show(self):
        result = list()
        while True :
            multiedit = self.alignment.get_multiedit();
            if multiedit == None :
                break
            result.append(multiedit)
        return '[%s]' % ', '.join(result)

    
    
    def alignment_evalcost(self):
        return None
    
    
    def alignment_delete(self):
        self.alignment = None
        self.sequenz1 = None
        self.sequenz2 = None
        return None

