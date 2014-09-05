export

PHONY := all
all: base_unlint.o m test

m: m.o base_unlint.o
	$(Q)$(call P,LINK,$@)$(CXX) $^ $(LFLAGS) -o $@

PHONY += test
test:
	$(MAKE) $(MFLAGS) -C test-suite

PHONY += clean
clean:
	$(RM) `find . -regex '.*\.\(o\|dep-s\)$$'`

PHONY += mrproper
mrproper: clean
	$(RM) m test

.PHONY: $(PHONY)

-include $(shell ls | egrep ".c$$|.cpp$$" | sed "s/$$/.dep-s/")

%.o: %.c
	$(Q)$(call P,CC,$@)$(CC) $< $(CXXFLAGS) -o $@

%.o: %.cpp
	$(Q)$(call P,CXX,$@)$(CXX) $< $(CXXFLAGS) -o $@

%.dep-s:
	@ echo -n "$@ " > $@
	@$(call P,CC,$@)$(CC) -MM $* >> $@