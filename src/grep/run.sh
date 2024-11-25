#!/bin/bash

make s21_grep

GREEN='\e[32m'
NC='\e[0m'
RED='\e[31m'
TESTFILE=tests/test.txt
TESTFILE2=tests/test1.txt
TESTFILE3=Makefile
PAT='aboba'

printf "${GREEN}-----RUNNING TESTS-----${NC}\n"

# TEST 1

grep $PAT $TESTFILE > a
./s21_grep $PAT $TESTFILE > b
result=$(diff a b)

i=1
failed=0

if [ $? -eq 0 ]; then
    printf " TEST # $i ${GREEN}PASSED${NC}\n"
else
    printf " TEST # $i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep $PAT $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 2
grep -v $PAT $TESTFILE > a
./s21_grep -v $PAT $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -v $PAT $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 3
grep -i $PAT $TESTFILE > a
./s21_grep -i $PAT $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -i $PAT $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 4
FLAGS='-c'
grep $FLAGS $PAT $TESTFILE > a
./s21_grep $FLAGS $PAT $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -c $PAT $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 5
FLAGS='-l'
grep $FLAGS $PAT $TESTFILE $TESTFILE $TESTFILE > a
./s21_grep $FLAGS $PAT $TESTFILE $TESTFILE $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -l $PAT $TESTFILE $TESTFILE $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 6
FLAGS='-n'
grep $FLAGS $PAT $TESTFILE > a
./s21_grep $FLAGS $PAT $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -n $PAT  $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))


# TEST 7 
FLAGS='-cl'
grep $FLAGS 123 $TESTFILE > a
./s21_grep $FLAGS 123 $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -cl 123  $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))
#test 8
FLAGS='-ivc'
grep $FLAGS aboba  $TESTFILE > a
./s21_grep $FLAGS aboba  $TESTFILE > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -ivc aboba  $TESTFILE
    printf "$result\n"
    ((failed++))
fi

((i++))

FLAGS='-ic'
grep $FLAGS -e aboba  -e popa $TESTFILE $TESTFILE2 tests/t.txt> a
./s21_grep $FLAGS -e aboba -e popa  $TESTFILE $TESTFILE2 tests/t.txt > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -ic -e aboba -e popa   $TESTFILE $TESTFILE $TESTFILE2 tests/t.txt
    printf "$result\n"
    ((failed++))
fi

((i++))
FLAGS='-cl'
grep $FLAGS  aboba  tests/test.txt tests/t.txt> a
./s21_grep $FLAGS  aboba tests/test.txt tests/t.txt > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -cl  aboba  tests/t.txt tests/t.txt
    printf "$result\n"
    ((failed++))
fi

((i++))
FLAGS='-vn'
grep $FLAGS  -e abob -e pop tests/test.txt tests/t.txt  tests/test1.txt> a
./s21_grep $FLAGS  -e abob -e pop tests/test.txt tests/t.txt tests/test1.txt > b
result=$(diff a b)

if [ $? -eq 0 ]; then
    printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST #$i ${RED}FAILED${NC}\n"
	valgrind --tool=memcheck --leak-check=yes ./s21_grep -vn  -e aboba -e pop  tests/test.txt tests/t.txt tests/test1.txt
    printf "$result\n"
    printf "$result\n"
    ((failed++))
fi

((i++))
printf " ${GREEN}-----DONE[$((i - failed))/$((i))]-----${NC}\n"

rm a b
make clean
