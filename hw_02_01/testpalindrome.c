/**
 * \file
 * \brief Файл с модульным тестированием palindrome.c
 */
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "CUnit/Basic.h"
#include "palindrome.h"
#include "errors.h"

#define FILE_STR_LEN 100

static size_t flags[MAX_COUNT] = {0};
static uint32_t numbers[MAX_COUNT] = {0};
static uint32_t real_numbers[MAX_COUNT] = {0};
static size_t length = 0;
static size_t real_flags[MAX_COUNT] = {0};
static FILE *ftmp = NULL;
static FILE *ferr = NULL;

/**
 * \brief Функция для инициализации Suite функции print_palindromes
 */
int init_suite_print_palindromes(void)
{
    if ((ftmp = fopen("out.txt", "w+")) == NULL)
        return ERR_IO;

    if ((ferr = fopen("err.txt", "w+")) == NULL)
        return ERR_IO;

    return EXIT_SUCCESS;
}

/**
 * \brief Функция для очистки Suite функции print_palindromes
 */
int clean_suite_print_palindromes(void)
{
    fclose(ftmp);
    fclose(ferr);

    return EXIT_SUCCESS;
}

/**
 * \brief Функция для инициализации Suite функции is_palindrome
 */
int init_suite_is_palindrome(void)
{
    return EXIT_SUCCESS;
}

/**
 * \brief Функция для очистки Suite функции is_palindrome
 */
int clean_suite_is_palindrome(void)
{
    return EXIT_SUCCESS;
}

/**
 * \brief Функция для инициализации Suite функции get_palindrome_flags
 */
int init_suite_get_flags(void)
{
    return EXIT_SUCCESS;
}

/**
 * \brief Функция для очистки Suite функции get_palindrome_flags
 */
int clean_suite_get_flags(void)
{
    return EXIT_SUCCESS;
}

/**
 * \brief Тестовый случай is_palindrome с проверкой числа 0
 */
void is_palindrome_true_zero(void)
{
    CU_ASSERT_TRUE(is_palindrome(0));
}

/**
 * \brief Тестовый случай is_palindrome с проверкой числа, 
 *      состоящего из одной цифры
 */
void is_palindrome_true_one(void)
{
    CU_ASSERT_TRUE(is_palindrome(1));
}

/**
 * \brief Тестовый случай is_palindrome с проверкой числа-палиндрома, длина
 *      которого нечетна
 */
void is_palindrome_true_odd(void)
{
    CU_ASSERT_TRUE(is_palindrome(121));
}

/**
 * \brief Тестовый случай is_palindrome с проверкой числа-палиндрома, длина
 *      которого четна
 */
void is_palindrome_true_even(void)
{
    CU_ASSERT_TRUE(is_palindrome(1221));
}

/**
 * \brief Тестовый случай is_palindrome с проверкой числа-не_палиндрома, длина
 *      которого нечетна
 */
void is_palindrome_false_odd(void)
{
    CU_ASSERT_FALSE(is_palindrome(123));
}

/**
 * \brief Тестовый случай is_palindrome с проверкой числа-не_палиндрома, длина
 *      которого четна
 */
void is_palindrome_false_even(void)
{
    CU_ASSERT_FALSE(is_palindrome(12));
}

/**
 * \brief Тестовый случай print_palindromes при отсутствии чисел-палиндромов
 */
void print_palindromes_error_noflag(void)
{
    // no true flags
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;

    numbers[0] = 12;
    numbers[1] = 23;
    numbers[2] = 34;

    length = 3;

    CU_ASSERT_EQUAL(ERR_NO_ANSWER, print_palindromes(ftmp, ferr, numbers, length, flags));
}

/**
 * \brief Тестовый случай print_palindromes при наличии чисел-палиндромов
 */
void print_palindromes_success_oneflag(void)
{
    // one true flag
    flags[0] = 0;
    flags[1] = 1;
    flags[2] = 0;

    numbers[0] = 12;
    numbers[1] = 22;
    numbers[2] = 34;

    real_numbers[0] = 22;

    length = 3;

    CU_ASSERT_EQUAL(EXIT_SUCCESS, print_palindromes(ftmp, ferr, numbers, length, flags));

    fflush(ftmp);

    uint32_t ntmp;
    size_t q = 0;

    while (fscanf(ftmp, "%u", &ntmp) > 0)
        CU_ASSERT_EQUAL(ntmp, real_numbers[q++]);
}

/**
 * \brief Тестовый случай get_palindrome_flags при отсутствии палиндромов
 */
void get_flags_allfalse_nopali(void)
{
    // no true flags
    real_flags[0] = 0;
    real_flags[1] = 0;
    real_flags[2] = 0;

    numbers[0] = 12;
    numbers[1] = 23;
    numbers[2] = 34;

    length = 3;

    get_palindrome_flags(numbers, length, flags);

    for (size_t i = 0; i < length; i++)
        CU_ASSERT_EQUAL(flags[i], real_flags[i]);
}

/**
 * \brief Тестовый случай get_palindrome_flags при наличии одного палиндрома
 */
void get_flags_onetrue_onepali(void)
{
    // one true flag
    real_flags[0] = 0;
    real_flags[1] = 1;
    real_flags[2] = 0;

    numbers[0] = 12;
    numbers[1] = 22;
    numbers[2] = 34;

    length = 3;

    get_palindrome_flags(numbers, length, flags);

    for (size_t i = 0; i < length; i++)
        CU_ASSERT_EQUAL(flags[i], real_flags[i]);
}

/**
 * \brief Тестовый случай get_palindrome_flags при наличии всех палиндромов
 */
void get_flags_alltrue_allpali(void)
{
    // all true flags
    real_flags[0] = 1;
    real_flags[1] = 1;
    real_flags[2] = 1;

    numbers[0] = 11;
    numbers[1] = 22;
    numbers[2] = 33;

    length = 3;

    get_palindrome_flags(numbers, length, flags);

    for (size_t i = 0; i < length; i++)
        CU_ASSERT_EQUAL(flags[i], real_flags[i]);
}

int main(void)
{
    CU_pSuite pSuite_is_pali = NULL, pSuite_print_pali = NULL, pSuite_get_flags = NULL;

    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    pSuite_is_pali = CU_add_suite("is_palindrome", 
            init_suite_is_palindrome, clean_suite_is_palindrome);
    pSuite_print_pali = CU_add_suite("print_palindromes", 
            init_suite_print_palindromes, clean_suite_print_palindromes);
    pSuite_get_flags = CU_add_suite("get_palindrome_flags", 
            init_suite_get_flags, clean_suite_get_flags);

    if ((pSuite_is_pali == NULL) || (pSuite_print_pali == NULL) || (pSuite_get_flags == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite_is_pali, "Single digit zero test (true)", is_palindrome_true_zero);
    CU_add_test(pSuite_is_pali, "Single digit one test (true)", is_palindrome_true_one);
    CU_add_test(pSuite_is_pali, "Odd length (true)", is_palindrome_true_odd);
    CU_add_test(pSuite_is_pali, "Even legnth (true)", is_palindrome_true_even);
    CU_add_test(pSuite_is_pali, "Odd length (false)", is_palindrome_false_odd);
    CU_add_test(pSuite_is_pali, "Even length (false)", is_palindrome_false_even);
    
    CU_add_test(pSuite_get_flags, "No palindromes", get_flags_allfalse_nopali);
    CU_add_test(pSuite_get_flags, "One palindrome", get_flags_onetrue_onepali);
    CU_add_test(pSuite_get_flags, "All palindromes", get_flags_alltrue_allpali);
    
    CU_add_test(pSuite_print_pali, "No palindromes (error)", print_palindromes_error_noflag);
    CU_add_test(pSuite_print_pali, "Some palindromes (success)", print_palindromes_success_oneflag);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_error();
}
