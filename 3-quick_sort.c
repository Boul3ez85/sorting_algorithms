#include "sort.h"

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int algo_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int j, i;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);
		}
	}
	return (i);
}

void algo_quick_sort(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = algo_partition(array, size, low, high);
		algo_quick_sort(array, size, low,  p - 1);
		algo_quick_sort(array, size, p + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	algo_quick_sort(array, size, 0, size - 1);
}
