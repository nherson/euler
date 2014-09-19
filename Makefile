#OBJS=main.o matmul.o omp_matmul_for.o omp_matmul_task.o pthread_matmul.o
PROBLEMS=problem1 problem2 problem3 problem4
CC=gcc-4.9
FLAGS=-pthread -fopenmp -O2
# Dirs
SRC=src
LIB=lib
BIN=bin
OBJ=obj


##all: $(OBJS)
##	$(CC) $(FLAGS) $(OBJ) -o matmul
##
##%.o: $(SRC)/%.c
##	$(CC) $(FLAGS) -c $< 
##
##clean:
##	rm -rf $(OBJ)/*
##
##rebuild: clean all
##
##problem%: $(OBJ)/problem%.o
##	$(CC) $(FLAGS) $< -o $(BIN)/problem%

all: $(PROBLEMS)

clean:
	rm -rf $(OBJ)/*

problem%: $(OBJ)/problem%.o
	$(CC) $(FLAGS) $< -o $(BIN)/$@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) -c $< -o $@
