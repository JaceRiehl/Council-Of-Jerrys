CXX = g++
INCLUDES= -Iinclude/
CXXFLAGS = -std=c++11 -g $(INCLUDES)  --coverage
SRC= src
TESTS=test
OBJ = $(SRC:.cpp=.o)
LINKFLAGS= -lcppunit

PROGRAM_TEST = tests

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = coverage.results
COVERAGE_REPORT_DIR = coverage
LCOV_FLAGS = --gcov-tool=$(GCOV) --no-external -b $(SRC)

all: clean coverage

$(PROGRAM_TEST): $(TESTS) $(SRC) main.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(TESTS)/*.cpp $(SRC)/*.cpp main.cpp $(LINKFLAGS)
	./$(PROGRAM_TEST)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objs bin $(PROGRAM_TEST) $(COVERAGE_RESULTS)
	rm -f ./*.gc*

coverage: $(PROGRAM_TEST)
	mv *.gc* $(SRC)
	$(LCOV) -c -i -d $(SRC) -o $(SRC)/$(PROGRAM_TEST)_base.info $(LCOV_FLAGS)
	./$(PROGRAM_TEST)
	mv *.gc* $(SRC)
	$(LCOV) --c --d src -o $(SRC)/$(COVERAGE_RESULTS) $(LCOV_FLAGS)
	$(LCOV) -a $(SRC)/$(PROGRAM_TEST)_base.info -a $(SRC)/$(COVERAGE_RESULTS) -o $(SRC)/$(COVERAGE_RESULTS) $(LCOV_FLAGS)
	genhtml $(SRC)/$(COVERAGE_RESULTS) --output-directory $(COVERAGE_REPORT_DIR)
	rm -f $(SRC)/*.gc* $(SRC)/$(COVERAGE_RESULTS) $(SRC)/$(PROGRAM_TEST)_base.info
	firefox $(COVERAGE_REPORT_DIR)/index.html&

mem: valgrind ./JerrysAdventure
