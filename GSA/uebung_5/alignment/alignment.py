from validator import Validator
from string.sequenz import Sequenz as SequenzString
from string.alignment import Alignment as AlignmentString
from multiedit.multiedit import Multiedit

class Alignment:
    
    cost = None
    alignment = None
    sequenz1 = None
    sequenz2 = None
    
    def __init__(self, cost, sequenz1, sequenz2, alignment):
        self.cost = cost
        self.sequenz1 = SequenzString(sequenz1)
        self.sequenz2 = SequenzString(sequenz2)
        self.alignment = AlignmentString(alignment) 

    # Create new instance of alignments 
    # with two sequenz strings and empty alignment string        
    def alignment_new(self):
        return Alignment(self.cost, self.sequenz1.get_string(), self.sequenz2.get_string(), '')
    
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
        if self.sequenz1 != None :
            if self.sequenz2 != None :
                list1 = list()
                list2 = list()
                list3 = list()
                self.sequenz1.reset()
                self.sequenz2.reset()
                self.alignment.reset()
                multiedit_string = self.alignment.get_multiedit();
                while multiedit_string :
                    multiedit = Multiedit(multiedit_string)
                    
                    for i in range(0, multiedit.get_count()):
                        if multiedit.is_insert() :
                            char2 = self.sequenz2.get_next()
                            list1.append('-')
                            list2.append('-' if char2 == None else char2)
                            list3.append(' ')
                        elif multiedit.is_replace() :
                            char1 = self.sequenz1.get_next()
                            char2 = self.sequenz2.get_next()
                            list1.append('-' if char1 == None else char1)
                            list2.append('-' if char2 == None else char2)
                            list3.append('|' if char1 == char2 else ' ')
                        elif multiedit.is_delete() :
                            char1 = self.sequenz1.get_next()
                            list1.append('-' if char1 == None else char1)
                            list2.append('-')
                            list3.append(' ')
                         
                    multiedit_string = self.alignment.get_multiedit();
                return "%s\n%s\n%s\n" % (''.join(list1), ''.join(list3), ''.join(list2))

    
    def alignment_evalcost(self):
        if self.sequenz1 != None :
            if self.sequenz2 != None :
                const = 0
                self.sequenz1.reset()
                self.sequenz2.reset()
                self.alignment.reset()
                multiedit_string = self.alignment.get_multiedit();
                while multiedit_string :
                    multiedit = Multiedit(multiedit_string)
                    
                    char1 = None
                    char2 = None
                    
                    for i in range(0, multiedit.get_count()):
                        if multiedit.is_insert() :
                            char1 = None
                            char2 = self.sequenz2.get_next()
                        elif multiedit.is_replace() :
                            char1 = self.sequenz1.get_next()
                            char2 = self.sequenz2.get_next()
                        elif multiedit.is_delete() : 
                            char1 = self.sequenz1.get_next()
                            char2 = None
                
                        const = const + self.cost.get(char1, char2)
                    multiedit_string = self.alignment.get_multiedit();
                return const
        return None
    
    
    # clear values for sequenzes and 
    # alignment    
    def alignment_delete(self):
        self.sequenz1.set_string(None)
        self.sequenz2.set_string(None)
        self.alignment.set_string(None)
        return None

