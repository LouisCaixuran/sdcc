# Work for individual tests is not parallelized although tests
# themselves may be run in parallel.
.NOTPARALLEL:

VPATH := $(srcdir)

# Include any target specifics.
-include $(srcdir)/../test-conf.mk

# Naming and target options are inconsistent so nearly all simulators
# are going to have to define things in *.src/test-conf.mk some and
# individual tests are likely to have to override on a per-target
# basis using:
#     target: CC=... SDAS=... SDLD=...
#     target: prereqs
#             recipe
TARGET ?= $(patsubst s%,%,$(notdir $(SIM)))

CC ?= sdcc -m$(TARGET)
PACKIHX ?= packihx
AS ?= sdas$(TARGET)
ASFLAGS ?= -plosgffw
LD ?= sdld$(TARGET)
LDFLAGS ?=


# When to colourize the diff output. Unless otherwise overridden we use
# "auto" normally but "always" if output is being collected because make
# is running parallel jobs.
DIFF_COLOUR ?= $(if $(findstring --jobserver, $(MAKEFLAGS)),always,auto)

# Options to diff to be used when comparing outputs to baselines. This is
# mainly used to ignore things that are expected to change. Test makefiles
# may added to this for specific cases.
DIFF_OPTS += -I '^uCsim [^,]*, Copyright '
DIFF_OPTS += -I '^ucsim version '
DIFF_OPTS += -I '^Simulated [[:digit:]]\+ ticks '
DIFF_OPTS += -I '[[:upper:]][[:alpha:]]\{2\} [[:upper:]][[:alpha:]]\{2\} .[[:digit:]] [[:digit:]]\{2\}:[[:digit:]]\{2\}:[[:digit:]]\{2\} [[:digit:]]\{4\}'


# $(call run-sim,<sim args>)
# Prerequisites of the form %.cmd are passed as command scripts
# using -e immediately after any args specified.
# Prerequisites of the form %.ihx are given as image files to load.
# Other prerequisites are ignored.
# If there are no %.cmd prequisites and -e does not appear anywhere
# in the sim args "-e run" is passed to the simulator.
define run-sim =
	$(SIM) -R 0 $(SIM_ARGS) $(1) \
		$(if $(filter %.cmd, $+), \
			-e '$(patsubst %, exec "%";, $(filter %.cmd, $+))', \
			$(if $(findstring -e, $(1)), , -g)) \
		$(filter %.ihx, $+) \
		> 'out/$@' 2>&1 < /dev/null
endef


.PHONY:	all clean _diff_to_baseline _log_test _silent

# silent is used to suppress "nothing to do" messages.
_silent:
	@echo -n

# A test produces one or more outputs which are then diff'd against
# the baseline saved in the source tree.
all:	_log_test out $(OUTPUTS) _diff_to_baseline

_log_test:
	@echo 'TEST $(srcdir)'

out:
	mkdir '$@'

# Outputs must, at least, be up to date with respect to the baseline
# output (if it exists), the main test's Makefile, test-lib.mk and the
# simulator being tested. Other dependencies and the recipe used for
# the test are in the main test's Makefile.
.PHONY: $(patsubst %,baseline/%,$(OUTPUTS))
$(OUTPUTS): %: baseline/% Makefile $(srcdir)/../../../test-lib.mk $(SIM)

# Compare the complete output with the saved baseline. If there are
# differences there is no need to report fail (the diff output is
# sufficient) but hide the error to keep make quiet and allow other
# tests to go ahead.
_diff_to_baseline:
	diff -urN --color='$(DIFF_COLOUR)' \
		$(DIFF_OPTS) \
		'$(srcdir)/baseline' 'out' \
	|| true

clean:	| _silent


MAKEDEPEND = $(CC) -MM $(CPPFLAGS) $< > $*.d.tmp

POSTCOMPILE = cp $*.d.tmp $*.d \
	&& while read line; do \
		for file in $${line\#*:}; do \
			echo "$$file:"; \
		done; \
	done < $*.d.tmp >> $*.d \
	&& rm -f $*.d.tmp


%.hex:	%.ihx
	$(PACKIHX) '$<' >'$@'

%.ihx:	%.c
	$(MAKEDEPEND)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $<
	$(POSTCOMPILE)

%.rel:	%.asm
	$(AS) $(ASFLAGS) $@ $<

%.ihx:	%.rel
	$(LD) $(LINKFLAGS) -i $@ $<


include $(wildcard *.d)