CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=2-OPT.cpp cities.cpp city.cpp tsp.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tsp

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
