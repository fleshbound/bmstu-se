#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "sortw.h"

#define WORD_COUNT 10
#define WORD_LEN 10

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

void sort_words(char words[][WORD_LEN], const size_t count)
{
    assert(count != 0);

    for (size_t i = 0; i < count - 1; i++)
    {
        assert(i < count - 1);

        if (strcmp(words[i], words[i + 1]) > 0)
            swap_words(words[i], words[i + 1]);
    }
}

