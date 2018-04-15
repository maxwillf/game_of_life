Target = game
INCLUDES = Includes
CXX = g++
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)

SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(Target): $(OBJECTS) $(INCLUDES)/*.hpp
	@echo "Linkin Files: " $(OBJECTS) $(DRIVER)
	@$(CXX) $(OBJECTS) $(DRIVER)  $(CXXFLAGS) -o $@
	@echo "Linkin complete!"
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Sources $<" 
	@echo "Compiling Files $< to  $@ "
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	@rm -r $(OBJDIR)
	@rm $(Target)
	@echo "Cleanup Complete!"
