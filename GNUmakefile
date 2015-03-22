# -*- Makefile -*-

#
# step #1 - system specific compilers, setttings etc
#

OSTYPE := $(shell uname -s)

#
#
#

ifeq ($(CONFIG),) # not defined

include build/GNUmakefile.config # default is debug

endif


#
# external libraries
#

LOCAL_INCLUDE =

#
# utilities
#

ECHO := /bin/echo

#
# defines
#

DEFS  :=

#
# compiler flags, dependncy generation and implicit build rules
#

-include build/GNUmakefile.compiler
-include build/GNUmakefile.ABI
-include build/GNUmakefile.depends
-include build/GNUmakefile.rules

#
# sources, objects and targets
#
# object files - done by string substitution
#

SRCS_ITINC := main.cpp
OBJS_ITINC := $(addsuffix .o, $(basename $(SRCS_ITINC)))	
DEPS_ITINC := $(addsuffix .d, $(basename $(SRCS_ITINC)))

OBJS := $(OBJS_ITINC)
DEPS := $(DEPS_ITINC)

# all targets

ITINC := itinc

.PHONY: all tags dox clean realclean

all: $(ITINC)

$(ITINC): $(OBJS_ITINC)
	$(LD) $(LDFLAGS) -o $@ $(wordlist 1,10000000,$^) -L/usr/local/lib $(SYSLIB)	

#dependencies
-include $(DEPS)

tags:
	@(find . -name "*.h" -print | etags -)
	@(find . -name "*.cpp" -print | etags -a -)
	@(find . -name "*.cc" -print | etags -a -)
	@/bin/echo "TAGS updated"

dox:
	doxygen

clean:
	-rm -rf $(ITINC)
	-rm -rf $(OBJS)

realclean:
	-rm -rf $(ITINC)
	-rm -rf $(OBJS)
	-rm -rf $(DEPS)
	-rm -rf TAGS
