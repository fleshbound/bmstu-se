#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <CUnit/CUnit.h>

#define TRUE 1
#define FALSE 0

#define WORD_LEN 10
#define WORD_COUNT 10

/**
 * \brief Функция для обмена слов
 */

void swap_words(char *const word1, char *const word2)
{
    for (size_t i = 0; i < WORD_COUNT; i++)
    {
        char tmp = word1[i];
        word1[i] = word2[i];
        word2[i] = tmp;
    }
}

/**
 * \brief Функция для сортировки массива слов в алфавитном порядке
 */

void sort_words(char *words[], const size_t count)
{
    for (size_t i = 0; i < count - 1; i++)
    {
        assert(i < count - 1);

        if (strcmp(words[i], words[i + 1]) > 0)
            swap_words(words[i], words[i + 1]);
    }
}

/**
 * \brief Функция создания кейса тестирования подпрограммы sort_words
 */

int init_suite(void)
{
    char *words[WORD_COUNT];

    return EXIT_SUCCESS;
}

/**
 * \brief Функция очистки кейса тестирования функции sort_words
 */

int clean_suite(void)
{
    for (size_t i = 0; i < WORD_COUNT; i++)
        memset(words[i], '\0', WORD_LEN)

    return EXIT_SUCCESS;
}

/**
 * \brief Тестовый случай 1 для функции сортировки массива слов
 *
 * Проверка сортировки массива из одинаковых слов
 */

void test_sort_words(void)

int main(void)
{
    
    
    return EXIT_SUCCESS;
}
