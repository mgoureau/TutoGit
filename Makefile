DEBUG=-ggdb

CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -O3 -march=native -pthread $(DEBUG)
CXX_LDFLAGS=-ltbb

all: trapezoidal.exe

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(CXX_LDFLAGS)

