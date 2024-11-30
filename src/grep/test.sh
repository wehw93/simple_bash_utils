#!/bin/bash

# Убедитесь, что файлы существуют
if [[ ! -f "War.txt" || ! -f "tests/test.txt" ]]; then
    echo "Один или оба файла не найдены. Пожалуйста, убедитесь, что War.txt и tests/test.txt существуют."
    exit 1
fi

# Определяем комбинации флагов и шаблонов
flags=("i" "v" "n" "l" "c")
patterns=("ab" "hello" "aboba" "popa" "ba")

# Счетчики для совпадений и несовпадений
matches=0
mismatches=0

# Генерация всех комбинаций шаблонов
for (( i=0; i<${#patterns[@]}; i++ )); do
    for (( j=i; j<${#patterns[@]}; j++ )); do
        # Формируем шаблоны с флагом -e
        if [[ $i -eq $j ]]; then
            pattern="-e ${patterns[i]}"
        else
            pattern="-e ${patterns[i]} -e ${patterns[j]}"
        fi

        # Проверка всех флагов
        for flag in "${flags[@]}"; do
            echo "Тестирование с флагом -$flag и шаблоном '$pattern' на War.txt"
            ./s21_grep -$flag $pattern War.txt > s21_output.txt
            grep -$flag $pattern War.txt > grep_output.txt
            if diff -u s21_output.txt grep_output.txt > /dev/null; then
                echo "Вывод совпадает"
                ((matches++))
            else
                echo "Вывод не совпадает"
                ((mismatches++))
            fi

            echo "Тестирование с флагом -$flag и шаблоном '$pattern' на tests/test.txt"
            ./s21_grep -$flag $pattern tests/test.txt > s21_output.txt
            grep -$flag $pattern tests/test.txt > grep_output.txt
            if diff -u s21_output.txt grep_output.txt > /dev/null; then
                echo "Вывод совпадает"
                ((matches++))
            else
                echo "Вывод не совпадает"
                ((mismatches++))
            fi

            echo "Тестирование с флагом -$flag и шаблоном '$pattern' на обоих файлах"
            ./s21_grep -$flag $pattern War.txt tests/test.txt > s21_output.txt
            grep -$flag $pattern War.txt tests/test.txt > grep_output.txt
            if diff -u s21_output.txt grep_output.txt > /dev/null; then
                echo "Вывод совпадает"
                ((matches++))
            else
                echo "Вывод не совпадает"
                ((mismatches++))
            fi
        done
    done
done

# Удаляем временные файлы
rm s21_output.txt grep_output.txt

# Выводим результаты
echo "Количество совпадений: $matches"
echo "Количество несовпадений: $mismatches"

