# example makefile call: make -f mustermake <executable>
# or rename it to Makefile and just call: make <executable>

# default parameters for CFLAGS
CFLAGS=-Wall -Werror -g

# a local variable that gets set if it is not set in the environment
opt?=no

# if opt was set on the command line like this: opt=yes
# ADD '-O3' to CFLAGS
ifeq (${opt}, yes)
  CFLAGS+= -O3
endif


affinealign.x: alignment.o matrix.o
alignment.o: alignment.h
matrix.o: matrix.h

aufgabe8_3.x: EDtabcolumn.o
EDtabcolumn.o: EDtabcolumn.h


# rule for all targets that end in .x, depending on a file with the same name
# and ending .o.
# LDFLAGS is not set in this file, because it is usualy not needed. If you want
# to compile something that includes math.h you have to set LDFLAGS=-lm on the
# command line or in the makefile for that code.
# $@: automatic variable containing the targets name
# $^: automatic variable containing the dependencies of that target
%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

# rule for all targets ending in .o depending on a file with the same name
# ending in .c
# this rule is not really necessary as make has it implicit.
%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

# more complex example:
#
# one file main.c uses code from module.c which has the file module.h to make
# its functions known.
# to extend the default rules above you only need to add targets without rules
# like this:
# this adds module.h to the dependencies of main.o and module.o
main.o module.o: module.h

# this adds module.o to the dependencies of main.x
main.x: module.o
# vim: ft=make
clean:
	${RM} -rf *.o *.x *~
