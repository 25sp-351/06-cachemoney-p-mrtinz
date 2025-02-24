CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET = money_converter
OBJ = money_to_words.o convert_integer_to_words.o cache_manager.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(TARGET) $(OBJ)
