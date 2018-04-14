Target = game
INCLUDES = Includes
CXX = g++
DRIVER = src/game.cpp
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)

SRCDIR = src
OBJDIR = obj

SOURCES := $(filter-out $(DRIVER), $(wildcard $(SRCDIR)/*.cpp))
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm = rm -f

$(Target):	$(DRIVER)  $(OBJECTS) $(INCLUDES)/*.hpp
	@echo "Linkin Files: " $(OBJECTS) $(DRIVER)
	@$(CXX) $(OBJECTS) $(DRIVER)  $(CXXFLAGS) -o $@
	
	@echo "Linkin complete!"
$(OBJECTS):	$(SOURCES) | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
#	@$(rm) $(OBJECTS)
	rm $(Target)
	@echo "Cleanup Complete!"
remove:	clean
	@$(rm) $(Target)
	@echo "Executable removed!"
