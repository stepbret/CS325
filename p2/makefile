CC=g++
CFLAGS= -std=c++11 -c -Wall
LDFLAGS=
SOURCES=changeSlow.cpp changeGreedy.cpp hr_time.cpp Prog2-CoinChange.cpp Results.cpp DPchange.cpp
OBJECTS=$(SOURCES:.cpp=.o)
	EXECUTABLE=change

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	    $(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
