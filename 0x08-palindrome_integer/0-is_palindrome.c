#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - Function that checks if a integer is a palindrome.
 * @n: Integer to evaluate if it's a palindrome
 *
 * Return:  return 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long int n)
{
	int number_of_digits, i;
	char buffer[20];

	number_of_digits = sprintf(buffer, "%lu", n);
	for (i = 0; i < number_of_digits / 2; i++)
	{
		if (buffer[i] != buffer[number_of_digits - i - 1])
			return (0);
	}
	return (1);
}
