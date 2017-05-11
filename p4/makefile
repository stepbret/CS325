MODULES =  
CXX = g++ -g -std=c++11 

all: opt 

engine : $(E_OBJS)
	$(CXX) $(E_OBJS) -o engine $(LFLAGS) 

engine_module.o: $(MODULES)
	ld -r -o engine_module.o $(MODULES)

%.o: %.cxx
	$(CXX) -c $(inputs) -o $(outputs)

clean:
	\rm *.o engine
