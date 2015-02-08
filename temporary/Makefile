CXX = g++-4.9 -fdiagnostics-color=always -O3 -Wall -std=c++11
MAIN_BINARIES = $(basename $(wildcard *Main.cpp))
TEST_BINARIES = $(basename $(wildcard *Test.cpp))
HEADER = $(wildcard *.h)
OBJECTS = $(addsuffix .o, $(basename $(filter-out %Main.cpp %Test.cpp, $(wildcard *.cpp))))
CPPLINT_PATH = ../cpplint.py

BUILDDIR=build

.PRECIOUS: $(BUILDDIR)/%.o

all: compile test

compile: $(addprefix $(BUILDDIR)/,$(MAIN_BINARIES)) $(addprefix $(BUILDDIR)/,$(TEST_BINARIES))

test: $(addprefix $(BUILDDIR)/,$(TEST_BINARIES))
	for T in $(addprefix $(BUILDDIR),$(TEST_BINARIES)); do ./$$T; done

checkstyle:
	python $(CPPLINT_PATH) *.h *.cpp

clean:
	rm -f *.o
	rm -f $(MAIN_BINARIES)
	rm -f $(TEST_BINARIES)
	rm -f *.class
	rm -f *Test.TMP.*
	rm -f core
	rm -rf $(BUILDDIR)

$(BUILDDIR)/%Main: $(BUILDDIR)/%Main.o $(addprefix $(BUILDDIR)/,$(OBJECTS))
	$(CXX) -o $@ $^

$(BUILDDIR)/%Test: $(BUILDDIR)/%Test.o $(addprefix $(BUILDDIR)/,$(OBJECTS))
	$(CXX) -o $@ $^ -lgtest -lgtest_main -lpthread

$(BUILDDIR)/%.o: %.cpp $(HEADER) builddir
	$(CXX) -c $< -o $@

builddir: $(BUILDDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

.PHONY: all compile test builddir
