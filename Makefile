MAKEFLAGS+=--no-builtin-rules --no-builtin-variables

CXXFLAGS=-O3 -DNDEBUG -Wall -MMD -Wno-unused-function -fopenmp
CXXFLAGS+=-Iinclude -ItestMains -Iinclude/maths -Iinclude/rasterizer -Iinclude/rasterizer/render -Iinclude/glad -fopenmp
CFLAGS=$(CXXFLAGS)
CC=gcc
CXX=g++

LDLIBS=-Llib -lglfw -lSDL2 -lSDL2main -lGL -lGLU -ldl -lSDL2_image -fopenmp
SRC=$(wildcard src/*.cpp) $(wildcard src/maths/*.cpp) $(wildcard src/rasterizer/*.cpp) $(wildcard src/rasterizer/render/*.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRC)) src/glad.o
DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: exe

-include $(DEPS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

exe: $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^ $(LDLIBS)

clean:
	rm -f $(DEPS) $(OBJS) gmon.out exe

threading:
	make -j