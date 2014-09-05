export

PHONY := all
all: ../test

../test: main.o gen.o test.o usefull.o ../base_unlint.o
	$(Q)$(call P,LINK,$@)$(CXX) $^ $(LFLAGS) -o $@

.PHONY: $(PHONY)

-include $(shell ls | egrep ".c$$|.cpp$$" | sed "s/$$/.dep-s/")

%.o: %.c
	$(Q)$(call P,CC,$@)$(CC) $< $(CXXFLAGS) -o $@

%.o: %.cpp
	$(Q)$(call P,CXX,$@)$(CXX) $< $(CXXFLAGS) -o $@

%.dep-s:
	@ echo -n "$@ " > $@
	@$(call P,CC,$@)$(CC) -MM $* >> $@