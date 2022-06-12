#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -o app.exe main.c palindrome.c fileio.c
echo "done"
