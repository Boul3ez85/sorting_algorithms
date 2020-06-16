#include "sort.h"

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int algo_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot;
	size_t j, i;

	pivot = array[high];
	for (i = j = low; j < high; j++)
	{
		if (array[i] < pivot)
		{
			swap(&array[j], &array[i++]);
			print_array(array, size);
			i++;
		}
	}	
	swap(&array[i], &pivot);
	print_array(array, size);
	
	return (i);
}

void algo_quick_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t p;

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
