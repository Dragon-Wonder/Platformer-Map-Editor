CC=g++
CFLAGS= -std=c++11 -Os -s
LNFLAGS= -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
source=$(wildcard source/*.cpp)
HEAD=$(wildcard source/*.h)
OBJ=$(source:.cpp=.o)
EXE=MapMaker

all: $(OBJ) $(HEAD)
	@echo "link $(EXE)"
	@$(CC) $(OBJ) $(CFLAGS) $(LNFLAGS) -o$(EXE)

source/main.o: source/main.cpp source/version.h source/main.h source/button.h
source/button.o: source/button.cpp source/button.h source/main.h 

clean:
	rm -f source/*.o
	rm -f $(EXE)

.cpp.o:
	@echo "   cc $<"
	@${CC} -c ${CFLAGS} $< -o $@
