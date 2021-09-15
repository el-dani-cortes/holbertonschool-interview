#include <stdlib.h>
#include <stdio.h>

/**
 * count_digits - Function to count number of digits in an integer.
 * @n: Integer
 *
 * Return: Number of digits.
 */
unsigned long count_digits(unsigned long n)
{
	unsigned long i;

	for (i = 0; n > 10; i++)
		n = n / 10;
	return (i + 1);
}

/**
 * right_digit - Function that gets first digit of an integer.
 * @n: Integer
 * @counter: Counter number to get the divisor
 *
 * Return:  Last digit of the integer.
 */
int right_digit(unsigned long n, int counter)
{
	unsigned long divisor = 1, i;

	for (i = 0; i < count_digits(n) - counter; i++)
	{
		divisor *= 10;
	}
	return ((n / divisor) % 10);
}

/**
 * left_digit - Function that gets the last digit
 * @n: Integer
 *
 * Return:  The last digit of an integer
 */
int left_digit(unsigned long n)
{
	return (n % 10);
}

/**
 * is_palindrome - Function that checks if a integer is a palindrome.
 * @n: Integer to evaluate if it's a palindrome
 *
 * Return:  return 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	int number_of_digits, right, left, i;

	number_of_digits = count_digits(n);
	for (i = 0; i < number_of_digits / 2; i++)
	{
		right = right_digit(n, i + 1);
		left = left_digit(n);
		if (right == left)
			n = n / 10;
		else
			return (0);
	}
	return (1);
}
