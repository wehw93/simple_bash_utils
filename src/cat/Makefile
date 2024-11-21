CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11
TARGET = s21_cat
FILES = *.c ../common/work_with_file.c
all: $(TARGET)

$(TARGET) : clean $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	rm -rf *.0 $(TARGET)

rebuild:
	cleat s21_cat
format:
	clang-format -i *.c *.h ../common/*.h ../common/*.c

check-format:
	clang-format -n *.c *.h ../common/*.h ../common/*.c

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES) *.c 
