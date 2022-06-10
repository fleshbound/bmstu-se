#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "fileio.h"
#include "errors.h"

#define READ_COUNT 1
#define MAX_COUNT 100

int read_array(FILE *const f, uint32_t *numbers, size_t *const length)
{
    assert(f != NULL);

    size_t curr_len = 0;
    uint32_t num;

    while (fscanf(f, "%u", &num) == READ_COUNT)
    {
        curr_len++;

        if (curr_len > MAX_COUNT)
        {
            fprintf(stderr, "Отсутствуют числа\n");

            return ERR_DATA;
        }

        assert(curr_len <= MAX_COUNT);

        numbers[curr_len - 1] = num;
    }

    assert(curr_len <= MAX_COUNT);

    *length = curr_len;

    if (*length == 0)
    {
        fprintf(stderr, "Отсутствуют числа\n");

        return ERR_DATA;
    }

    assert(*length != 0);

    return EXIT_SUCCESS;
}
