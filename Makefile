Target = game
INCLUDES = Includes
CXX = g++
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)
TEXT = historico.txt
SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(OBJECTS) $(INCLUDES)/*.hpp
	@echo "Linkin Files: " $(OBJECTS) $(DRIVER)
	@$(CXX) $(OBJECTS) $(DRIVER)  $(CXXFLAGS) -o $(Target)
	@echo "Linkin complete!"
	@echo "Generating Documentation"
	@doxygen Doxyfile
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Sources $<" 
	@echo "Compiling Files $< to  $@ "
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean clean_txt
clean: $(TEXTS)
	@rm -r $(OBJDIR)
	@rm -r html latex
	@rm $(Target)
	@echo "Cleanup Complete!"
clean_txt: $(TEXT)
	@rm $(TEXT)
