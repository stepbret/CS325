CXX=g++
CXXFLAGS=-c -std=c++11 -Wall -pedantic-errors -O3
LDFLAGS=
SOURCES=Prog1-MaxSum.cpp Results.cpp Enum.cpp BetterEnum.cpp divAConq.cpp Linear.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=max_sum

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean: 
	rm -f ${EXECUTABLE} *.o *~

	

