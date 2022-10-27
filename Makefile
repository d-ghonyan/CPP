#run make fclean in all directories

SUBDIRS = $(wildcard */ex*/.)
RULE = fclean

all: $(SUBDIRS)

$(SUBDIRS):
		$(MAKE) $(RULE) -C $@

.PHONY: all $(SUBDIRS)