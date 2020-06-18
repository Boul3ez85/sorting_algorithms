#include "sort.h"

/**
 * swap - swaping two integer
 * @a: integer
 * @b: integer
 *
 * Return: Void
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorting an array of integers
 * @array: array of integers
 * @size: size of the array
 *
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	int i, j, gap;

	if (!array || size < 2)
		return;
	gap = 1;
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = 0 ; i < (int)size; i++)
		{
			for (j = i; j < (int)size; j += gap)
			{
				if (array[i] > array[j])
					swap(&array[i], &array[j]);
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
	for (i = 0; i < (int)size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			swap(&array[i], &array[i + 1]);
			for (j = i; j >= 0; j--)
			{
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
			}
		}
	}
}
