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

format:
	clang-format -i *.c *.h ../common/*.h ../common/*.c

check-format:
	clang-format -n *.c *.h ../common/*.h ../common/*.c

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES) *.c *.h ../common/*.c
