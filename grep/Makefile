CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TARGET = s21_grep
FILES = *.c ../common/work_with_file.c

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	rm -rf *.0 s21_grep

rebuild:
	clean s21_grep
