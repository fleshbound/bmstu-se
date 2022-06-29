/**
 * \file
 * \brief Заголовочный файл с описанием функций для работы
 *     с палиндромами
 */

#ifndef __PALINDROME_H__

#define __PALINDROME_H__

void get_palindrome_flags(uint32_t *numbers, const size_t length, size_t *flags);

int print_palindromes(FILE *const f, FILE *const f_err, uint32_t *numbers, const size_t length, size_t *const flags);

int is_palindrome(const uint32_t number);

#endif
