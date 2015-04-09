
from modeller.automodel import *   # Load the automodel class

log.verbose()                       # request verbose output
env = environ() # create a new MODELLER environment to build this model in

# directories for input atom files
env.io.atom_files_directory = './:./atom_files'

a = automodel(env,
              alnfile  = 'fdxhomologs.pir', # alignment filename
              knowns   = ('1fxd', '1fdn'),  # codes of the templates
              sequence = 'ferodox')         # code of the target

a.auto_align() # get an automatic alignment

a.make()       # do the actual homology modelling

