CC = gcc
CFLAGS = -Iinclude -Wall
OBJ = build/main.o build/election.o build/voter.o build/candidate.o build/utils.o
TARGET = build/election_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f build/*.o $(TARGET)
