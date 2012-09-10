CC = gcc
CFLAGS = 

ifeq ($(shell uname),Darwin)
    LIBS = -framework OpenGL -framework GLUT
else	
	LIBS = -lglut
endif

SOURCES = $(wildcard *.c)
OBJ_DIR = Debug

EXEC = rawvideoplayer 
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

all: createdirs $(EXEC)

createdirs:
	mkdir -p $(OBJ_DIR)

$(EXEC) : $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LIBS) -o $(EXEC)

$(OBJ_DIR)/%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *~ *.o $(EXEC) $(OBJ_DIR)





