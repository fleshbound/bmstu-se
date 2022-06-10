#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#include "fileio.h"
#include "palindrome.h"
#include "errors.h"

#define MAX_COUNT 100

int check_file(FILE *const f)
{
    if (f == NULL)
    {   
        fprintf(stderr, "Ошибка доступа к файлу\n");

        return ERR_IO;
    }

    assert(f != NULL);

    return EXIT_SUCCESS;
}

int check_argc(const int argc)
{
    if (argc != EXPECTED_ARGC)
    {
        fprintf(stderr, "Неожиданное количество аргументов\n");

        return ERR_ARGC;
    }

    assert(argc == EXPECTED_ARGC);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int err_code = check_argc(argc);

    if (err_code)
        return err_code;

    FILE *f_in = fopen(argv[1], "r");

    err_code = check_file(f_in);

    if (err_code)
        return err_code;

    uint32_t numbers[MAX_COUNT];
    size_t flags[MAX_COUNT];
    size_t length = 0;

    err_code = read_array(f_in, numbers, &length);
    
    if (err_code)
        return err_code;

    fclose(f_in);

    get_palindrome_flags(numbers, length, flags);
    
    err_code = print_palindromes(numbers, length, flags);

    if (err_code)
        return err_code;

    return EXIT_SUCCESS;
}
