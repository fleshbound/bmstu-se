#!/bin/bash
  
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -o test_fileio.exe fileio.c testfileio.c -lcunit
echo "done"
