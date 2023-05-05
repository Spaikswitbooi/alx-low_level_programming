#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given index.
 * @index: is the index, starting from 0 of the bit you want to get
 * @n: is the number to search
 * Return: the value of the bit at index index or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div, res;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << index;
	res = n & div;
	if (res == div)
		return (1);

	return (0);
}
