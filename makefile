# thx to https://gl.developpez.com/tutoriel/outil/makefile/

# yes/no
DEBUG = no

ifeq ($(DEBUG),yes)
	MODEFLAGS = -O0
else
	MODEFLAGS = -Ofast
endif

CXX = g++
CXXFLAGS = $(MODEFLAGS) -Wall -std=c++17
LDFLAGS = 
INCLUDES = -I./ -I/usr/include/
LIBS = -L/usr/lib/

EXEC = prime
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

INDEX = index.hpp
TO_INDEX_DIR = problems/
TO_INDEX_HPP = $(wildcard $(TO_INDEX_DIR)/*.hpp)
TO_INDEX = $(TO_INDEX_HPP:.hpp=.index)
TO_INDEX_INT = $(foreach file,$(TO_INDEX_HPP),$(subst $(TO_INDEX_DIR)/pb,,$(subst .hpp,,$(file))))

empty = 
space = $(empty) $(empty)
comma = ,


all: message $(EXEC)
	@echo "Finished successfully!"
	@echo

$(EXEC): $(OBJ)
	@$(CXX) -o $(EXEC) $(OBJ) $(LDFLAGS) $(LIBS)

%.o: %.cpp
	@$(CXX) -o $@ -c $< $(CXXFLAGS)	$(INCLUDES)



.PHONY: messsage clear mrproper install

message:
ifeq ($(DEBUG),yes)
	@echo "Generating in debug mode..."
else
	@echo "Generating in release mode..."
endif

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

install: $(EXEC)
	cp $(EXEC) /usr/bin/
