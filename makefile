CC = g++
OBJS = 	main.cpp
INCLUDE = -IC:\MinGW_lib\SDL2x86\include
LIBRARY = -LC:\MinGW_lib\SDL2x86\lib
LINKER = -lmingw32 -lSDL2main -lSDL2 -lSDL2_net -lSDL2_ttf
NAME = SpacedReps
all : $(OBJS)
		$(CC) $(OBJS) $(INCLUDE) $(LIBRARY) $(LINKER) -o $(NAME)