# Creado por Davis Cartagena - Lunes, 25 de marzo de 2019 11:59:59
# Makefile para compilar el proyecto Aparked

# Definicion de carpetas
SOURCEDIR		:= source
OBJDIR			:= build/obj
BINDIR			:= build/bin
INCLUDEDIR		:= -Iinclude
TESTDIR 		:= test
TESTBINDIR		:= build/test

# Definicion de archivos
SOURCE			:= $(wildcard $(SOURCEDIR)/*.cpp)
TESTS 			:= $(wildcard $(TESTDIR)/*.cpp)
OBJECTS			:= $(patsubst $(SOURCEDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCE))
TESTOBJ			:= $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(TESTS))
TESTSBIN		:= $(patsubst $(TESTDIR)/%.cpp,$(TESTBINDIR)/%,$(TESTS))

# Definicion de las banderas de compilacion
CXXFLAGS		:= -Wall -Wextra -Werror -g $(INCLUDEDIR)
CXXVERSION		:= -std=c++20

# Definicion del compilador
CXX				:= g++

# Definicion de los objetivos
test	: $(TESTSBIN)
	@echo "Compilacion de pruebas exitosa"

$(TESTSBIN)	: DIRS $(OBJECTS) $(TESTOBJ)
		$(CXX) $(CXXFLAGS) $(CXXVERSION) -o $@ $(OBJECTS) $(TESTOBJ)

$(OBJECTS)	: $(SOURCE)
	$(CXX) $(CXXFLAGS) $(CXXVERSION) -c $^
	mv *.o $(OBJDIR)

$(TESTOBJ) : $(TESTS)
	$(CXX) $(CXXFLAGS) $(CXXVERSION) -c $^
	mv *.o $(OBJDIR)

DIRS	:
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)
	mkdir -p $(TESTBINDIR)
info	:
	@echo "SOURCE: $(SOURCE)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TESTOBJ: $(TESTOBJ)"

clean	:
	rm -f $(BINDIR)/*
	rm -f $(OBJDIR)/*
	rm -f $(TESTBINDIR)/*
	rm -rf build