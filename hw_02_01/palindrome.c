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

void test_is_palindrome(void)
{
    CU_ASSERT_TRUE(is_palindrome(0));
    CU_ASSERT_TRUE(is_palindrome(1));
    CU_ASSERT_TRUE(is_palindrome(121));
    CU_ASSERT_TRUE(is_palindrome(111));
    CU_ASSERT_TRUE(is_palindrome(1221));
    
    CU_ASSERT_FALSE(is_palindrome(123));
    CU_ASSERT_FALSE(is_palindrome(12));
}

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

void test_get_palindrome_flags(void)
{
    size_t flags[MAX_COUNT] = {0};
    size_t real_flags[MAX_COUNT] = {0};
    uint32_t numbers[MAX_COUNT] = {0};
    size_t length = 0;
    
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

int print_palindromes(uint32_t *numbers, const size_t length, size_t *flags)
{
    assert(length <= MAX_COUNT);
    assert(length > 0);
    
    size_t print_count = 0;

    for (size_t i = 0; i < length; i++)
    {
        assert(i < length);

        if (flags[i] == TRUE)
        {
            int rc = fprintf(stdout, "%u ", numbers[i]);
            
            assert(rc > 0);
            
            print_count++;
        }
    }

    if (print_count == 0)
    {
        fprintf(stderr, "Палиндромов нет\n");

        return ERR_NO_ANSWER;
    }

    assert(print_count != 0);

    fprintf(stdout, "\n");

    return EXIT_SUCCESS;
}

void test_print_palindromes(void)
{

}
