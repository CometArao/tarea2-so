CXX = g++
CXXFLAGS = -std=c++11 -Wall -fopenmp
LIBS = `pkg-config --cflags --libs opencv4`

all: secuencial paralelo

secuencial: secuencial.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)

paralelo: paralelo.cpp
	$(CXX) $CXXFLAGS) $< -o $@ $(LIBS)

clean:
	rm -f secuencial paralelo
