Target = game
INCLUDES = Includes
CXX = g++
DRIVER = src/game.cpp
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)

SRCDIR = src
OBJDIR = obj

SOURCES := $(filter-out $(DRIVER), $(wildcard $(SRCDIR)/*.cpp))
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(Target):	$(DRIVER)  $(OBJECTS) $(INCLUDES)/*.hpp
	@echo "Linkin Files: " $(OBJECTS) $(DRIVER)
	@$(CXX) $(OBJECTS) $(DRIVER)  $(CXXFLAGS) -o $@
	
	@echo "Linkin complete!"
$(OBJECTS):	$(SOURCES) | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiling Files $< to  $@ "
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	@rm -r $(OBJDIR)
	@rm $(Target)
	@echo "Cleanup Complete!"
#remove:	clean
#	@rm $(Target)
#	@echo "Executable removed!"
