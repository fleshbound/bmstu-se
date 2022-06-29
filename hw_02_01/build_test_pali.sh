#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -o test_pali.exe palindrome.c paliutest.c -lcunit
echo "done"
