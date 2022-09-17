#run make fclean in all directories

SUBDIRS := $(wildcard */ex*/.)

all: $(SUBDIRS)
$(SUBDIRS):
		$(MAKE) fclean -C $@

.PHONY: all $(SUBDIRS)