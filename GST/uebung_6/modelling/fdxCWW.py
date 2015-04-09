
from modeller.automodel import *   # Load the automodel class

log.verbose()                       # request verbose output
env = environ() # create a new MODELLER environment to build this model in

# directories for input atom files
env.io.atom_files_directory = './:./atom_files'

a = automodel(env,
              alnfile  = 'fdxCWW.pir', # alignment filename
              knowns   = ('1fxd', '1fdn'),  # codes of the templates
              sequence = 'ferodoxM')         # code of the target

#a.auto_align() # get an automatic alignment
a.starting_model=2
a.ending_model=2

a.make()       # do the actual homology modelling
