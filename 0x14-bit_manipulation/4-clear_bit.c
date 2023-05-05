#include "main.h"

/**
 * clear_bit -  function that sets the value of a bit to 0 at a given index.
 * @n: pointer to the number to change
 * @index: index is the index, starting from 0 of the bit you want to set
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}
*n &= ~(1UL << index);
return (1);
}
