Target = game

CXX = g++

CXXFLAGS = -std=c++11 -g -ggdb

SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/*.o)
rm = rm -f

$(Target): $(OBJECTS)
	@$(CXX) $(OBJECTS) $(CXXFLAGS) -o $@
	@echo "Linkin complete!"
$(OBJECTS):	$(OBJDIR)/%.o | $(OBJDIR): $(SRCDIR)/%.cpp 
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup Complete!"
remove:	clean
	@$(rm) $(Target)
	@echo "Executable removed!"
