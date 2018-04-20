Target = game
INCLUDES = Includes
CXX = g++
CXXFLAGS = -std=c++11 -g -ggdb -I $(INCLUDES)
TEXT = $(filter historico.txt, $(wildcard *.txt)) # If no file generates nothing
DOCS = html latex
SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: project docs
project: $(OBJECTS) $(INCLUDES)/*.hpp
	@echo "Linkin Files: " $(OBJECTS) $(DRIVER)
	@$(CXX) $(OBJECTS) $(DRIVER)  $(CXXFLAGS) -o $(Target)
	@echo "Linkin complete!"

docs: project
	@echo "Generating Documentation"
	@doxygen Doxyfile
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Sources $<" 
	@echo "Compiling Files $< to  $@ "
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean clean_txt clean_docs clean_proj
clean: clean_proj clean_txt clean_docs

clean_proj:
	@rm -r $(OBJDIR)
	@rm $(Target)
	@echo "Cleanup Complete!"
clean_txt: $(TEXT)
	@rm -f $(TEXT)

clean_docs: $(DOCS)
	@rm -r $(DOCS)
