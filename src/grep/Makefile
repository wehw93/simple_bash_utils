CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
TARGET = s21_grep
FILES = *.c 

all: $(TARGET)

$(TARGET): clean $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	rm -rf *.0 s21_grep

rebuild:
	clean s21_grep

format:
	clang-format -i *.c *.h 

check-format:
	clang-format -n *.c *.h 

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES) *.c *.h 
valgrind: all
	valgrind --tool=memcheck --leak-check=yes ./s21_grep  -iv  a  test.txt War.txt
