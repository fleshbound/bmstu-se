#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "sortw.h"

#define TRUE 1
#define FALSE 0

#define WORD_LEN 10
#define WORD_COUNT 10

/**
 * \brief Функция создания кейса тестирования подпрограммы sort_words
 */

int init_suite(void)
{
    char *words[WORD_LEN];
    char *expected_words[WORD_LEN];
    size_t length = 0;

    memset(expected_words, '\0', WORD_LEN * WORD_COUNT);
    memset(words, '\0', WORD_LEN * WORD_COUNT);

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
 * Проверка сортировки массива из слов в обратном порядке
 */

void test1_sort_words(void)
{
    length = 3;

    words[0][0] = 'c';
    words[0][1] = '\0';

    words[1][0] = 'b';
    words[1][1] = '\0';

    words[2][0] = 'a';
    words[2][1] = '\0';

    expected_words[0][0] = 'a';
    expected_words[0][1] = '\0';

    expected_words[1][0] = 'b';
    expected_words[1][1] = '\0';

    expected_words[2][0] = 'c';
    expected_words[2][1] = '\0';

    sort_words(words, length);

    for (size_t i = 0; i < length; i++)
        CU_ASSERT_TRUE(expected_words[i], words[i]);
}

/** 
 * \brief Тестовый случай 2 для функции сортировки массива слов
 *  
 * Проверка сортировки массива из отсортированных слов
 */

void test2_sort_words(void)
{
    length = 3;

    words[0][0] = 'a';
    words[0][1] = '\0';
        
    words[1][0] = 'b';
    words[1][1] = '\0';

    words[2][0] = 'c';
    words[2][1] = '\0';

    expected_words[0][0] = 'a';
    expected_words[0][1] = '\0';

    expected_words[1][0] = 'b';
    expected_words[1][1] = '\0';

    expected_words[2][0] = 'c';
    expected_words[2][1] = '\0';
    
    sort_words(words, length);

    for (size_t i = 0; i < length; i++)
        CU_ASSERT_TRUE(expected_words[i], words[i]);
}

/**
 * \brief Тестовый случай 3 для функции сортировки массива слов
 *
 * Проверка сортировки массива из слов в произвольном порядке (два одинаковых)
 */

void test3_sort_words(void)
{
    length = 4;

    words[0][0] = 'с';
    words[0][1] = '\0';

    words[1][0] = 'a';
    words[1][1] = '\0';

    words[2][0] = 'b';
    words[2][1] = '\0';

    words[3][0] = 'a';
    words[3][1] = '\0';

    expected_words[0][0] = 'a';
    expected_words[0][1] = '\0';

    expected_words[1][0] = 'a';
    expected_words[1][1] = '\0';

    expected_words[2][0] = 'b';
    expected_words[2][1] = '\0';

    expected_words[3][0] = 'c';
    expected_words[3][1] = '\0';

    sort_words(words, length);

    for (size_t i = 0; i < length; i++)
        CU_ASSERT_TRUE(expected_words[i], words[i]);
}

int main(void)
{
    CU_pSuite pSuite = NULL;

    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);

    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((CU_add_test(pSuite, "sort_words слова в обратном порядке", test1_sort_words) == NULL)
        || (CU_add_test(pSuite, "sort_words слова в правильном порядке", test2_sort_words) == NULL)
        || (CU_add_test(pSuite, "sort_words слова в произвольном порядке (два одинаковых)", test2_sort_words) == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
