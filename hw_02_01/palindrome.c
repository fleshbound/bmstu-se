/**
 * \file
 * \brief Файл с описанием функций для анализа массива целых чисел,
 *          направленного на выявление и вывод палиндромов.
 *
 * Данный файл содержит в себе определения основных функций, пред-
 * назначенных для анализа массива целых чисел с использованием ма-
 * ссива флагов для хранения информации о палиндромах.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <CUnit/CUnit.h>

#include "palindrome.h"
#include "errors.h"

#define TRUE 1
#define FALSE 0
#define MAX_COUNT 100

/**
 * \brief Функция для определения, является ли переданное число палиндромом
 * \param[in] number Анализируемое число
 * \returns Признак (истина или ложь)
 */
int is_palindrome(const uint32_t number)
{
    uint32_t reversed = 0, curr_n = number;

    while (curr_n > 0)
    {
        assert(curr_n > 0);

        uint32_t rem = curr_n % 10;
        reversed = reversed * 10 + rem;
        curr_n /= 10;
    }

    if (number != reversed)
        return FALSE;
    
    assert(number == reversed);

    return TRUE;
}

/**
 * \brief Функция для анализа массива целых чисел для выявления палиндромов
 *
 * Функция проверяет каждый элемент переданного массива чисел на соответствие 
 * форме палиндрома и записывает полученный признак в переданном
 * массиве флагов.
 *
 * \param[in] numbers Массив целых беззнаковых чисел
 * \param[in] length Количество элементов массива
 * \param[out] flags Массив флагов
 */
void get_palindrome_flags(uint32_t *numbers, const size_t length, size_t *flags)
{
    assert(length <= MAX_COUNT);
    assert(length > 0);

    for (size_t i = 0; i < length; i++)
    {
        assert(i < length);

        flags[i] = FALSE;

        if (is_palindrome(numbers[i]))
            flags[i] = TRUE;
    }
}

/** 
 * \brief Функция для вывода в файл палиндромов, содержащихся в массиве
 *
 * Функция выводит в передаваемый поток выхода палиндромы, содержащиеся в массиве,
 * используя для этого информацию из массива флагов. В случае отсутствия
 * палиндромов в массиве функция выводит сообщение об ошибке в передаваемый
 * поток ошибок.
 *
 * \param[in] f Поток выхода
 * \param[in] f_err Поток ошибок
 * \param[in] numbers Массив целых беззнаковых чисел
 * \param[in] length Количество элементов массива
 * \param[in] flags Массив флагов
 * \returns Код возврата (0 - успех, ERR_NO_ANSWER - неудача)
 */
int print_palindromes(FILE *const f, FILE *const f_err, uint32_t *numbers, const size_t length, size_t *const flags)
{
    assert(length <= MAX_COUNT);
    assert(length > 0);

    size_t print_count = 0;

    for (size_t i = 0; i < length; i++)
    {
        assert(i < length);

        if (flags[i] == TRUE)
        {
            int rc = fprintf(f, "%u ", numbers[i]);
            
            assert(rc > 0);
            
            print_count++;
        }
    }

    if (print_count == 0)
    {
        fprintf(f_err, "Палиндромов нет\n");

        return ERR_NO_ANSWER;
    }

    assert(print_count != 0);

    fprintf(f, "\n");

    return EXIT_SUCCESS;
}
