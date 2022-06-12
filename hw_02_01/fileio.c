/**
 * \file
 * \brief Файл с описанием функций для работы с входным файлом целых чисел
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "fileio.h"
#include "errors.h"

#define READ_COUNT 1
#define MAX_COUNT 100

/**
 * \brief Функция для считывания массива целых чисел из текстового файла
 * \param[in] f Файловая переменная (текстовый файл)
 * \param[out] numbers Массив целых беззнаковых чисел
 * \param[out] length Количество элементов массива
 * \returns Код возврата (0 - успех, ERR_DATA - ошибка)
 */
int read_array(FILE *const f, uint32_t *numbers, size_t *const length)
{
    assert(f != NULL);
    
    fseek(f, 0, SEEK_SET);

    size_t curr_len = 0;
    uint32_t num;

    while (fscanf(f, "%u", &num) == READ_COUNT)
    {
        curr_len++;

        if (curr_len > MAX_COUNT)
        {
            fprintf(stderr, "Отсутствуют числа\n");
            *length = 0;

            return ERR_DATA;
        }

        assert(curr_len <= MAX_COUNT);

        numbers[curr_len - 1] = num;
    }

    assert(curr_len <= MAX_COUNT);

    *length = curr_len;

    if ((*length == 0) || (!feof(f)))
    {
        if (!feof(f))
            *length = 0;

        fprintf(stderr, "Отсутствуют числа\n");

        return ERR_DATA;
    }

    assert(*length != 0);

    return EXIT_SUCCESS;
}
