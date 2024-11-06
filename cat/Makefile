CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11
TARGET = s21_cat
FILES = *.c ../common/work_with_file.c
all: $(TARGET)

$(TARGET) : $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	rm -rf *.0 $(TARGET)

rebuild:
	cleat s21_cat
