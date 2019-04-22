CXXFLAGS = -g -Wall -Wfatal-errors -std=c++14

.PHONY: all
all: release test

.PHONY: release
release:
	$(CXX) $(CXXFLAGS) -o runMain main.cpp

.PHONY: tests
test:
	$(CXX) $(CXXFLAGS) -o runTests ./tests/tests.cpp