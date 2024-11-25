#!/bin/bash

GREEN='\e[32m'
NC='\e[0m'
RED='\e[31m'
TESTFILE=tests/test.txt
TESTFILE2=tests/test1.txt
TESTFILE3=Makefile

# Массив флагов
FLAGS=("-v" "-i" "-c" "-l" "-n" "-cl" "-ivc")

# Массив паттернов для поиска
PATTERNS=("aboba" "123" "test" "hello" "world")

printf "${GREEN}-----RUNNING TESTS-----${NC}\n"

# Счетчик тестов
i=1
failed=0

# Внешний цикл по паттернам
for PAT in "${PATTERNS[@]}"; do
    # Внутренний цикл по флагам
    for FLAG in "${FLAGS[@]}"; do
        # Выполнение стандартного grep
        grep $FLAG $PAT $TESTFILE > a
        ./s21_grep $FLAG $PAT $TESTFILE > b
        result=$(diff a b)

        if [ $? -eq 0 ]; then
            printf " TEST #$i ${GREEN}PASSED${NC}\n"
        else
            printf " TEST #$i ${RED}FAILED${NC}\n"
            valgrind --tool=memcheck --leak-check=yes ./s21_grep $FLAG $PAT $TESTFILE
            printf "$result\n"
            ((failed++))
        fi

        ((i++))
    done
done

printf " ${GREEN}-----DONE[$((i - failed))/$((i))]-----${NC}\n"

rm a b
make clean

