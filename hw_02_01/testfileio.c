/**
 * \file
 * \brief Файл с модульным тестированием fileio.c
 */
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "CUnit/Basic.h"
#include "fileio.h"
#include "errors.h"

static FILE *f_in = NULL;
static uint32_t numbers[MAX_COUNT] = {0};
static size_t length = 0;
static size_t real_length = 0;

/**
 * \brief Функция для инициализации Suite функции read_array
 */
int init_suite_read_array(void)
{
    if ((f_in = fopen("in.txt", "w+")) == NULL)
        return ERR_IO;

    return EXIT_SUCCESS;
}

/**
 * \brief Функция для очистки Suite функции read_array
 */
int clean_suite_read_array(void)
{
    fclose(f_in);

    return EXIT_SUCCESS;
}

/**
 * \brief Тестовый случай read_array одно число
 */
void read_array_success_single_number(void)
{
    fseek(f_in, 0, SEEK_SET);

    real_length = 1;

    for (uint32_t i = 0; i < real_length; i++)
        fprintf(f_in, "%u\n", i);
    
    CU_ASSERT_EQUAL(EXIT_SUCCESS, read_array(f_in, numbers, &length));
    CU_ASSERT_EQUAL(length, real_length);

    for (uint32_t i = 0; i < real_length; i++)
        CU_ASSERT_EQUAL(numbers[i], i);
}

/**
 * \brief Тестовый случай read_array несколько чисел
 */
void read_array_success_several_numbers(void)
{
    fseek(f_in, 0, SEEK_SET);

    real_length = 3;

    for (uint32_t i = 0; i < real_length; i++)
        fprintf(f_in, "%u\n", i);

    CU_ASSERT_EQUAL(EXIT_SUCCESS, read_array(f_in, numbers, &length)); 
    CU_ASSERT_EQUAL(length, real_length);
 
    for (uint32_t i = 0; i < real_length; i++)
        CU_ASSERT_EQUAL(numbers[i], i);
}

/**
 * \brief Тестовый случай read_array несколько символов и чисел
 */
void read_array_error_several_chars(void)
{
    fseek(f_in, 0, SEEK_SET);

    real_length = 3;

    for (uint32_t i = 0; i < real_length; i++)
        fprintf(f_in, "a %u\n", i);

    CU_ASSERT_EQUAL(ERR_DATA, read_array(f_in, numbers, &length));
    CU_ASSERT_EQUAL(0, length);
}

/**
 * \brief Тестовый случай read_array кол-во чисел больше max
 */
void read_array_error_several_numbers_max(void)
{
    fseek(f_in, 0, SEEK_SET);

    real_length = MAX_COUNT + 1;

    for (uint32_t i = 0; i < real_length; i++)
        fprintf(f_in, "%u\n", i);

    CU_ASSERT_EQUAL(ERR_DATA, read_array(f_in, numbers, &length))
    CU_ASSERT_EQUAL(0, length);
}

/**
 * \brief Тестовый случай read_array числа + символы больше max
 */
void read_array_error_several_chars_max(void)
{
    fseek(f_in, 0, SEEK_SET);

    real_length = MAX_COUNT * 2;

    for (uint32_t i = 0; i < real_length; i++)
        fprintf(f_in, "%u a\n", i);
    
    CU_ASSERT_EQUAL(ERR_DATA, read_array(f_in, numbers, &length))
    CU_ASSERT_EQUAL(0, length);
}

int main(void)
{
    CU_pSuite pSuite_read_array = NULL;

    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    pSuite_read_array = CU_add_suite("read_array", init_suite_read_array, clean_suite_read_array);

    if (pSuite_read_array == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite_read_array, "Single number", read_array_success_single_number);
    CU_add_test(pSuite_read_array, "Several numbers", read_array_success_several_numbers);
    CU_add_test(pSuite_read_array, "Several numbers and chars", read_array_error_several_chars);
    CU_add_test(pSuite_read_array, "More than max numbers", read_array_error_several_numbers_max);
    CU_add_test(pSuite_read_array, "More than max numbers + chars", read_array_error_several_chars_max);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_error();
}
