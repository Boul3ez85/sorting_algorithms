#include "sort.h"

/**
 * counting_sort - sort array of integers
 * @array: pointer to first integer of array
 * @size: size of the array
 *
 * Return: Void
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int *c;
	int max;


	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	c = malloc(sizeof(int) * (max + 1));
	for (i = 0; (int)i < max + 1; i++)
	{
		c[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		c[array[i]] += 1;
	}
	for (i = 1; (int)i < max + 1; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	print_array(c, max + 1);
	for (i = 0; (int)i < max; i++)
	{
		array[c[i]] = i + 1;
	}
	free(c);
}
