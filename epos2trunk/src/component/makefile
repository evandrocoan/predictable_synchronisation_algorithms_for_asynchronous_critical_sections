# EPOS Components Makefile

include ../../makedefs

OBJS := $(subst .cc,.o,$(shell find *.cc | grep -v _test | grep -v _init))
INITS := $(subst .cc,.o,$(shell find *.cc | grep _init))

all:
	${MAKE} all_multithread -j$(NPROCS)

all_multithread: $(LIBSYS) $(LIBINIT)

$(LIBSYS):	$(LIBSYS)($(OBJS))

$(LIBINIT):	$(LIBINIT)($(INITS))

clean:
		$(CLEAN) *.o *_test
