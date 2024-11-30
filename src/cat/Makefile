CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11
TARGET = s21_cat
FILES = *.c 
all: $(TARGET)

$(TARGET) : clean $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	rm -rf *.0 $(TARGET)

rebuild:
	cleat s21_cat
format:
	clang-format -i *.c *.h 

check-format:
	clang-format -n *.c *.h 

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES) *.c 
valgrind: all
	valgrind --tool=memcheck --leak-check=yes  ./s21_cat  -t  tests/test1.txt tests/empty.txt

